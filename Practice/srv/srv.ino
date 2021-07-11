#include<Servo.h>
Servo srv;
int srvPin = 5;
void setup() {
  // put your setup code here, to run once:
  srv.attach(srvPin);
  srv.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i<180; i++)
  {
     srv.write(i);
     delay(10);
  }
  for(int i = 180; i>0; i--)
  {
     srv.write(i);
     delay(10);
  }

}
