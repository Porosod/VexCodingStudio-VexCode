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
// InLeft               motor         14              
// InRight              motor         16              
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
  Brain.Screen.print("  #####  ####   #   #  #####    #####"); Brain.Screen.newLine();
  Brain.Screen.print("  #      #   #  #   #  #        #   #"); Brain.Screen.newLine();
  Brain.Screen.print("  #      ####   #####  #####    #####"); Brain.Screen.newLine();
  Brain.Screen.print("  #      #   #  #   #      #    #   #"); Brain.Screen.newLine();
  Brain.Screen.print("  #####  #####  #   #  #####    #   #"); Brain.Screen.newLine();
  //RDM.rotateTo(90,deg);
  //LDM.rotateTo(90,deg);



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
  int L1State=0;
  // User control code here, inside the loop
  //bool ReleaseCube=true;
  while (1) {
    if(true){//tank drive
        RDM.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
        //RDMB.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
        LDM.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
        //LDMB.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
        CDM.spin(vex::directionType::fwd, Controller1.Axis1.value(), vex::velocityUnits::pct);
        CDM.spin(vex::directionType::fwd, Controller1.Axis4.value(), vex::velocityUnits::pct);
   }
   else { //non functional for now
        RDM.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
        //RDMB.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
        LDM.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
        //LDMB.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
        CDM.spin(vex::directionType::fwd, Controller1.Axis1.value(), vex::velocityUnits::pct);
        
        while(Controller1.Axis4.value()){
        RDM.spin(vex::directionType::rev, Controller1.Axis4.value(), vex::velocityUnits::pct);
        RDMB.spin(vex::directionType::rev, Controller1.Axis4.value(), vex::velocityUnits::pct);
        LDM.spin(vex::directionType::fwd, Controller1.Axis4.value(), vex::velocityUnits::pct);
        LDMB.spin(vex::directionType::fwd, Controller1.Axis4.value(), vex::velocityUnits::pct);
         }
    }
    if(Controller1.ButtonL1.pressing()){
           
           
        InLeft.spin(directionType::fwd,50,velocityUnits::rpm);
        InRight.spin(directionType::rev,25,velocityUnits::rpm);
        }
    
       else if(Controller1.ButtonL2.pressing()) {
            InLeft.spin(directionType::rev,25,velocityUnits::rpm);
            InRight.spin(directionType::fwd,25,velocityUnits::rpm);           
             
        }
        else{
            //stop the damn intakes
           InLeft.stop(brakeType::hold);
           InRight.stop(brakeType::hold);
        }

    if(Controller1.ButtonR1.pressing()){
           
            ArmLeft.spin(directionType::fwd,50,velocityUnits::rpm);
            ArmRight.spin(directionType::rev,50,velocityUnits::rpm);           
        }
        else if(Controller1.ButtonR2.pressing()){
          ArmLeft.spin(directionType::rev,50,velocityUnits::rpm);
          ArmRight.spin(directionType::fwd,50,velocityUnits::rpm);           
        }
     if(Controller1.ButtonUp.pressing()){
            InTakeLift.spin(directionType::fwd,25,velocityUnits::rpm);
        }
        else if(Controller1.ButtonDown.pressing()){
            InTakeLift.spin(directionType::rev,25,velocityUnits::rpm);
        }
        else{
          InTakeLift.stop(brakeType::hold);
        }
     //TYFF MADE A BIG CHANGE! wow
       
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
