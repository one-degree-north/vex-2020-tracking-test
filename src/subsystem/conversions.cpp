#include "main.h"

/**
 * Convert radians to degrees
 * @param rad Radians to be converted
 * @return Angle value in degrees
 */
double degrees(double rad){
    return rad * (180/PI);
}

/**
 * Convert degrees to radians
 * @param deg Angle in degrees to be converted
 * @return Angle value in radians
 */
double rad(double deg){
    return deg * (PI/180);
}

/**
 * Get the r value of a polar coordinate (r, Θ) from a Cartesian coordinate (x, y)
 * @param x The x-value of the Cartesian (x, y) coordinate
 * @param y The y-value of the Cartesian (x, y) coordinate
 * @return The r value of the polar (r, Θ) coordinate
 */
double polarR(double x, double y){
    return sqrt(pow(x, 2) + pow(y, 2));
}

/**
 * Get the Θ value of a polar coordinate (r, Θ) from a Cartesian coordinate (x, y)
 * @param x The x-value of the Cartesian (x, y) coordinate
 * @param y The y-value of the Cartesian (x, y) coordinate
 * @return The Θ value of the polar (r, Θ) coordinate
 */
double polarAngle(double x, double y){
    return atan(y / x);
}

/**
 * Get the x value of a Cartesian coordinate from a polar coordinate (r, Θ)
 * @param r The r vlaue of the polar (r, Θ) coordinate
 * @param a The Θ vlaue of the polar (r, Θ) coordinate
 * @return The r value of the polar (r, Θ) coordinate
 */
double xPos(double r, double a){
    return r * cos(a);
}

/**
 * Get the y value of a Cartesian coordinate from a polar coordinate (r, Θ)
 * @param r The r vlaue of the polar (r, Θ) coordinate
 * @param a The Θ vlaue of the polar (r, Θ) coordinate
 * @return The r value of the polar (r, Θ) coordinate
 */
double yPos(double r, double a){
    return r * sin(a);
}