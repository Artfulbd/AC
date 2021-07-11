#define HC06 Serial3

#define ENA_m1 6        // Enable/speed motor Front Right 
#define ENB_m1 7        // Enable/speed motor Back Right
#define ENA_m2 4       // Enable/speed motor Front Left
#define ENB_m2 5       // Enable/speed motor Back Left

#define IN_11  30        // L298N #1 in 1 motor Front Right
#define IN_12  32        // L298N #1 in 2 motor Front Right
#define IN_13  34        // L298N #1 in 3 motor Back Right
#define IN_14  36        // L298N #1 in 4 motor Back Right

#define IN_21  22        // L298N #2 in 1 motor Front Left
#define IN_22  24        // L298N #2 in 2 motor Front Left
#define IN_23  26       // L298N #2 in 3 motor Back Left
#define IN_24  28       // L298N #2 in 4 motor Back Left

//char data;           
int speedCar = 100, led = 13;     
int speed_Coeff = 4;
boolean lightFront = false;
boolean lightBack = false;
boolean horn = false;

void setup() {  

    delay(1000);
    Serial.begin(9600);
    Serial3.begin(9600);
    pinMode(led, OUTPUT);
       
    pinMode(ENA_m1, OUTPUT);
    pinMode(ENB_m1, OUTPUT);
    pinMode(ENA_m2, OUTPUT);
    pinMode(ENB_m2, OUTPUT);
  
    pinMode(IN_11, OUTPUT);
    pinMode(IN_12, OUTPUT);
    pinMode(IN_13, OUTPUT);
    pinMode(IN_14, OUTPUT);
    
    pinMode(IN_21, OUTPUT);
    pinMode(IN_22, OUTPUT);
    pinMode(IN_23, OUTPUT);
    pinMode(IN_24, OUTPUT);

      Serial.write("\nTest Start\n");

  } 

void loop(){
       
      if(Serial3.available())
      {
        char data = Serial3.read();
        //Serial.write(data);
        Serial3.write(data);  
        stopRobot();      //Initialize with motors stopped.
        switch (data) 
        {
             case 'F':goAhead();break;
             case 'B':goBack();break;
             case 'L':goLeft();break;
             case 'R':goRight();break;
             case 'I':goAheadRight();break;
             case 'G':goAheadLeft();break;
             case 'J':goBackRight();break;
             case 'H':goBackLeft();break;
             case '0':speedCar = 100;break;
             case '1':speedCar = 115;break;
             case '2':speedCar = 130;break;
             case '3':speedCar = 145;break;
             case '4':speedCar = 160;break;
             case '5':speedCar = 175;break;
             case '6':speedCar = 190;break;
             case '7':speedCar = 205;break;
             case '8':speedCar = 220;break;
             case '9':speedCar = 235;break;
             case 'q':speedCar = 255;break;
             case 'W':lightFront = true;break;
             case 'w':lightFront = false;break;
             case 'U':lightBack = true;break;
             case 'u':lightBack = false;break;
             case 'V':horn = true;break;
             case 'v':horn = false;break;
             case 'a': digitalWrite(led, HIGH);break; 
             case 'd': digitalWrite(led, LOW);break;
             default : break;

        }///end of switch
        Serial.println(data);  
      }///end of if
      

 } ///end of loop
 
 void goAhead(){ 

      digitalWrite(IN_11, HIGH);
      digitalWrite(IN_12, LOW);
      analogWrite(ENA_m1, speedCar);

      digitalWrite(IN_13, LOW);
      digitalWrite(IN_14, HIGH);
      analogWrite(ENB_m1, speedCar);


      digitalWrite(IN_21, LOW);
      digitalWrite(IN_22, HIGH);
      analogWrite(ENA_m2, speedCar);


      digitalWrite(IN_23, HIGH);
      digitalWrite(IN_24, LOW);
      analogWrite(ENB_m2, speedCar);

  }

void goBack(){ 

      digitalWrite(IN_11, LOW);
      digitalWrite(IN_12, HIGH);
      analogWrite(ENA_m1, speedCar);


      digitalWrite(IN_13, HIGH);
      digitalWrite(IN_14, LOW);
      analogWrite(ENB_m1, speedCar);


      digitalWrite(IN_21, HIGH);
      digitalWrite(IN_22, LOW);
      analogWrite(ENA_m2, speedCar);


      digitalWrite(IN_23, LOW);
      digitalWrite(IN_24, HIGH);
      analogWrite(ENB_m2, speedCar);

  }

void goRight(){ 

      digitalWrite(IN_11, LOW);
      digitalWrite(IN_12, HIGH);
      analogWrite(ENA_m1, speedCar);


      digitalWrite(IN_13, HIGH);
      digitalWrite(IN_14, LOW);
      analogWrite(ENB_m1, speedCar);


      digitalWrite(IN_21, LOW);
      digitalWrite(IN_22, HIGH);
      analogWrite(ENA_m2, speedCar);


      digitalWrite(IN_23, HIGH);
      digitalWrite(IN_24, LOW);
      analogWrite(ENB_m2, speedCar);


  }

void goLeft(){

      digitalWrite(IN_11, HIGH);
      digitalWrite(IN_12, LOW);
      analogWrite(ENA_m1, speedCar);


      digitalWrite(IN_13, LOW);
      digitalWrite(IN_14, HIGH);
      analogWrite(ENB_m1, speedCar);

        
      digitalWrite(IN_21, HIGH);
      digitalWrite(IN_22, LOW);
      analogWrite(ENA_m2, speedCar);


      digitalWrite(IN_23, LOW);
      digitalWrite(IN_24, HIGH);
      analogWrite(ENB_m2, speedCar);

        
  }

void goAheadRight(){
      
      digitalWrite(IN_11, HIGH);
      digitalWrite(IN_12, LOW);
      analogWrite(ENA_m1, speedCar/speed_Coeff);

      digitalWrite(IN_13, LOW);
      digitalWrite(IN_14, HIGH);
      analogWrite(ENB_m1, speedCar/speed_Coeff);


      digitalWrite(IN_21, LOW);
      digitalWrite(IN_22, HIGH);
      analogWrite(ENA_m2, speedCar);


      digitalWrite(IN_23, HIGH);
      digitalWrite(IN_24, LOW);
      analogWrite(ENB_m2, speedCar);
 
  }

void goAheadLeft(){
      
      digitalWrite(IN_11, HIGH);
      digitalWrite(IN_12, LOW);
      analogWrite(ENA_m1, speedCar);

      digitalWrite(IN_13, LOW);
      digitalWrite(IN_14, HIGH);
      analogWrite(ENB_m1, speedCar);


      digitalWrite(IN_21, LOW);
      digitalWrite(IN_22, HIGH);
      analogWrite(ENA_m2, speedCar/speed_Coeff);


      digitalWrite(IN_23, HIGH);
      digitalWrite(IN_24, LOW);
      analogWrite(ENB_m2, speedCar/speed_Coeff);
 
  }

void goBackRight(){ 

      digitalWrite(IN_11, LOW);
      digitalWrite(IN_12, HIGH);
      analogWrite(ENA_m1, speedCar/speed_Coeff);


      digitalWrite(IN_13, HIGH);
      digitalWrite(IN_14, LOW);
      analogWrite(ENB_m1, speedCar/speed_Coeff);


      digitalWrite(IN_21, HIGH);
      digitalWrite(IN_22, LOW);
      analogWrite(ENA_m2, speedCar);


      digitalWrite(IN_23, LOW);
      digitalWrite(IN_24, HIGH);
      analogWrite(ENB_m2, speedCar);

  }

void goBackLeft(){ 

      digitalWrite(IN_11, LOW);
      digitalWrite(IN_12, HIGH);
      analogWrite(ENA_m1, speedCar);


      digitalWrite(IN_13, HIGH);
      digitalWrite(IN_14, LOW);
      analogWrite(ENB_m1, speedCar);


      digitalWrite(IN_21, HIGH);
      digitalWrite(IN_22, LOW);
      analogWrite(ENA_m2, speedCar/speed_Coeff);


      digitalWrite(IN_23, LOW);
      digitalWrite(IN_24, HIGH);
      analogWrite(ENB_m2, speedCar/speed_Coeff);

  }

void stopRobot(){  

      digitalWrite(IN_11, LOW);
      digitalWrite(IN_12, LOW);
      analogWrite(ENA_m1, speedCar);


      digitalWrite(IN_13, LOW);
      digitalWrite(IN_14, LOW);
      analogWrite(ENB_m1, speedCar);

  
      digitalWrite(IN_21, LOW);
      digitalWrite(IN_22, LOW);
      analogWrite(ENA_m2, speedCar);

      
      digitalWrite(IN_23, LOW);
      digitalWrite(IN_24, LOW);
      analogWrite(ENB_m2, speedCar);
  
  }
