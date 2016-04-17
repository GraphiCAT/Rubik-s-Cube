#include "DrawHandler.h"
#include "Point3D.h"
#include "Cell.h"
#include "Cube.h"

const int TRIANGLE = 0;
const int TRIANGLE_POINT = 1;
Cube rubiks;

#define CLOCKWISE 0
#define COUNTER_CLOCKWISE -1
#define TOP 1
#define BOTTOM 2
#define LEFT 3
#define RIGHT 4
#define BACK 5
#define FRONT 6
#define MIDDLEX 7


#include <vector>
using namespace std;


int refreshMills = 15;        // refresh interval in milliseconds [NEW]
int iteration = 1;
float angle = 0.0f;
int direction = CLOCKWISE;

/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor (1.0, 1.0, 1.0,1.0);
    glColor3f(0.0,0.0,0.0);
}

void displayCube() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
   rubiks.resetCube();
   rubiks.drawCube();
   glFlush();
}

void keyPressed (unsigned char key, int x, int y) {
  Sleep(100);
  if (key=='b') {
    rubiks.handleRotate(BOTTOM,direction);
  } else if (key=='f') {
    rubiks.handleRotate(FRONT,direction);
  } else if (key=='x') {
    rubiks.handleRotate(MIDDLEX,direction);
  } else if (key=='t') {
    rubiks.handleRotate(TOP,direction);
  } else if (key=='c') {
    toggleDirection();
  }
}

void toggleDirection() {
  if (direction==CLOCKWISE)
    direction = COUNTER_CLOCKWISE;
  else
    direction = CLOCKWISE;
}


void mouse(int btn, int state, int x, int y)
  {
    if (state == GLUT_DOWN)
    {
      if (btn == GLUT_LEFT_BUTTON);

      else if (btn == GLUT_RIGHT_BUTTON);

  }
}

/* Called back when timer expired [NEW] */

void timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}

float red = 229.0/255.0;
float green = 0.0;
float blue = 81.0/255.0;

void triangle( point2 a, point2 b, point2 c)
/* display one triangle  */
{
    glColor3f(red, green, blue);
    glBegin(GL_TRIANGLES);
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
    glEnd();

    if (red > 0) {
        red = red - (229.0/255.0)/iteration;
        green = green + (148.0/255.0)/iteration;
        blue = blue + (180.0/255.0)/iteration;
    } else {
        red = 229.0/255.0;
        green = 0;
        blue = 81.0/255.0;
    }

    /* if (red > 0 && blue < 0.25) {
        red = red - 0.25;
        green = green + 0.25;
    } else if (green > 0 && red < 0.25) {
        green = green - 0.25;
        blue = blue + 0.25;
    } else if (blue > 0 && green < 0.25) {
        blue = blue - 0.25;
        red = red + 0.25;
    } */
}


float red_point = 0.0/255.0;
float green_point = 166.0/255.0;
float blue_point  = 229.0/255.0;

void triangle_point( point2 a, point2 b, point2 c)
/* display one triangle  */
{
    glColor3f(red_point, green_point, blue_point);
    glBegin(GL_LINES);
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
    glVertex2fv(a);
    glEnd();

    if (red_point < (175.0/255.0)) {
        red_point = red_point + (175.0/255.0)/iteration;
        green_point = green_point + (77.0/255.0)/iteration;
        blue_point = blue_point - (131.0/255.0)/iteration;
    } else {
        red_point = 0.0/255.0;
        green_point = 166.0/255.0;
        blue_point  = 229.0/255.0;
    }
}

// Draw our world
void display_1(void)
{
   displayCube();
}


// This is called when the window has been resized.
void reshape_2 (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
}

// This is called when the window has been resized.
void reshape_3 (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape_1(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void setIteration(int itr) {
    iteration = itr;
}

void printLogo() {
    char fr = 176;
    char fr_array[33];
    int i;
    for (i=0; i<33; i++) {
        fr_array[i] = fr;
    }
    fr_array[i] = 0;
    std::cout << "                     " << fr_array << std::endl;
    std::cout << std::endl;
    std::cout << "                     " << "  Welcome to GraphiCAT Program!  " << std::endl;
    std::cout << std::endl;
    std::cout << "                     " << fr_array << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

void printMenu() {
    std::cout << "Please select from the programs listed below:" << std::endl;
    std::cout << "1. Rainbow cube" << std::endl;
    std::cout << "2. Sierpinski Sieve Points" << std::endl;
    std::cout << "3. Sierpinski Sieve" << std::endl;
    std::cout << "0. Exit :(" << std::endl;
}

void printGoodbye() {
   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << "                         ====== Bye-bye! :'( ======                         " << std::endl;
}
