#include "main.h"

// CONSTANTS
const int DEADZONE = 5;
const double CURVE_MAGNITUDE = 2.5;
const int MAX_VALUE = 127;
const double CURVE_FACTOR_FAST = 0.787;
const double CURVE_FACTOR_SLOW = 0.4;

// HELPER FUNCTIONS
/**
 * Helper function to quickly set the velocities of left and right side motors
 *
 * @param left Velocity of left side
 * @param right Velocity of right side
 */
void setDrive(int left, int right){
  leftFront = left;
  leftBack = left;
  rightFront = right;
  rightBack = right;
}
/**
 * Curves the velocity along an exponential curve
 *
 * @param x Velocity to be curved
 * @param curve_factor Multiplier of entire curve function
 * @return curved input if input is greater than the deadzone value or 0 if
 * the value is less than the deadzone
 */
double driveCurve(int x, double curve_factor) {
  if(abs(x) > DEADZONE){
    int input = std::min((int)std::abs(x), MAX_VALUE);
    double output = (x/abs(x)) * ((curve_factor) *
                     (pow((input / pow(MAX_VALUE, (1 - (1 / CURVE_MAGNITUDE)))),
                          CURVE_MAGNITUDE)));
    return output;
  }
  else
    return 0;
}

/**
 * Outputs drive voltages to Brain screen using LCD emulator
 */
void printDrive(){
  
  int xVal = round(con.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X));
  int yVal = round(con.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));

  std::string left = "Left side: " +
                      std::to_string(driveCurve(round(round(yVal)+round(xVal)),
                      CURVE_FACTOR_FAST));
  std::string right = "Right side: " +
                      std::to_string(driveCurve(round(round(yVal)-round(xVal)),
                      CURVE_FACTOR_FAST));

  pros::lcd::set_text(2, left);
  pros::lcd::set_text(3, right);
}

/**
 * Applies deadzone to joystick
 *
 * @param input The value of an analog joystick
 * @return input if input is greater than the deadzone value or 0 if the value
 *is less than the deadzone
 */
int round(int input){
  
  if(abs(input)>DEADZONE)
    return input;
  else
    return 0;
}


// AUTONOMOUS FUNCTIONS
/**
 * Resets drivebase motor encoders to 0
 */
void resetDriveMotors(){
  
  leftFront.tare_position();
  leftBack.tare_position();
  rightFront.tare_position();
  rightFront.tare_position();
}

// CHANGE TO OKAPI CHASSIS PID LATER
/**
 * Autonomous function that drives the robot forward distance dist at speed voltage
 * 
 * @param dist Distance to be travelled (in inches)
 * @param voltage Voltage drive motors to be set to
 */
void autoDrive(double dist, int voltage){
  
  int dir = std::fabs(dist)/dist;
  // calc avg displacement
  double avg = leftFront.get_position() + leftBack.get_position() 
             + rightFront.get_position() + rightBack.get_position();
  while(std::fabs(avg) > std::fabs(dist)){
    setDrive(dir*voltage, dir*voltage);
    pros::delay(10);
  }
}

// DRIVER CONTROL FUNCTIONS
/**
 * Sets the drive motors using joystick values (arcade mode)
 */
void setDriveMotors(){
  int xVal = round(con.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X));
  int yVal = round(con.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));

  setDrive(driveCurve(round(round(yVal)+round(xVal)), CURVE_FACTOR_FAST),
           driveCurve(round(round(yVal)-round(xVal)), CURVE_FACTOR_FAST));
}