const int blueLEDPin = 11;
const int redLEDPin = 10;
const int greenLEDPin = 9;

const int greenSensorPin = A1;
const int redSensorPin = A0;
const int blueSensorPin = A2;

int redValue = 0;
int blueValue = 0;
int greenValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup()
{
Serial.begin(9600);

pinMode(greenLEDPin,OUTPUT);
pinMode(blueLEDPin,OUTPUT);
pinMode(redLEDPin,OUTPUT);
}

void loop()
{
redSensorValue = analogRead(redSensorPin);
delay(5);
greenSensorValue = analogRead(greenSensorPin);
delay(5);
blueSensorValue = analogRead(blueSensorPin);

Serial.print("\nRaw Sensor RGB : ");
Serial.print(redSensorValue);
Serial.print(greenSensorValue);
Serial.print(blueSensorValue);

redValue = redSensorValue/4;
greenValue = greenSensorValue/4;
blueValue = blueSensorValue/4;

Serial.print("\nMapped RGB : ");
Serial.print(redValue);
Serial.print(greenValue);
Serial.print(blueValue);

analogWrite(redLEDPin,redValue);
analogWrite(greenLEDPin,greenValue);
analogWrite(blueLEDPin,blueValue);

}
