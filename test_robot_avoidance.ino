#include<AFMotor.h>

AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

const int trigPin=2;
const int echoPin=13;
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
}


void loop() {
/*distance measuring code*/
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);

duration=pulseIn(echoPin,HIGH);
distance=(duration*0.034)/2;
/*distance measuring code "end"*/

/*Motor control*/
if(distance<20)
{
  Serial.println("distance less than 20 cm");
  motor3.setSpeed(0);
  motor3.run(RELEASE);

  motor4.setSpeed(0);
  motor4.run(RELEASE);

  delay(500);

  motor3.setSpeed(200);
  motor3.run(BACKWARD);

  motor4.setSpeed(200);
  motor4.run(BACKWARD);
  delay(1500);
 
  motor3.setSpeed(100);
  motor3.run(FORWARD);

  motor4.setSpeed(100);
  motor4.run(BACKWARD);
  delay(2000);

}
Serial.println("distance greater than 20 cm");
motor3.setSpeed(200);
motor3.run(FORWARD);

motor4.setSpeed(200);
motor4.run(FORWARD);
/*Motor control end*/
}

