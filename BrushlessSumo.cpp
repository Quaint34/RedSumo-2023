#include "BrushlessSumo.h"
#include "Constants.h"

BrushlessSumo::BrushlessSumo()
{

   
}

boolean BrushlessSumo::IsDIP1On(){

  return digitalRead(DIP1);
}


boolean BrushlessSumo::IsDIP2On(){

  return digitalRead(DIP2);
}



boolean BrushlessSumo::IsDIP3On(){

  return digitalRead(DIP3);
}


boolean BrushlessSumo::IsStarted(){

  return digitalRead(DC4);
}

void BrushlessSumo::WaitForStart(){

  while(!digitalRead(DC4)){
    delay(2);
  }
}

void BrushlessSumo::setup(){

  pinMode(DIP1, INPUT_PULLUP);
  pinMode(DIP2, INPUT_PULLUP);
  pinMode(DIP3, INPUT_PULLUP);
  
  pinMode(AC1, INPUT);
  pinMode(AC2, INPUT);
  pinMode(AC3, INPUT);
  pinMode(AC5, INPUT);

  pinMode(DC1, INPUT);
  pinMode(DC2, INPUT);
  pinMode(DC3, INPUT);
  pinMode(DC4, INPUT);
  pinMode(DC5, INPUT);
  pinMode(DC6, INPUT);
  pinMode(DC7, INPUT);
  pinMode(DC8, INPUT);
  pinMode(DC9, INPUT);
  pinMode(DC10, INPUT);
  pinMode(DC11, INPUT);
  pinMode(DC12, INPUT);

  pinMode(USR_LED, OUTPUT);
  
  _leftMotor.attach();
  _rightMotor.attach();

}

void BrushlessSumo::forward(int speedleft, int speedRight){

  
    _rightMotor.reverse(speedRight);
    _leftMotor.reverse(speedleft);
      
    
    

}

void BrushlessSumo::reverse(int speedleft, int speedRight){

     _leftMotor.forward(speedleft);
    _rightMotor.forward(speedRight);
    


}
void BrushlessSumo::left(int speedleft, int speedRight){

    _leftMotor.forward(speedleft);
    _rightMotor.reverse(speedRight);

}
void BrushlessSumo::right(int speedleft, int speedRight){

    _leftMotor.reverse(speedleft);
    _rightMotor.forward(speedRight);
}
void BrushlessSumo::stop(){

    _leftMotor.stop();
    _rightMotor.stop();
}

void BrushlessSumo::coast(){

    _leftMotor.coast();
    _rightMotor.coast();
}


boolean BrushlessSumo::IsOnFrontRightLight()
{
  return analogRead(AC5) > 50; 
}

boolean BrushlessSumo::IsOnFrontLeftLight()
{
  return analogRead(AC1) > 50; 
}


boolean BrushlessSumo::IsFarLeftDist()
{
  return !digitalRead(DCDB1); 
}
boolean BrushlessSumo::IsMidLeftDist()
{
  return !digitalRead(AC2); 
}
boolean BrushlessSumo::IsFrontLeft()
{
  return !digitalRead(AC3); 
}


boolean BrushlessSumo::IsFarRightDist()
{
  return !digitalRead(DCDB2); 
}

boolean BrushlessSumo::IsMidRightDist()
{
  return !digitalRead(DC12); 
}
boolean BrushlessSumo::IsFrontRight()
{
  return !digitalRead(DC1); 
}
        
