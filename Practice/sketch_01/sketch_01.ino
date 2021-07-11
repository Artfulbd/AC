const int pin1 = 9, pin2  = 2, pin3 = 7, holdTime = 200;
int count = 0, i, total = 0, till; 
void setup() {
  Serial.begin(9400);
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
}
void print(int i,String s){
  Serial.print("#");
  Serial.print(i);
  Serial.print(". We are printing "+s);
  Serial.println(total);
}
void loop() {
  if(count == 6){
    digitalWrite(pin3,HIGH);
    delay(holdTime+1000);
    count = 0;
    digitalWrite(pin3,LOW);
  }
  count++; 
  Serial.print("How many times do you want to blink?");
  while(!Serial.available()){}
  till = Serial.parseInt();
  Serial.println();
  for(i = 0; i<till; i++){
    print(i,"green ");
    digitalWrite(pin1,51);
    delay(holdTime);
    digitalWrite(pin1,0);
    delay(holdTime);
  }
  for(i = 0; i<till; i++){
    print(i,"white ");
    digitalWrite(pin2,HIGH);
   delay(holdTime);
   digitalWrite(pin2,LOW);
   delay(holdTime);
  }
  //if(holdTime  == 500) holdTime = 1000;
  //else holdTime = 500;
  total++;
}
