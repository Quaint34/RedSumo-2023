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
    if (sumo.IsOnFrontLeftLight()) {
         sumo.reverse(50, 50);
         delay(350);
         sumo.stop();
         sumo.right(20,20); /* turn right when the left sensor hit the edge*/
         delay(500);
         sumo.stop();

    }else if (sumo.IsOnFrontRightLight()) {
         sumo.reverse(50, 50);
         delay(350);
         sumo.stop();
         sumo.left(20,20); /* turn left when the right sensor hit the edge*/
         delay(500);
         sumo.stop();
      
    }else{
           /* Changed charge condition to either one of the sensor is true to make to robot more prone to charge
           instead of keep turning right and left until both sensor is true */
         if(sumo.IsFrontLeft()){
          if(sumo.IsFrontRight()){
              sumo.forward(90,90);
              Serial.println("Charging");
            } else{
              sumo.forward(10, 15);
            }
          
          } else if(sumo.IsFrontRight()){
            if(sumo.IsFrontLeft()){
                sumo.forward(90,90);
                Serial.println("Charging");
            } else{
              sumo.forward(15, 10);
            }
         } else if(sumo.IsFarRightDist()){
            sumo.right(17, 0);
            Serial.println("RightFar");
         
         } else if(sumo.IsFarLeftDist()){
            sumo.left(0, 17);
            Serial.println("LeftFar");
            
         } else if(sumo.IsMidRightDist()){
            sumo.right(5, 5);
            Serial.println("RightMid");
            
         } else if(sumo.IsMidLeftDist()){
            sumo.left(5, 5);
            Serial.println("LeftMid"); 
         
         } else{
          sumo.forward(20, 20);
          //delay(25);
          //sumo.left(35, 10);
         } 
    }
  }
