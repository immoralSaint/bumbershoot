#include<AFMotor.h> //library for the motor driver handling
#include<Servo.h> //library for servo motor

Servo s1;
//initialize motor pins
//here only two
//here we are writing code for activating the motor 3 and 4 on the arduino motor shield

AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

char command;//the command character received via bluetooth module is stored in the variable command

void setup() {
 //start to read the data transfered via bluetooth module(HC-05 module)
 Serial.begin(9600); //set the baud rate to your bluetooth module
 s1.attach(9);
 s1.write(0); 
}

int angle;
void loop() {
  if(Serial.available()>0)//if there is some data comming form the bluetooth module
  {
    angle=0;
    command=Serial.read();//read the command comming via the bluetooth module
    //display the comand received
    //Serial.println(command);
    Stop();//default commnad that means if a command is not provided then stop the motors
    switch(command)
    {
      case 'F':
               forward();
               break;
      case 'B':
              back();
              break;
      case 'L':
              left();
              break;
      case 'R':
             right();
             break;
      case '0':
              angle=0;
              s1.write(angle);
              break;
              
      case '1':
              angle=10;
              s1.write(angle);
              break;
      
      case '2':
              angle=20;
              s1.write(angle);
              break;
      case '3':
              angle=30;
              s1.write(angle);
              break;
      case '4':
              angle=40;
              s1.write(angle);
              break;
      case '5':
              angle=50;
              s1.write(angle);
              break;
      case '6':
              angle=60;
              s1.write(angle);
              break;
      case '7':
              angle=70;
              s1.write(angle);
              break;
      case '8':
              angle=80;
              s1.write(angle);
              break;
      case '9':
              angle=90;
              s1.write(angle);
              break;     
               
    }
  }
  
}


void forward()
{
  Serial.println("Moving Forward");
  motor3.setSpeed(255);
  motor3.run(FORWARD);

  motor4.setSpeed(255);
  motor4.run(FORWARD);
}

void back()
{ 
  Serial.println("Moving Backward");
  motor3.setSpeed(255);
  motor3.run(BACKWARD);

  motor4.setSpeed(255);
  motor4.run(BACKWARD);
  
}

void left()
{ 
  Serial.println("Moving Left");
  motor3.setSpeed(255 );
  motor3.run(BACKWARD);

  motor4.setSpeed(255);
  motor4.run(FORWARD);
  
}

void right()
{ 
  Serial.println("Moving Right");
  motor3.setSpeed(255);
  motor3.run(FORWARD);

  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

void Stop()
{ 
  Serial.println("Stopped Moving");
  motor3.setSpeed(0);
  motor3.run(RELEASE);

  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
