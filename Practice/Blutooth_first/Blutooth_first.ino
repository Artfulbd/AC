#include<Servo.h>
Servo srv;
const int srvPin = 5; 
int  flag = 0, pos = 0;
char state = '0';
 
void setup() {
   Serial.begin(9600);
   srv.attach(srvPin);
   srv.write(0);
   delay(20);
  }
 
void loop() {

  Serial.println(Serial.available());
    if(Serial.available()> 0)
    {
     state = Serial.read();
     Serial.println(state);
     
     if(state == 'F'){
          if(pos < 171){
            srv.write(pos-=9);
          }
     }
     else if(state == 'B'){
          if(pos > 10){
            srv.write(pos-=9);
          }
     }
    Serial.println("Out of Base");
    }
    else
    {
      Serial.println("Serious trouble");
    }
    delay(50);
}
