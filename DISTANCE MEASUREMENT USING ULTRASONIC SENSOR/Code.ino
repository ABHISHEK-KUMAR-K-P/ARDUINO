#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  lcd.begin(16, 2); // Set up the number of columns and rows on the LCD.
  
}



void loop()
{
  int val = 0.01723 * readUltrasonicDistance(9, 9);
  if (val==336){
    lcd.print("NOTHING DETECTED");
    
  }
  else{
    lcd.print(val);
    lcd.print(" cm far away");
    
  }
  delay(1000);
  lcd.clear();
}


