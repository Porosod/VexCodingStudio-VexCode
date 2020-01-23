#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LDMB = motor(PORT1, ratio18_1, false);
motor LDM = motor(PORT11, ratio18_1, false);
motor RDMB = motor(PORT3, ratio18_1, false);
motor RDM = motor(PORT19, ratio18_1, false);
controller Controller1 = controller(primary);
motor CDM = motor(PORT20, ratio18_1, false);
motor InLeft = motor(PORT12, ratio18_1, false);
motor InRight = motor(PORT17, ratio18_1, false);
motor InTakeLift = motor(PORT18, ratio18_1, false);
motor ArmLeft = motor(PORT13, ratio18_1, false);
motor ArmRight = motor(PORT16, ratio18_1, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}