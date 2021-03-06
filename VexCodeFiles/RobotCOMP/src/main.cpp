/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LDMB                 motor         1               
// LDM                  motor         2               
// RDMB                 motor         3               
// RDM                  motor         4               
// Controller1          controller                    
// CDM                  motor         5               
// Rarm                 motor         14              
// Larm                 motor         16              
// Release              motor         13              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  bool ReleaseCube=false;
  bool SlowDrive = true;
  int ReleaseLoc=Release.position(degrees);
  while (1) {
    if(SlowDrive==true){//tank drive
        RDM.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
        RDMB.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
        LDM.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
        LDMB.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);

        if(Controller1.ButtonLeft.pressing()){//strafing left
        CDM.spin(directionType::rev,100,velocityUnits::rpm);
         }
           else if(Controller1.ButtonRight.pressing()){//right
        CDM.spin(directionType::fwd,100,velocityUnits::rpm);
         }
           else{//stop center drive Motor
          CDM.stop(brakeType::hold);
        }
        if(Controller1.ButtonB.pressing()){
          SlowDrive=!SlowDrive;
        }
   }
   else if(SlowDrive==false){
        RDM.spin(vex::directionType::rev, Controller1.Axis2.value()/2, vex::velocityUnits::pct);
        RDMB.spin(vex::directionType::rev, Controller1.Axis2.value()/2, vex::velocityUnits::pct);
        LDM.spin(vex::directionType::fwd, Controller1.Axis3.value()/2, vex::velocityUnits::pct);
        LDMB.spin(vex::directionType::fwd, Controller1.Axis3.value()/2, vex::velocityUnits::pct);
         
         if(Controller1.ButtonLeft.pressing()){//strafing left
        CDM.spin(directionType::rev,50,velocityUnits::rpm);
         }
           else if(Controller1.ButtonRight.pressing()){//right
        CDM.spin(directionType::fwd,50,velocityUnits::rpm);
         }
           else{//stop center drive Motor
          CDM.stop(brakeType::hold);
        }
        if(Controller1.ButtonB.pressing()){
          SlowDrive=!SlowDrive;
        }
    }
    if(Controller1.ButtonR1.pressing()){
           
           Rarm.spin(directionType::rev,100,velocityUnits::rpm);
           Larm.spin(directionType::fwd,100,velocityUnits::rpm);
        }
    
       else if(Controller1.ButtonR2.pressing()) {
              Rarm.spin(directionType::fwd,100,velocityUnits::rpm);           
              Larm.spin(directionType::rev,100,velocityUnits::rpm);           
        }
       else if(Controller1.ButtonUp.pressing()){//slow arm movement Up
           Rarm.spin(directionType::rev,50,velocityUnits::rpm);
           Larm.spin(directionType::fwd,50,velocityUnits::rpm);
           }
           else if(Controller1.ButtonDown.pressing()){//slow arm movement Down
           Rarm.spin(directionType::fwd,50,velocityUnits::rpm);
           Larm.spin(directionType::rev,50,velocityUnits::rpm);
           }
        else{
            //stop the damn arem
            Rarm.stop(brakeType::hold);
            Larm.stop(brakeType::hold);
        }
        if(Controller1.ButtonUp.pressing()){//slow arm movement Up
           Rarm.spin(directionType::rev,50,velocityUnits::rpm);
           Larm.spin(directionType::fwd,50,velocityUnits::rpm);
           }
           else if(Controller1.ButtonDown.pressing()){//slow arm movement Down
           Rarm.spin(directionType::fwd,50,velocityUnits::rpm);
           Larm.spin(directionType::rev,50,velocityUnits::rpm);
           }
           
        

        if(Controller1.ButtonA.pressing()){//releasing cube
            ReleaseCube=!ReleaseCube;//changes bool to opposite of what it was
            if(ReleaseCube==true){
            ReleaseLoc=Release.position(degrees);
            Release.rotateTo(-65,rotationUnits::deg);
            
            }
            else if (ReleaseCube==false){
            Release.rotateTo(ReleaseLoc,rotationUnits::deg);
           
            }
            else{
              Release.stop(brakeType::brake);
            }


        }
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
