int pin = A0, red = 8, green = 11, white = 5;
float constantVol = 255./1023.;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin,INPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(white,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  float value = analogRead(pin);
  delay(200);
  Serial.println(value);
  if(value > 600){
    digitalWrite(red,51);
    digitalWrite(green,0);
  }
  else if(value>200 && value<601){
    digitalWrite(green,51);
    digitalWrite(red,0);
  }
  else{
    digitalWrite(green,0);
    digitalWrite(red,0);
  }
  value *= constantVol;
  digitalWrite(white,value);
  Serial.println(value);
  Serial.println();
  

}
