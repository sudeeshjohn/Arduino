/*
 SUDI
 */
 //https://create.arduino.cc/projecthub/Bill_Mougios/arduino-controlled-car-with-hc-sr04-a8e57d
//L293 Connection   
  const int motorA1      = 3;  
  const int motorA2      = 4; 
  const int motorAspeed  = 5;
  const int motorB1      = 7; 
  const int motorB2      = 8; 
  const int motorBspeed  = 6; 
  const int lights       = 12;
  const int buzzer       = 13;
  const int echoPin      = 9;
  const int trigPin      = 10;
  

//Useful Variables
  int state;
  int i=0;
  int j=0;
  int vSpeed=200;     // Default speed, from 0 to 255
  int maximumRange = 55; // Maximum range needed
  int minimumRange = 0; // Minimum range needed
  long duration, distance; // Duration used to calculate distance


void setup() {
    // Set pins as outputs:
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);
    pinMode(lights, OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
   
    // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
    
}

void go_rvrs()
{
  digitalWrite (motorA1,HIGH);
  delay(1);
  digitalWrite(motorA2,LOW);                       
  delay(1);
  
  digitalWrite (motorB1,HIGH);
  delay(1);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
    }

void go_right()
{
  digitalWrite (motorA1,LOW);
  delay(1);
  digitalWrite(motorA2,HIGH);                       
  delay(1);
  
  digitalWrite (motorB1,LOW);
  delay(1);
  digitalWrite(motorB2,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, 0);
    }
 
void loop() {
  
    if(Serial.available() > 0){     
      state = Serial.read();   
    }
   Serial.println(state); 
  //Change speed if state is equal from 0 to 4. Values must be from 0 to 255 (PWM)
    if (state == '0'){
      vSpeed=0;}
    else if (state == '1'){
      vSpeed=100;}
    else if (state == '2'){
      vSpeed=180;}
    else if (state == '3'){
      vSpeed=200;}
    else if (state == '4'){
      vSpeed=255;}
     
  /***********************Forward****************************/
  //If state is equal with letter 'F', car will go forward!
    if (state == 'F') {
  digitalWrite (motorA1,LOW);
  delay(1);
  digitalWrite(motorA2,HIGH);                       
  delay(1);
  
  digitalWrite (motorB1,LOW);
  delay(1);
  digitalWrite(motorB2,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
  }
  /**********************Forward Left************************/
  //If state is equal with letter 'G', car will go forward left
    else if (state == 'I') {
  digitalWrite (motorA1,LOW);
  delay(1);
  digitalWrite(motorA2,HIGH);                       
  delay(1);
  
  digitalWrite (motorB1,LOW);
  delay(1);
  digitalWrite(motorB2,HIGH);

  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, vSpeed);
    }
  /**********************Forward Right************************/
  //If state is equal with letter 'I', car will go forward right
    else if (state == 'G') {
  digitalWrite (motorA1,LOW);
  delay(1);
  digitalWrite(motorA2,HIGH);                       
  delay(1);
  
  digitalWrite (motorB1,LOW);
  delay(1);
  digitalWrite(motorB2,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, 0);
    }
  /***********************Backward****************************/
  //If state is equal with letter 'B', car will go backward
    else if (state == 'B') {
  digitalWrite (motorA1,HIGH);
  delay(1);
  digitalWrite(motorA2,LOW);                       
  delay(1);
  
  digitalWrite (motorB1,HIGH);
  delay(1);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
    }
  /**********************Backward Left************************/
  //If state is equal with letter 'J', car will go backward left
    else if (state == 'J') {
  digitalWrite (motorA1,HIGH);
  delay(1);
  digitalWrite(motorA2,LOW);                       
  delay(1);
  
  digitalWrite (motorB1,HIGH);
  delay(1);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, vSpeed);
    }
  /**********************Backward Right************************/
  //If state is equal with letter 'H', car will go backward right
    else if (state == 'H') {
  digitalWrite (motorA1,HIGH);
  delay(1);
  digitalWrite(motorA2,LOW);                       
  delay(1);
  
  digitalWrite (motorB1,HIGH);
  delay(1);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, 0);
    }
  /***************************Left*****************************/
  //If state is equal with letter 'L', wheels will turn left
    else if (state == 'L') {
  digitalWrite (motorA2,HIGH);
  delay(1);
  digitalWrite(motorA1,LOW);                       
  delay(1);
  
  digitalWrite (motorB2,LOW);
  delay(1);
  digitalWrite(motorB1,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
    }
  /***************************Right*****************************/
  //If state is equal with letter 'R', wheels will turn right
    else if (state == 'R') {
  digitalWrite (motorA2,LOW);
  delay(1);
  digitalWrite(motorA1,HIGH);                       
  delay(1);
  
  digitalWrite (motorB2,HIGH);
  delay(1);
  digitalWrite(motorB1,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);    
    }

     /************************Stop*****************************/
  //If state is equal with letter 'S', stop the car
    else if (state == 'S'){
        analogWrite(motorA1, 0);  analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
    }
 /************************Lights*****************************/
 //If state is equal with letter 'W', turn leds on or of off
    else if (state == 'W') {
      if (i == 0) {  
         digitalWrite(lights, HIGH); 
         i=1;
      }
      else if (i==1){
         digitalWrite(lights, LOW); 
         i=0;
      }
      state='n';
    }
  /**********************Horn sound***************************/
  //If state is equal with letter 'V', play (or stop) horn sound
    else if (state == 'V') {
      if (j == 0) {  
         digitalWrite(buzzer, HIGH);
         j=1;
      }
      else if (j==1){
         digitalWrite(buzzer, LOW);
         j=0;
      }
      state='n';  
    }

    /* 
The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. 
*/ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 

if (distance < maximumRange ){
 /* Send a positive number to computer and Turn MOTORS ON 
 to indicate "out of range" */
 //Serial.println("1");
  go_rvrs();
  delay(50);
  go_right();
 delay(50);
 
 }
    
}
