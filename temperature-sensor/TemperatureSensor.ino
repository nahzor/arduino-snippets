const int sensorPin = A0;
const int baseT = 20.0;

void setup()
{
Serial.begin(9600);

for(int i = 3;i<6;i++)
{
pinMode(i, OUTPUT);
digitalWrite(i,LOW);
}
}

void loop()
{
int sensorVal = analogRead(sensorPin);
Serial.print("\n\nSensorVal :" );
Serial.print(sensorVal);

float voltage = (sensorVal/1024.0)*5.0;

Serial.print("\nVoltage :" );
Serial.print(voltage);

Serial.print("\nDeg. C :" );

float temp = (voltage - 0.5) * 100;

Serial.print(temp);

if(temp < baseT)
{
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(5,LOW);
}
else if(temp>= baseT+2 && temp < baseT+4)
{
digitalWrite(3,HIGH);
digitalWrite(4,LOW);
digitalWrite(5,LOW);
}
else if(temp>= baseT+4 && temp < baseT+6)
{
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
}
else if(temp>= baseT+6)
{
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
}
delay(1);
}
