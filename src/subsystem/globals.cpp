#include "main.h"

pros::Motor leftFront(1, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightFront(10, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftBack(11, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightBack(20, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);

// master controller
pros::Controller con(pros::E_CONTROLLER_MASTER);

// encoders for tracking  -- update ports to match actual robot when testing!
pros::ADIEncoder leftTrack('A', 'B', false);
pros::ADIEncoder rightTrack('E', 'F', true);
pros::ADIEncoder backTrack('C', 'D', false);

// some global constants
const double PI = 3.1415926535;  // probably enough sig figs
