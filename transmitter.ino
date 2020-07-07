
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3);
char mychar;
const int buttonf = 7;
const int buttonb = 8;
const int buttonl = 10;
const int buttonr = 11;
int buttonstate;
const int buttonPinF = 7;
const int buttonPinB = 8;
const int buttonPinL = 10;
const int buttonPinR = 11;


void setup() {
  BTSerial.begin(9600);
  Serial.begin(9600);
  pinMode(buttonPinF, INPUT);
  pinMode(buttonPinB, INPUT);
  pinMode(buttonPinL, INPUT);
  pinMode(buttonPinR, INPUT);

}


void loop() {
  Serial.print("Entering loop");

  buttonstate = digitalRead(buttonf);
  
  if (buttonstate == LOW) {
    Serial.print("button not pressed"); 
    mychar = 'f';
    BTSerial.write(mychar);
  }
  else if (buttonstate == HIGH) {
   Serial.print("button is pressed");
   mychar = 's';
   BTSerial.write(mychar);

  }

  buttonstate = digitalRead(buttonb);
    if (buttonstate == LOW) {
    Serial.print("button not pressed"); 
    mychar = 'f';
    BTSerial.write(mychar);
  }
  else if (buttonstate == HIGH) {
   Serial.print("button is pressed");
   mychar = 'b';
   BTSerial.write(mychar);

  }

  buttonstate = digitalRead(buttonl);
    if (buttonstate == LOW) {
    Serial.print("button not pressed"); 
    mychar = 'f';
    BTSerial.write(mychar);
  }
  else if (buttonstate == HIGH) {
   Serial.print("LEFT button is pressed");
   mychar = 'l';
   BTSerial.write(mychar);

  }

  buttonstate = digitalRead(buttonr);
    if (buttonstate == LOW) {
    Serial.print("button not pressed"); 
    mychar = 'f';
    BTSerial.write(mychar);
  }
  else if (buttonstate == HIGH) {
   Serial.print("RIGHT button is pressed");
   mychar = 'r';
   BTSerial.write(mychar);

  }
}
