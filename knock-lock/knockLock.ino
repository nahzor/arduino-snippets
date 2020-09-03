//knock_lock

#include<Servo.h>
Servo myServo;

const int piezo = A0;
const int switchPin = 2;

const int yellowLed = 3;
const int redLed = 5;
const int greenLed = 4;

int knockVal;
int switchVal;
int i = 0;
const int quietKnock = 10;
const int loudKnock = 100;

boolean locked = false;
int numberOfKnocks = 0;

void setup()
{
  myServo.attach(9);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
  
  digitalWrite(greenLed, HIGH);
  myServo.write(0);
  Serial.println("Setup:The box is unlocked!");
}

void loop()
{

    knockVal = analogRead(piezo);
    if(knockVal >0){
      if(checkForKnock(knockVal)==true)
      {
       i++;
      if(i%2==0){
      myServo.write(0);
            delay(20);
      digitalWrite(greenLed,HIGH);
      digitalWrite(redLed, LOW);
      }
      else
      {
            myServo.write(110);
                  delay(20);
      digitalWrite(greenLed,LOW);
      digitalWrite(redLed, HIGH);
      }
    }
    }
  
}//loop

boolean checkForKnock(int value){
  
  if(value > quietKnock && value<loudKnock){
    digitalWrite(yellowLed,HIGH);
    delay(50);
    digitalWrite(yellowLed, HIGH);
    Serial.print("Valid : ");
    Serial.println(value);
    return true;
  }
  else
  {
  Serial.print("Invalid  : ");
  Serial.println(value);
return false;
  }
 
}
