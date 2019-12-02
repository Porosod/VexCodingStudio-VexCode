#include "robot-config.h"
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VCS VEX V5                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/

//Creates a competition object that allows access to Competition methods.
vex::competition;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
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

void autonomous( void ) {
  
  
  

}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                              User Control Task                             */
/*                                                                            */
/*  This task is used to control your robot during the user control phase of  */
/*  a VEX Competition.                                                        */
/*                                                                            */
/*  You must modify the code to add your own robot specific commands here.    */
/*----------------------------------------------------------------------------*/

void usercontrol( void ) {
    digital_out dig1 = digital_out(Brain.ThreeWirePort.A);
    digital_out dig2 = digital_out(Brain.ThreeWirePort.B);
    digital_out dig3 = digital_out(Brain.ThreeWirePort.C);
    digital_out dig4 = digital_out(Brain.ThreeWirePort.D);
  Brain.Screen.print("..#####..####...#...#...#####......#####."); Brain.Screen.newLine();
  Brain.Screen.print("..#......#..#...#...#...#..........#...#."); Brain.Screen.newLine();
  Brain.Screen.print("..#......####...#####...#####......#####."); Brain.Screen.newLine();
  Brain.Screen.print("..#......#...#..#...#.......#......#...#."); Brain.Screen.newLine();
  Brain.Screen.print("..#####..#####..#...#...#####......#...#."); Brain.Screen.newLine();  
  bool driveH=true;
  bool ReleaseCube = true;
    while(true){
    
    if(Controller1.ButtonB.pressing()){
        driveH=!driveH;
        task::sleep(1000);
    }
       
   
    
   if(true){
        RDM.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
        RDMB.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
        LDM.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
        LDMB.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
       
   }
    
    else {
        RDM.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
        RDMB.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
        LDM.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
        LDMB.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
        CDM.spin(vex::directionType::fwd, Controller1.Axis1.value(), vex::velocityUnits::pct);
        
        while(Controller1.Axis4.value()){
        RDM.spin(vex::directionType::rev, Controller1.Axis4.value(), vex::velocityUnits::pct);
        RDMB.spin(vex::directionType::rev, Controller1.Axis4.value(), vex::velocityUnits::pct);
        LDM.spin(vex::directionType::fwd, Controller1.Axis4.value(), vex::velocityUnits::pct);
        LDMB.spin(vex::directionType::fwd, Controller1.Axis4.value(), vex::velocityUnits::pct);
         }
    }
       
      
      
        if(Controller1.ButtonR1.pressing()){
           
           THEARM.spin(directionType::rev,100,velocityUnits::rpm);
           THEARM2.spin(directionType::fwd,100,velocityUnits::rpm);
        }
    
       else if(Controller1.ButtonR2.pressing()) {
              THEARM.spin(directionType::fwd,100,velocityUnits::rpm);           
              THEARM2.spin(directionType::rev,100,velocityUnits::rpm);           
        }
        else{
            //stop the damn arem
            THEARM.stop(brakeType::brake);
            THEARM2.stop(brakeType::brake);
        }
        
        if(Controller1.ButtonA.pressing()){
            ReleaseCube = !ReleaseCube;
            if(ReleaseCube==true){
            Release.rotateTo(-100,rotationUnits::deg);
            Release.stop(brakeType::brake);
            }
            else{
            Release.rotateTo(400,rotationUnits::deg);
            Release.stop(brakeType::brake);
            }
        }  
   // ........................................................................
 
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    
    //Run the pre-autonomous function. 
    pre_auton();
    
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );

    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}