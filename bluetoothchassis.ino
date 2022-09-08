#include <SoftwareSerial.h> 
SoftwareSerial HC05(0, 1); //RX, TX
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

int delay_time = 250; //Setting a delay time

void setup() {
  // put your setup code here, to run once:
  HC05.begin(9600);

  motor1.setSpeed(200);
  motor2.setSpeed(200);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void forward()
{
  HC05.println("Forward");
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
}

void backward()
{
  HC05.println("Backward");
  motor1.run(FORWARD);
  motor2.run(BACKWARD);

}

void left()
{
  HC05.println("Left");
  motor1.run(FORWARD);
  motor2.run(FORWARD);

}

void right()
{
  HC05.println("Right");
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);

}

void stop(){
  HC05.println("Stop");
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

char cmd;

void loop() {
  // put your main code here, to run repeatedly:
  if (HC05.available() > 0){
    cmd = HC05.read();
    //Using this for rover, so...
    if (cmd == 'f'){
      //This will move the rover up
      forward();
    }

    if (cmd == 'l'){
      //This will move the rover left, rotating it and then moving upward
      left();     
      forward();
    }

    if (cmd == 'r'){
      //This will move the rover right, rotating it and then moving upward
      right();
      forward();
      }

    if (cmd == 'b'){
      //This will reverse the rover
      backward();
    }

    if (cmd == 's'){
      stop();
    }
  }
}
