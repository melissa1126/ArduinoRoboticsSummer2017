const int leftForward = 4;
const int leftBackward = 2;
const int rightForward = 5;
const int rightBackward = 3;
const int pushButton = 7;
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);


}

void loop() {
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);
  delay(1);
  if (buttonState == HIGH) {

    goBack();

    //    //go forward
    //    digitalWrite(leftBackward, LOW);
    //    digitalWrite(leftForward, HIGH);
    //    digitalWrite(rightForward, HIGH);
    //    digitalWrite(rightBackward, LOW);
    //    delay(1000);
    //    //turn righ
    //    digitalWrite(leftBackward, LOW);
    //    digitalWrite(leftForward, HIGH);
    //    digitalWrite(rightForward, LOW);
    //    digitalWrite(rightBackward, HIGH);
    //    delay(1000);


    //    digitalWrite(leftBackward, HIGH);
    //    digitalWrite(leftForward, LOW);
    //    digitalWrite(rightForward, LOW);
    //    digitalWrite(rightBackward, HIGH);
    //    delay(1000);

  } else {
    pause();

    //  digitalWrite (2, LOW);
    // digitalWrite (4, LOW);
    // digitalWrite (8, LOW);
    // digitalWrite (10, LOW);
    // delay(1000);
  }

}
void goBack() { //enter function
  //go forward
  digitalWrite(leftBackward, LOW);
  digitalWrite(leftForward, HIGH);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightBackward, LOW);
  delay(1000);
  //turn right
  digitalWrite(leftBackward, LOW);
  digitalWrite(leftForward, HIGH);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, HIGH);
  delay(1000);
  digitalWrite(leftBackward, HIGH);
  digitalWrite(leftForward, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, HIGH);
  delay(1000);
}
void pause() {
  digitalWrite (2, LOW);
  digitalWrite (4, LOW);
  digitalWrite (8, LOW);
  digitalWrite (10, LOW);
  delay(1000);
} //return

