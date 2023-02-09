/** 
*move randomly any where and keep on listening 
*to the echo of the ultrasonic sensor
*if a obstacle is detected move to the left first and check 
*for any obstacle if no then move forward else  there is any
*obstacle then move right(the movement is restricted to right)
*the distance is 10cm for the obstacle detetcion.
 */
#include<AFMotor.h>

AF_DCMotor motor3(3);
AF_DCMotor motor4(4);


const int trigPin=2;
const int echoPin=13;
long duration;
int distance;

int obstacle()
{
  //clear the trigPin
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  //set the trigPin on HIGH for 10 microseconds
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  //read the duration after which echo pin is HIGH
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  Serial.println(distance);
  return distance;
}
 
void setup() {
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 Serial.begin(9600); 
}
boolean st;
int dist=0;
void loop() 
{
   st=true;
    dist=obstacle();
    if (dist<20)
    { 
      if(st==true)
      {
         motor3.setSpeed(0);
         motor3.run(RELEASE);

         motor4.setSpeed(0);
         motor4.run(RELEASE);
         delay(1000);
      }
      st=false;
      motor3.setSpeed(100);
      motor3.run(FORWARD);

      motor4.setSpeed(100);
      motor4.run(BACKWARD);
      delay(1000);
       
    }
  motor3.setSpeed(100);
  motor3.run(FORWARD);

  motor4.setSpeed(100);
  motor4.run(FORWARD);
}
