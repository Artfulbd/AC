#define HC06 Serial3
int led = 13;

void setup()
{
  delay(1000);
  Serial.begin(9600);
  Serial3.begin(9600);
  pinMode(led, OUTPUT);
  
  Serial.write("\nTest Start\n");
}

void loop()
{
  if(Serial3.available())
  {
    char data = Serial3.read();
    //Serial.write(data);
    Serial3.write(data);
    switch(data)
      {
        case 'F': digitalWrite(led, HIGH);break; 
        case 'B': digitalWrite(led, LOW);break;
        default : break;
      }
      Serial.println(data);
  }
  //else Serial.println("Serious trouble");
  //delay(50);
}
