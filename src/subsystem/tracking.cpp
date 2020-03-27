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
    // ASSUME ZERO FOR NOW
    double x, y, theta = 0;
    double x0, y0, theta0 = 0; 
    double left0, right0, back0 = 0;    // tracking wheel positions
    double delta_x, delta_y, delta_theta;
    while(true){
        // calculating positional values
        delta_theta = degrees(getAngleChange(left0, right0));
        theta = theta0 + delta_theta;
        // update variables for next cycle
        x0 = x;
        y0 = y;
        theta0 = theta;
        left0 = leftTrack.get_value();
        right0 = rightTrack.get_value();
        back0 = backTrack.get_value();
        // delay to save CPU
        pros::delay(5);  // 5 ms for higher precision (max 10)
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
    // POSSIBLY RELOCATE TO FILE DEDICATED TO BRAIN DISPLAY
}
