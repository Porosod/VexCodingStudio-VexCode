using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LDMB;
extern motor LDM;
extern motor RDMB;
extern motor RDM;
extern controller Controller1;
extern motor CDM;
extern motor InLeft;
extern motor InRight;
extern motor Release;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );