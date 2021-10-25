/*
 * temp.h
 *
 *  Created on: Oct 20, 2021
 *      Author: yash
 */

#ifndef INCLUDE_SIMULATOR_H_
#define INCLUDE_SIMULATOR_H_

#include <GL/glut.h>

#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <ik.h>

using namespace std;

GLfloat cameraDistance = 12, cameraAngle = 0;

// angles = { Y rotation at shoulder, Z rotation at shoulder, Z rotation at elbow, X rotation at wrist }
int arm_angles[4] = {0, 0, 0, 0};
enum { SHOULDER_Y, SHOULDER_Z, ELBOW_Z, WRIST_X, WRIST_Z };

void change_angle(int angle, int delta, int minimum = 0, int maximum = 180) {
    arm_angles[angle] = (arm_angles[angle] + delta) % 360;
    arm_angles[angle] = max(arm_angles[angle], minimum);
    arm_angles[angle] = min(arm_angles[angle], maximum);
}

// unflod 3D scene
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    GLfloat x = cameraDistance * sin(cameraAngle);
    GLfloat z = cameraDistance * cos(cameraAngle);
    gluLookAt (x, 0.0, z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


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
            glColor3f(249./255., 238./255., 153./255.);
            glutWireCube(1.);       // elbow
        glPopMatrix();

        glTranslatef(1., 0., 0.);
        glRotatef((GLfloat) arm_angles[WRIST_Z], 0., 0., 1.);
        glRotatef((GLfloat) arm_angles[WRIST_X], 1., 0., 0.);

        glTranslatef(1., 0., 0.);
        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glColor3f(207./255., 106./255., 76./255.);
            glutWireCube(1.);       // wrist
        glPopMatrix();
    glPopMatrix();

    // Run the commands
    glutSwapBuffers();
}


// Called when the window resize occurs
void reshape(GLsizei w, GLsizei h) {
    // Tamanyo del viewport
  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 300.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

// Respond to special key events
void specialKeys(int key, int x, int y) {
    GLfloat distanceDelta = 1.0, angleDelta = 5 * M_PI / 180.0;
    if(key == GLUT_KEY_UP) {
        cameraDistance -= distanceDelta;
        cameraDistance = max((GLfloat)2.0, cameraDistance);
    }
    if(key == GLUT_KEY_DOWN) {
        cameraDistance += distanceDelta;
    }
    if(key == GLUT_KEY_LEFT) {
        cameraAngle -= angleDelta;
    }
    if(key == GLUT_KEY_RIGHT) {
        cameraAngle += angleDelta;
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    int delta = 5;

    switch (key) {
        case 27: //ESC
            exit(0);
        case 'angle[0]':
            change_angle(SHOULDER_Y, delta, -180, 0);
            break;
        case 'angle[0]':
            change_angle(SHOULDER_Y, -delta, -180, 0);
            break;
        case 'angle[1]':
            change_angle(SHOULDER_Z, delta, -90, 90);
            break;
        case 'angle[1]':
            change_angle(SHOULDER_Z, -delta, -90, 90);
            break;
        case 'angle[2]':
            change_angle(ELBOW_Z, delta, 0, 135);
            break;
        case 'angle[2]':
            change_angle(ELBOW_Z, -delta, 0, 135);
            break;
        case 'angle[3]':
            change_angle(WRIST_X, delta, -45, 45);
            break;
        case 'angle[3]':
            change_angle(WRIST_X, -delta, -45, 45);
            break;
        case 't':
            change_angle(WRIST_Z, delta, -15, 90);
            break;
        case 'g':
            change_angle(WRIST_Z, -delta, -15, 90);
            break;
    }
    glutPostRedisplay();
}




#endif /* INCLUDE_SIMULATOR_H_ */
