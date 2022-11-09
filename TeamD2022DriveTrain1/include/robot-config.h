using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor rMotor;
extern motor lMotor;
extern controller Controller1;
extern motor_group FlyWheelMotors;
extern motor PushMotor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );