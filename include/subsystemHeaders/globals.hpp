#include "main.h"

// standard 4-motor drive
extern pros::Motor leftFront;
extern pros::Motor rightFront;
extern pros::Motor leftBack;
extern pros::Motor rightBack;

// master controller
extern pros::Controller con;

// encoders for tracking 
extern pros::ADIEncoder leftTrack;
extern pros::ADIEncoder rightTrack;
extern pros::ADIEncoder backTrack;

// some global constants
extern const double PI;