#pragma once

#include "Arduino.h"
#include <Servo.h>

class ESCMotor 
{
    public:
        ESCMotor(int);
        void attach();
        void setSpeed(int);
        void forward(int);
        void reverse(int);
        void stop();
        void coast();
    private:
        int pinIn1;
        Servo motorServo;
        
        
};
