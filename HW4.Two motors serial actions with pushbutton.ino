onst int leftForward = 4;
const int leftBackward = 2;
const int rightForward = 5;
const int rightBackward = 3;
int inPin = 7;   // choose the input pin (for a pushbutton)
int val = 0;     // variable for reading the pin status

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
pinMode(inPin, INPUT);    // declare pushbutton as input

}

void loop() {
  val = digitalRead(inPin);  // read input value
  if (val == HIGH) {         // check if the input is HIGH (button released)
  
  }
  // left wheal and right wheal both go backward
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(3, LOW);
  delay(1000);
//left wheal and right wheal both go forward
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(3, HIGH);
  delay(1000);

//left wheal go forward and right wheal both go backward
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(3, HIGH);
  delay(1000);
}
