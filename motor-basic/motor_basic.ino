int state = 0;
void setup()
{
pinMode(9,OUTPUT);
pinMode(2,INPUT);
}

void loop()
{
state = digitalRead(2);

if(state == HIGH){
  digitalWrite(9,HIGH);
  
}else{
digitalWrite(9,LOW);
}
}
