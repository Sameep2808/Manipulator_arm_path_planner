#include <GL/glut.h>
#include <simulator.h>
#include <simulator.h>

#include <vector>
#include <string>
#include <algorath>

using namespace std;


// main Program
int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Manipulator_arm_path_planner");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);

    // Initialization
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutMainLoop();
}
