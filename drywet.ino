//Code by Vighnesh
//https://github.com/vighneshns2008

#include <ADCTouch.h>         //analog touch switch library
#include <Servo.h>            //servo motor arduino library
Servo myservo;                //create myservo object in class servo
int ref0, ref1;               //
int sensorValue = 0;          //intialize variables
int pos = 0;                  //
const int analogInPin = A0;   //

void setup() {
  Serial.begin(9600);             //begin serial communication
  myservo.attach(9);              //set myservo pin to nine
  ref1 = ADCTouch.read(A1, 500);  //initialise analog touch sensor
}

void loop() {
  myservo.write(50);                        //set servo to fifty degrees
  if (ADCTouch.read(A1) > 750)              //button pressed
  {
    Serial.println("Button pressed");       //serial print
    delay(1000);                            //wait a second
    sensorValue = analogRead(analogInPin);  //get moisture content
    if (sensorValue > 1000)                 //if it is dry waste
    {
      todrywaste():                         //throw in drywaste
      delay(1000);                          //wait a second
    }
      else {
      towetwaste();                         //throw in wetwaste
      delay(1000);                          //wait a second
    }
  }
}
void todrywaste() {                         //throw in drywaste
  for (pos = 50; pos <= 0; pos += 1) {
    myservo.write(pos);
    delay(5);
  }
  myservo.write(100);
}
    
void towetwaste() {                         //throw in wetwaste   
  for (pos = 50; pos >= 1; pos -= 1) {
    myservo.write(pos);
    delay(5);
  }
  myservo.write(-10);
}
