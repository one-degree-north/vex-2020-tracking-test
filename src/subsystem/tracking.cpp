#include "main.h"

/**
 * Notes about units:
 * Distance: inches
 * Time: milliseconds
 * Angle: degrees
 */

//----START CONSTANTS----
// driving wheels
const int WHEEL_DIAMETER = 4;
const double WHEEL_CIRCUMFERENCE = WHEEL_DIAMETER * PI;
const double INCHES_PER_DEG = WHEEL_CIRCUMFERENCE / 360;  // used for converting from encoder to dist.

// tracking wheels (SAMPLE VALUES)
const double OFFSET_LEFT = 7.25; 
const double OFFSET_RIGHT = 7.25;
const double OFFSET_BACK = 7.5;
// initial position of bot
const double INITIAL_X = 0;
const double INITIAL_Y = 0;
const double INITIAL_A = 0;
//----END CONSTANTS----


//----TRACKING ALGORITHM---
void track(void* param){
    // this will be used as a task later!
    // get initial positions
    while(true){

       pros::delay(15);
    }

}

/**
 * Returns the change in position along an axis (x or y)
 * @param start Starting position along that axis
 * @return The change in position along a certain axis
 */
double getPositionChange(double start){

}

/**
 * Returns the change in angle in degrees (using clockwise = positive)
 * @param L0 Original position of left tracking wheel at begining of interval
 * @param dR Original position of left tracking wheel at begining of interval
 * @return Change in orientation in degrees
 */
double getAngleChange(double L0, double R0){
    return degrees(((leftTrack.get_value()-L0) - (rightTrack.get_value()-R0)) / (OFFSET_LEFT + OFFSET_RIGHT));
}

/**
 * Print position values of robot to brain screen
 * @param a The angle of the robot relative to its starting orientation
 * @param x The x-coordinate of the robot on the playing field (in feet)
 * @param y The y-coordinate of the robot on the playing field (in feet)
 */
void printToScreen(double a, double x, double y){
    // might relocate to another file dedicated to brain stuff
}
