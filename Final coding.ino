//
// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header
//
// This sketch is a good place to start if you're just getting started with
// Pixy and Arduino.  This program simply prints the detected object blocks
// (including color codes) through the serial console.  It uses the Arduino's
// ICSP port.  For more information go here:
//
// http://cmucam.org/projects/cmucam5/wiki/Hooking_up_Pixy_to_a_Microcontroller_(like_an_Arduino)
//
// It prints the detected blocks once per second because printing all of the
// blocks for all 50 frames per second would overwhelm the Arduino's serial port.
//

#include <SPI.h>
#include <Pixy.h>

// This is the main Pixy object
Pixy pixy;

int objectX;
int screenWidth = 320;

int inPin = 7;   // choose the input pin (for a pushbutton)
int val = 0;     // variable for reading the pin status

const int leftForward = 4;
const int leftBackward = 2;
const int rightForward = 5;
const int rightBackward = 3;

void setup()
{
  Serial.begin(9600);
  Serial.print("Starting...\n");

  pixy.init();

  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(inPin, INPUT);    // declare pushbutton as input

}

void loop()
{
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32];

  // grab blocks!
  blocks = pixy.getBlocks();

  // If there are detect blocks, print them!
  if (blocks >= 1)
  {


    i++;

    // do this (print) every 50 frames because printing every
    // frame would bog down the Arduino
    if (i % 50 == 0)
    {
      sprintf(buf, "Detected %d:\n", blocks);
      Serial.print(buf);

      for (j = 0; j < blocks; j++)
      {
        sprintf(buf, "  block %d: ", j);
        Serial.print(buf);
        Serial.print("J=");
        Serial.println(j);
        pixy.blocks[j].print();
        objectX = pixy.blocks[j].x;

        //determine direction, divide the camera in to three parts
        // Object appear in the right part turn right, left part turn left
        // Object appear in the middle part go straight.
        if (objectX >   ((screenWidth / 3) * 2)) {
          turnRight();
        } else if (objectX <  ( screenWidth / 3)) {
          turnLeft();
        }
        else if (objectX > ( screenWidth / 3) && (objectX < ((screenWidth / 3) * 2))) {
          forward();
        }

        Serial.println(pixy.blocks[j].signature);

      }
    }
  }
}

//turn right
void turnRight() {
  digitalWrite(leftBackward, LOW);
  digitalWrite(leftForward, LOW);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightBackward, LOW);
  delay(1);
  Serial.println("right");
}
// turn left
void turnLeft() {
  digitalWrite(leftBackward, LOW);
  digitalWrite(leftForward, HIGH);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, LOW);
  delay(1);
  Serial.println("left");
}
// go straight!
void forward() {
  digitalWrite(leftBackward, LOW);
  digitalWrite(leftForward, HIGH);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightBackward, LOW);
  delay(1);
  Serial.println("forward");
}
