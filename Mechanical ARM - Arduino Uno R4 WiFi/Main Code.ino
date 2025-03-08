//IN ARDUINO CLOUD - ONLINE IDE

#include "thingProperties.h"
#include <Servo.h>

#include <Servo.h> //servo library

Servo s1; //initializing servos
Servo s2;
Servo s3;
Servo s4;
int val1;
int val2;
int val3;
int val4;


void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(12,INPUT_PULLUP); //reads input for switching modes
  s1.attach(6);
  s2.attach(5);
  s3.attach(3);
  s4.attach(10);
  pinMode(13,OUTPUT);
  // put your setup code here, to run once:
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  if (digitalRead(12)==1){
    ArduinoCloud.update(); //enables communication between dashboard switches and arduino
    Serial.println("IoT Mode");
  }
  if (digitalRead(12)==0){
    Serial.println("Pot Mode");
  val1=analogRead(A0); //reads the output value from potentiometer
  val2=analogRead(A1);
  val3=analogRead(A2);
  val4=analogRead(A3);
  
  val1= map(val1, 0, 1023, 150, 90); //maps the output of potentiometer and input values of servo motors
  val2=map(val2, 0, 1023, 90, 180);
  val3=map(val3, 0, 1023, 0, 180);
  val4=map(val4, 0, 1023, 90, 180);
  s1.write(val1); //controls the position of servos in degrees
  s2.write(val2);
  s3.write(val3);
  s4.write(val4);
  }
  
}


/*
  Since Front is READ_WRITE variable, onFrontChange() is
  executed every time a new value is received from IoT Cloud.
  These functions are used to define the operations using eachvariables and these variables 
  are linked to the switches/buttons in the  dashboard.
*/
void onFrontChange()  {
  // Add your code here to act upon Front change
  s1.write(front);
  delay(150);
}

/*
  Since Lift is READ_WRITE variable, onLiftChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLiftChange()  {
  // Add your code here to act upon Lift change
  s2.write(lift);
}

/*
  Since CatcH is READ_WRITE variable, onCatcHChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onCatcHChange()  {
  // Add your code here to act upon CatcH change
  if (catcH == true){
    s4.write(180);
  }
  else{
    s4.write(90);
  }
  
}

/*
  Since Turn is READ_WRITE variable, onTurnChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTurnChange()  {
  s3.write(turn);
  
}

