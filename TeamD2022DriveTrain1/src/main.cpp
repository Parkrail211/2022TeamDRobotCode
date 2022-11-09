// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// rMotor               motor         1               
// lMotor               motor         2               
// Controller1          controller                    
// FlyWheelMotors       motor_group   3, 4            
// PushMotor            motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----
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
      rMotor.spin(forward);
      lMotor.spin(forward);
      //
      
    }
    else {
      rMotor.stop();
      lMotor.stop();
    }
    #pragma endregion

    #pragma region launcher
    //if a button is pressed launch disk
    if(Controller1.ButtonA.pressing() == true) {
      FlyWheelMotors.setVelocity(100, percent);
      FlyWheelMotors.spin(forward);
      //spinn flywheel
      vex::task::sleep(1000);
      //wait for wheels to get to speed
      PushMotor.setVelocity(15, percent);
      PushMotor.setPosition(0, degrees);
      PushMotor.spinToPosition(180, degrees);
      PushMotor.spinToPosition(0, degrees);
      //push arm
      FlyWheelMotors.stop();
      //stop wheels
    }

    #pragma endregion
  }
}
