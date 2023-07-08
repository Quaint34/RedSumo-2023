#include "ESCMotor.h"
#include <Servo.h>

ESCMotor::ESCMotor(int p1)
{
    
   
    pinIn1 = p1;
    
    
   
}
void ESCMotor::stop()
{
    //TODO: Need a good braking solution.
    //writing 90 is coasting
    motorServo.write(90);
   
}



void ESCMotor::attach()
{
   
   motorServo.attach(pinIn1, 1000,2000);

}

void ESCMotor::coast()
{
   
   motorServo.write(90);

}

void ESCMotor::forward(int speed){
    setSpeed(speed);
}

void ESCMotor::reverse(int speed){
    setSpeed(-1 * speed);
}

void ESCMotor::setSpeed(int value)
{
    //value is a percentage value between 0 - 100
    //we need to convert it to a value between 0 - 90 for forward and 90 - 180 for reverse
    //we will use 90 as the stop value
    //we will use 0 - 90 for forward and 90 - 180 for reverse
    //we will use 0 - 100 for speed

    if(value > 100)
    {
        value = 100;
    }
    else if(value < -100)
    {
        value = -100;
    }

   
    if(value == 0)
    {
        stop();
    }
    else
    {
        // value = map(value, -100, 100, 0, 180);
        float percent = (abs(value) / 100) * 90;

        if(value > 0){
          value = 90 + value;
        }else{
          value = 90 - abs(value);
        }
        Serial.println(value);
    
        motorServo.write(value);
    }
}
