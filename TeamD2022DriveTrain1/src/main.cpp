/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Parker                                           */
/*    Created:      Wed Oct 12 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// rMotor               motor         1               
// lMotor               motor         2               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  int deadband = 5;
  while(true) {

    //single stick steer
    #pragma region driveTrain
    if(Controller1.Axis3.position(percent) + Controller1.Axis4.position(percent) > deadband) {
      double rMotorVelocity = Controller1.Axis3.position(percent) + Controller1.Axis4.position(percent);
      double lMotorVelocity = Controller1.Axis3.position(percent) - Controller1.Axis4.position(percent);
      rMotor.setVelocity(rMotorVelocity, percent);
      lMotor.setVelocity(lMotorVelocity, percent);
      //
      
    }
    else {
      rMotor.setVelocity(0, percent);
      lMotor.setVelocity(0, percent);
    }
    #pragma endregion
  }
}
