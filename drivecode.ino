
#include <SoftwareSerial.h>

int EnA = 10;
int EnB = 5;
int In1 = 9;
int In2 = 8;
int In3 = 7;
int In4 = 6;

SoftwareSerial BTSerial(2, 3);
char my;
char state;

void setup() {
  BTSerial.begin(9600);
  Serial.begin(9600);

  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);

}
void loop() {
if(BTSerial.available()) {
Serial.print("in loop!"); 
state = BTSerial.read();
switch(state) {
  case 's':
    Serial.write("Going straight");
      // turn on motor A
    digitalWrite(In1, HIGH); 
    digitalWrite(In2, LOW);
  // set speed to 150 out 255
    analogWrite(EnA, 200);
  // turn on motor B
    digitalWrite(In3, HIGH);
    digitalWrite(In4, LOW);
  // set speed to 150 out 255
    analogWrite(EnB, 200);
      break;
  case 'f':
    analogWrite(EnB, 0);
    analogWrite(EnA, 0);
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);  
    digitalWrite(In3, LOW);
    digitalWrite(In4, LOW);
      break;
  case 'b':
    Serial.write("Going backwards");
      // turn on motor A
    digitalWrite(In1, LOW); 
    digitalWrite(In2, HIGH);
  // set speed to 150 out 255
    analogWrite(EnA, 200);
  // turn on motor B
    digitalWrite(In3, LOW);
    digitalWrite(In4, HIGH);
  // set speed to 150 out 255
    analogWrite(EnB, 200);
      break;

        case 'r':
    Serial.write("Going right");
      // turn on motor A
    digitalWrite(In1, HIGH); 
    digitalWrite(In2, LOW);
  // set speed to 150 out 255
    analogWrite(EnA, 200);
  // turn on motor B
    digitalWrite(In3, LOW);
    digitalWrite(In4, LOW);
  // set speed to 150 out 255
    analogWrite(EnB, 200);
      break;
    default:
    break;

      case 'l':
    Serial.write("Going left");
      // turn on motor A
    digitalWrite(In1, LOW); 
    digitalWrite(In2, LOW);
  // set speed to 150 out 255
    analogWrite(EnA, 255);
  // turn on motor B
    digitalWrite(In3, HIGH);
    digitalWrite(In4, LOW);
  // set speed to 150 out 255
    analogWrite(EnB, 255);
      break;

}
Serial.write(BTSerial.read());
  
}
}
