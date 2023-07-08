
#pragma once


#include "Constants.h"
#include "ESCMotor.h"


class BrushlessSumo
{
    public:
       

        BrushlessSumo();
        void setup();
        void forward(int, int);
        void reverse(int, int);
        void left(int, int);
        void right(int, int);
        void stop();
        void coast();

        boolean IsDIP1On();
        boolean IsDIP2On();
        boolean IsDIP3On();
       
        boolean IsStarted();

        boolean IsOnFrontRightLight();
        boolean IsOnFrontLeftLight();

        boolean IsFarLeftDist();
        boolean IsMidLeftDist();
        boolean IsFrontLeft();

        
        boolean IsFarRightDist();
        boolean IsMidRightDist();
        boolean IsFrontRight();
        

        void WaitForStart();
        
        

    private:
     
        ESCMotor _leftMotor = ESCMotor(DC2); 
        ESCMotor _rightMotor = ESCMotor(DC11); 
       
        
};
