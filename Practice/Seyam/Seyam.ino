const int  pinWhite = 14, pinRed = 33, pinGreen = 35, pinBuz = 47, pot = A1;
int pusi, last  = 0;
void setup() {
   // put your setup code here, to run once:
    Serial.begin(1200);
    pinMode ( pinWhite,OUTPUT );
    pinMode ( pinRed,OUTPUT );
    pinMode ( pinGreen,OUTPUT );
    pinMode ( pinBuz,OUTPUT );
    pinMode ( pot,INPUT );
}

void loop() { 
  // put your main code here, to run repeatedly:
  pusi = analogRead(pot);
  delay(400);
  if(pusi<last) last = pusi;
  Serial.println(pusi );
  if (pusi<45)
    {
      Serial.println("You are in the room");
    }
    else 
    {
      Serial.println("You are outside");
    }    
}
