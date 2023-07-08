#include <Arduino.h>
#include "BrushlessSumo.h"

BrushlessSumo sumo = BrushlessSumo();

boolean runForward = true;

//create some functions that can be used on first pass
void Strat1(){

  
}


void Strat2(){
  
}

void setup() {

  //Uncomment when debugging.
  Serial.begin(115200);
  
 
 sumo.setup();

 sumo.stop();
 delay(2800); // delay to ensure the ESC is ready!

 //Wait For the start signal to be sent
 //sumo.WaitForStart();

 //three second start after the signal is sent.
 //delay(3000);

 //What is our first move strat?

 //if(sumo.IsDIP1On()){
 //  if(!sumo.IsDIP2On()){
 //   if(!sumo.IsDIP3On()){
 //     sumo.forward(30, 30);
 //   }
 //  }
 //}

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //if(sumo.IsStarted())
  //{
    if(sumo.IsOnFrontLeftLight() || sumo.IsOnFrontRightLight()) {

         sumo.reverse(50, 50);
         delay(350);
         sumo.stop();
         sumo.left(0,30);
         delay(200);
         sumo.stop();
      
    }else{
           
         if(sumo.IsFrontLeft() && sumo.IsFrontRight()){
            sumo.forward(80,90);
            Serial.println("Charging");
         /*} else if(sumo.IsFarRightDist()){
            sumo.right(10, 15);
            Serial.println("RightFar");
         } else if(sumo.IsFarLeftDist()){
            sumo.left(15, 10);
            Serial.println("LeftFar"); */
         } else if(sumo.IsMidRightDist()){
            sumo.right(20, 25);
            Serial.println("RightMid");
         } else if(sumo.IsMidLeftDist()){
            sumo.left(25, 20);
            Serial.println("LeftMid"); 
         } else{
          sumo.forward(20, 20);
          //delay(25);
          //sumo.left(35, 10);
         }
     
    }
 // }else{
    //Our kill signal has been triggered, stop the robot at once.
 //   sumo.stop();
 // }
//*/


 //uncomment the code below for debugging - might want to comment the code out above.

    /*
  
  
  Serial.print("DIP1: ");
  Serial.println(digitalRead(DIP1));

  Serial.print("DIP2: ");
  Serial.println(digitalRead(DIP2));

  Serial.print("DIP3: ");
  Serial.println(digitalRead(DIP3));



  Serial.print("FAR LEFT: ");
  Serial.println(sumo.IsFarLeftDist());

  Serial.print("MID LEFT: ");
  Serial.println(sumo.IsMidLeftDist());

   Serial.print("FRONT LEFT: ");
  Serial.println(sumo.IsFrontLeft());

   Serial.print("FRONT RIGHT: ");
  Serial.println(sumo.IsFrontRight());

   Serial.print("MID RIGHT: ");
  Serial.println(sumo.IsMidRightDist());

   Serial.print("FAR RIGHT: ");
  Serial.println(sumo.IsFarRightDist());

  
  Serial.print("LEFT LIGHT:");
  Serial.println(sumo.IsOnFrontLeftLight());
  Serial.println(analogRead(AC1));

  
  Serial.print("RIGHT LIGHT:");
  Serial.println(sumo.IsOnFrontRightLight());
  Serial.println(analogRead(AC4));

  
  
  

  
  delay(200);*/

  

}
