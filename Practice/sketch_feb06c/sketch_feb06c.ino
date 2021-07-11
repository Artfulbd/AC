const int pinWhite = 14, pinRed = 33, pinGreen = 35, pinBuz = 47, pot = A0;
int pusi;
void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode( pinWhite,OUTPUT );
    pinMode( pinRed,OUTPUT );
    pinMode( pinGreen,OUTPUT );
    pinMode( pinBuz,OUTPUT );
    pinMode( pot,INPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
  pusi = analogRead(pot);
  delay(200);
  Serial.println(pusi);
  if (pusi<=300)
    {
      digitalWrite(pinWhite,HIGH);
      digitalWrite(pinRed ,LOW );
      digitalWrite( pinGreen,LOW );
      digitalWrite( pinBuz,LOW );
    }
    else if(pusi >= 300 && pusi <= 600)
    {
       digitalWrite(pinWhite,LOW);
      digitalWrite(pinRed ,HIGH );
      digitalWrite( pinGreen,LOW );
      digitalWrite( pinBuz,LOW );
    }
    else if(pusi >= 600 && pusi <= 900)
    {
       digitalWrite(pinWhite,LOW);
      digitalWrite(pinRed ,LOW );
      digitalWrite( pinGreen,HIGH );
      digitalWrite( pinBuz,LOW );
    }
    else
    {
     digitalWrite(pinWhite,LOW);
      digitalWrite(pinRed ,LOW );
      digitalWrite( pinGreen,LOW );
      digitalWrite( pinBuz,HIGH );
    }
  
  

}
