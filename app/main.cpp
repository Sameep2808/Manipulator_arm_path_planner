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

void display(void) {

  double xr, yr, zr, phi, l1 = 5, l2 = 5, l3 = 5;

  glClear(GL_COLOR_BUFFER_BIT);

  glLoadIdentity();
  GLfloat x = cameraDistance * sin(cameraAngle);
  GLfloat z = cameraDistance * cos(cameraAngle);
  gluLookAt(x, 0.0, z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  if (c == 0) {
    std::cout << "Enter Arm Length" << std::endl;
    std::cin >> l1;
    std::cin >> l2;
    std::cin >> l3;
    arm_angles[SHOULDER_Y] = 0;
    arm_angles[SHOULDER_Z] = 0;
    arm_angles[ELBOW_Z] = 0;
    arm_angles[WRIST_Z] = 0;
    c++;
  }
  rob.set_initial(l1, l2, l3);
  glPushMatrix();
  glRotatef((GLfloat) arm_angles[SHOULDER_Y], 0., 1., 0.);
  glRotatef((GLfloat) arm_angles[SHOULDER_Z], 0., 0., 1.);

  glTranslatef(1., 0., 0.);
  glPushMatrix();
  glScalef(2.0, 0.4, 1.0);
  glColor3f(1.0f, 1.0f, 1.0f);
  glutWireCube(1.);       // shoulder
  glPopMatrix();

  glTranslatef(1., 0., 0.);
  glRotatef((GLfloat) arm_angles[ELBOW_Z], 0., 0., 1.);
  glTranslatef(1., 0., 0.);
  glPushMatrix();
  glScalef(2.0, 0.4, 1.0);
  glColor3f(249. / 255., 238. / 255., 153. / 255.);
  glutWireCube(1.);       // elbow
  glPopMatrix();

  glTranslatef(1., 0., 0.);
  glRotatef((GLfloat) arm_angles[WRIST_Z], 0., 0., 1.);

  glTranslatef(1., 0., 0.);
  glPushMatrix();
  glScalef(2.0, 0.4, 1.0);
  glColor3f(207. / 255., 106. / 255., 76. / 255.);
  glutWireCube(1.);
  glPopMatrix();
  glPopMatrix();

  glutSwapBuffers();

  if ((arm_angles[SHOULDER_Y] == round(rob.angle[0]))
      && (arm_angles[SHOULDER_Z] == round(rob.angle[1]))
      && (arm_angles[ELBOW_Z] == round(rob.angle[2]))
      && (arm_angles[WRIST_Z] == round(rob.angle[3]))) {
    std::cout << "Enter the final position and end effector angle" << std::endl;
    std::cin >> xr;
    std::cin >> yr;
    std::cin >> zr;
    std::cin >> phi;
    rob.input_end_point(xr, yr, zr);
    rob.ik_solve(phi);
  } else {
    if (arm_angles[SHOULDER_Y] != round(rob.angle[0]))
      if (arm_angles[SHOULDER_Y] < round(rob.angle[0]))
        arm_angles[SHOULDER_Y] += 1;
      else
        arm_angles[SHOULDER_Y] -= 1;

    if (arm_angles[SHOULDER_Z] != round(rob.angle[1]))
      if (arm_angles[SHOULDER_Z] < round(rob.angle[1]))
              arm_angles[SHOULDER_Z] += 1;
            else
              arm_angles[SHOULDER_Z] -= 1;

    if (arm_angles[ELBOW_Z] != round(rob.angle[2]))
      if (arm_angles[ELBOW_Z] < round(rob.angle[2]))
              arm_angles[ELBOW_Z] += 1;
            else
              arm_angles[ELBOW_Z] -= 1;

    if (arm_angles[WRIST_Z] != round(rob.angle[3]))
      if (arm_angles[WRIST_Z] < round(rob.angle[3]))
              arm_angles[WRIST_Z] += 1;
            else
              arm_angles[WRIST_Z] -= 1;
    glutPostRedisplay();
  }

  glutPostRedisplay();

}



