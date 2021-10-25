///============================================================================
/// @file        : main.cpp
/// @author      : Sameep Pote (Driver)
/// @author      : Yash Kulkarni (Navigator)
/// @version     : 1.0
/// @author      : Yash Kulkarni (Driver)
/// @author      : Sameep Pote (Navigator)
/// @version     : 2.0
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

/// Initialize the variables
Ik_solver rob;
GLfloat cameraDistance = 12, cameraAngle = 0;
int c = 0;
/// angles = { Y rotation at shoulder, Z rotation at shoulder,
///               Z rotation at elbow, X rotation at wrist }
int arm_angles[5] = { 0, 0, 0, 0, 0 };
enum {
  SHOULDER_Y,
  SHOULDER_Z,
  ELBOW_Z,
  WRIST_X,
  WRIST_Z
};

/// @fn void change_angle(int, int, int, int)
/// @brief Setting new angles of the arm
/// @param angle
/// @param delta
/// @param minimum
/// @param maximum
void change_angle(int angle, int delta, int minimum = 0, int maximum = 180) {
  arm_angles[angle] = (arm_angles[angle] + delta) % 360;
  arm_angles[angle] = std::max(arm_angles[angle], minimum);
  arm_angles[angle] = std::min(arm_angles[angle], maximum);
}

/// @fn void display(void)
/// @brief Creating the arm in the simulator and giving it angles according
///        to the ik_solver
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
  glRotatef((GLfloat) -arm_angles[SHOULDER_Y], 0., 1., 0.);
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
    if (arm_angles[SHOULDER_Y] != round(rob.angle[0])) {
      if (arm_angles[SHOULDER_Y] < round(rob.angle[0])) {
        arm_angles[SHOULDER_Y] += 1;
      } else {
        arm_angles[SHOULDER_Y] -= 1;
      }
    }

    if (arm_angles[SHOULDER_Z] != round(rob.angle[1])) {
      if (arm_angles[SHOULDER_Z] < round(rob.angle[1])) {
        arm_angles[SHOULDER_Z] += 1;
      } else {
        arm_angles[SHOULDER_Z] -= 1;
      }
    }

    if (arm_angles[ELBOW_Z] != round(rob.angle[2])) {
      if (arm_angles[ELBOW_Z] < round(rob.angle[2])) {
        arm_angles[ELBOW_Z] += 1;
      } else {
        arm_angles[ELBOW_Z] -= 1;
      }
    }

    if (arm_angles[WRIST_Z] != round(rob.angle[3])) {
      if (arm_angles[WRIST_Z] < round(rob.angle[3])) {
        arm_angles[WRIST_Z] += 1;
      } else {
        arm_angles[WRIST_Z] -= 1;
      }
    }
    glutPostRedisplay();
  }

  glutPostRedisplay();
}

/// @fn void specialKeys(GLsizei , Glsizei)
/// @brief This function is used to adjust the camera as per requirement
/// @param w
/// @param h
void reshape(GLsizei w, GLsizei h) {
  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 300.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

/// @fn int main()
/// @brief The main function is to run and execute all the functions
/// @return 0
int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(1900, 1900);
  glutCreateWindow("4DOF Robotic Arm");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glutMainLoop();
  return 0;
}
