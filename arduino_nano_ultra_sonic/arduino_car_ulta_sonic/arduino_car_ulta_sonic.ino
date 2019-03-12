/*
 SUDI
 */
//https://create.arduino.cc/projecthub/Bill_Mougios/arduino-controlled-car-with-hc-sr04-a8e57d
//L293 Connection
const int motorA1 = 3;
const int motorA2 = 4;
const int motorAspeed = 5;
const int motorB1 = 7;
const int motorB2 = 8;
const int motorBspeed = 6;
const int lights = 12;
const int buzzer = 13;
const int echoPin = 9;
const int trigPin = 10;

//Useful Variables
int vSpeed = 200;        // Default speed, from 0 to 255
int maximumRange = 70;   // Maximum range needed
int minimumRange = 0;    // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup()
{
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
void go_fwd()
{
  digitalWrite(motorA1, LOW);
  delay(1);
  digitalWrite(motorA2, HIGH);
  delay(1);

  digitalWrite(motorB1, LOW);
  delay(1);
  digitalWrite(motorB2, HIGH);

  analogWrite(motorAspeed, vSpeed);
  analogWrite(motorBspeed, vSpeed);
}

void go_rvrs()
{
  digitalWrite(motorA1, HIGH);
  delay(1);
  digitalWrite(motorA2, LOW);
  delay(1);

  digitalWrite(motorB1, HIGH);
  delay(1);
  digitalWrite(motorB2, LOW);

  analogWrite(motorAspeed, vSpeed);
  analogWrite(motorBspeed, vSpeed);
}

void go_fwd_left()
{
  digitalWrite(motorA1, LOW);
  delay(1);
  digitalWrite(motorA2, HIGH);
  delay(1);

  digitalWrite(motorB1, LOW);
  delay(1);
  digitalWrite(motorB2, HIGH);

  analogWrite(motorAspeed, vSpeed);
  analogWrite(motorBspeed, 0);
}

void go_fwd_right()
{
  digitalWrite(motorA1, LOW);
  delay(1);
  digitalWrite(motorA2, HIGH);
  delay(1);

  digitalWrite(motorB1, LOW);
  delay(1);
  digitalWrite(motorB2, HIGH);

  analogWrite(motorAspeed, 0);
  analogWrite(motorBspeed, vSpeed);
}

void go_rvrs_left()
{
  digitalWrite(motorA1, HIGH);
  delay(1);
  digitalWrite(motorA2, LOW);
  delay(1);

  digitalWrite(motorB1, HIGH);
  delay(1);
  digitalWrite(motorB2, LOW);

  analogWrite(motorAspeed, 0);
  analogWrite(motorBspeed, vSpeed);
}
void go_rvrs_right()
{
  digitalWrite(motorA1, HIGH);
  delay(1);
  digitalWrite(motorA2, LOW);
  delay(1);

  digitalWrite(motorB1, HIGH);
  delay(1);
  digitalWrite(motorB2, LOW);

  analogWrite(motorAspeed, vSpeed);
  analogWrite(motorBspeed, 0);
}
void go_left()
{
  digitalWrite(motorA2, HIGH);
  delay(1);
  digitalWrite(motorA1, LOW);
  delay(1);

  digitalWrite(motorB2, LOW);
  delay(1);
  digitalWrite(motorB1, HIGH);

  analogWrite(motorAspeed, vSpeed);
  analogWrite(motorBspeed, vSpeed);
}

void go_right()
{
  digitalWrite(motorA2, LOW);
  delay(1);
  digitalWrite(motorA1, HIGH);
  delay(1);

  digitalWrite(motorB2, HIGH);
  delay(1);
  digitalWrite(motorB1, LOW);

  analogWrite(motorAspeed, vSpeed);
  analogWrite(motorBspeed, vSpeed);
}

void car_stop()
{
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
}

void loop()
{
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
  distance = duration / 58.2;

  if (distance > maximumRange || distance < minimumRange)
  {
    /* Send a positive number to computer and Turn MOTORS ON 
 to indicate "out of range" */
    Serial.println("1");
    go_fwd();
  }
  else
  {
    go_rvrs();
    delay(250);
    go_fwd_right();
    delay(300);
  }
  //Delay 50ms before next reading.
  delay(50);
}
