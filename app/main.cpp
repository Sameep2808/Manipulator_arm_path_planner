///============================================================================
/// @file        : main.cpp
/// @author      : Sameep Pote (Driver)
/// @author      : Yash Kulkarni (Navigator)
/// @version     : 1.0
/// @copyright   : MIT License
/// @brief       : main.cpp Main function to run the program
///============================================================================

#include <ik.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
Ik_solver rob;
GLfloat cameraDistance = 12, cameraAngle = 0;
int c = 0;
// angles = { Y rotation at shoulder, Z rotation at shoulder, Z rotation at elbow, X rotation at wrist }
int arm_angles[5] = { 0, 0, 0, 0, 0 };
enum {
  SHOULDER_Y,
  SHOULDER_Z,
  ELBOW_Z,
  WRIST_X,
  WRIST_Z
};

void change_angle(int angle, int delta, int minimum = 0, int maximum = 180) {
  arm_angles[angle] = (arm_angles[angle] + delta) % 360;
  arm_angles[angle] = max(arm_angles[angle], minimum);
  arm_angles[angle] = min(arm_angles[angle], maximum);
}



