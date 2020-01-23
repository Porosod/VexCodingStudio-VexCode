#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"
//
using namespace vex;
vex::brain Brain;
vex::motor LDMB (vex::PORT1, vex::gearSetting::ratio18_1,false);
vex::motor LDM (vex::PORT2, vex::gearSetting::ratio18_1,false);
vex::motor RDMB (vex::PORT3, vex::gearSetting::ratio18_1,false);
vex::motor RDM (vex::PORT4, vex::gearSetting::ratio18_1,false);
vex::motor CDM (vex::PORT5, vex::gearSetting::ratio18_1,false);
vex::motor Release (vex::PORT13, vex::gearSetting::ratio18_1,false);
vex::motor THEARM (vex::PORT14, vex::gearSetting::ratio18_1,false);
vex::motor THEARM2 (vex::PORT16, vex::gearSetting::ratio18_1,false);
vex::controller Controller1;
vex::competition Competition;
