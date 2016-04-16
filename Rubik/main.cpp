/*
 * main.cpp: 3D Shapes
 */
#include <cstdlib>
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include "DrawHandler.h"

/* Global variables */
char title[] = "Rubix";
GLfloat anglePyramid = 0.0f;  // Rotational angle for pyramid [NEW]
int window_1, window_2;

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   char choice = -1;
   glutInit(&argc, argv);

   while (choice != '0') {
       int iteration;
       system("CLS");
       printLogo();
       printMenu();
       std::cout << std::endl;
       std::cout << "Input: ";
       std::cin >> choice;

       if (choice == '1') { // cube
           glutInitWindowSize(640, 480);
           glutInitWindowPosition(50, 50);
           window_1 = glutCreateWindow (argv[0]);
           glutSetWindowTitle(title);
           glutDisplayFunc(display_1);
           glutReshapeFunc(reshape_1);
           initGL();
           glutTimerFunc(0, timer, 0);
           display_1();
           glutMainLoop();
       }
   }
   printGoodbye();
   return 0;
}
