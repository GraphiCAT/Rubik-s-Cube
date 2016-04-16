#include "Cube.h"
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

#include <iostream>

using namespace std;
GLfloat angleCube = 0.0f;     // Rotational angle for cube [NEW]

Cube::Cube() {
    //Define Color
    for (int i = 0; i < 9; i++) {
        color[i] = WHITE;
    }
    for (int i = 9; i < 18; i++) {
        color[i] = YELLOW;
    }
    for (int i = 18; i < 27; i++) {
        color[i] = RED;
    }
    for (int i = 27; i < 36; i++) {
        color[i] = ORANGE;
    }
    for (int i = 36; i < 45; i++) {
        color[i] = BLUE;
    }
    for (int i = 45; i < 54; i++) {
        color[i] = GREEN;
    }

    Point3D top(0,-1,0);
    Point3D bottom(0,1,0);
    Point3D right(1,0,0);
    Point3D left(-1,0,0);
    Point3D behind(0,0,-1);
    Point3D infront(0,0,1);

    //TOP SURFACE
    surface[0] = Cell(WHITE, Point3D(-1,-1.9,-1), top);
    surface[1] = Cell(WHITE, Point3D(0,-1.9,-1), top);
    surface[2] = Cell(WHITE, Point3D(1,-1.9,-1), top);
    surface[3] = Cell(WHITE, Point3D(-1,-1.9,0), top);
    surface[4] = Cell(WHITE, Point3D(0,-1.9,0), top);
    surface[5] = Cell(WHITE, Point3D(1,-1.9,0), top);
    surface[6] = Cell(WHITE, Point3D(-1,-1.9,1), top);
    surface[7] = Cell(WHITE, Point3D(0,-1.9,1), top);
    surface[8] = Cell(WHITE, Point3D(1,-1.9,1), top);


    //BOTTOM SURFACE
    surface[9] = Cell(YELLOW, Point3D(-1,1.9,-1), bottom);
    surface[10] = Cell(YELLOW, Point3D(0,1.9,-1), bottom);
    surface[11] = Cell(YELLOW, Point3D(1,1.9,-1), bottom);
    surface[12] = Cell(YELLOW, Point3D(-1,1.9,0), bottom);
    surface[13] = Cell(YELLOW, Point3D(0,1.9,0), bottom);
    surface[14] = Cell(YELLOW, Point3D(1,1.9,0), bottom);
    surface[15] = Cell(YELLOW, Point3D(-1,1.9,1), bottom);
    surface[16] = Cell(YELLOW, Point3D(0,1.9,1), bottom);
    surface[17] = Cell(YELLOW, Point3D(1,1.9,1), bottom);

    //LEFT SURFACE
    surface[18] = Cell(RED, Point3D(-1.1,-1,-1), left);
    surface[19] = Cell(RED, Point3D(-1.1,0,-1), left);
    surface[20] = Cell(RED, Point3D(-1.1,1,-1), left);
    surface[21] = Cell(RED, Point3D(-1.1,-1,0), left);
    surface[22] = Cell(RED, Point3D(-1.1,0,0), left);
    surface[23] = Cell(RED, Point3D(-1.1,1,0), left);
    surface[24] = Cell(RED, Point3D(-1.1,-1,1), left);
    surface[25] = Cell(RED, Point3D(-1.1,0,1), left);
    surface[26] = Cell(RED, Point3D(-1.1,1,1), left);

    //RIGHT SURFACE
    surface[27] = Cell(ORANGE, Point3D(1.1,-1,-1), right);
    surface[28] = Cell(ORANGE, Point3D(1.1,0,-1), right);
    surface[29] = Cell(ORANGE, Point3D(1.1,1,-1), right);
    surface[30] = Cell(ORANGE, Point3D(1.1,-1,0), right);
    surface[31] = Cell(ORANGE, Point3D(1.1,0,0), right);
    surface[32] = Cell(ORANGE, Point3D(1.1,1,0), right);
    surface[33] = Cell(ORANGE, Point3D(1.1,-1,1), right);
    surface[34] = Cell(ORANGE, Point3D(1.1,0,1), right);
    surface[35] = Cell(ORANGE, Point3D(1.1,1,1), right);

    //BACK SURFACE
    surface[36] = Cell(BLUE, Point3D(-1,-1,-1.1), behind);
    surface[37] = Cell(BLUE, Point3D(0,-1,-1.1), behind);
    surface[38] = Cell(BLUE, Point3D(1,-1,-1.1), behind);
    surface[39] = Cell(BLUE, Point3D(-1,0,-1.1), behind);
    surface[40] = Cell(BLUE, Point3D(0,0,-1.1), behind);
    surface[41] = Cell(BLUE, Point3D(1,0,-1.1), behind);
    surface[42] = Cell(BLUE, Point3D(-1,1,-1.1), behind);
    surface[43] = Cell(BLUE, Point3D(0,1,-1.1), behind);
    surface[44] = Cell(BLUE, Point3D(1,1,-1.1), behind);

    //FRONT SURFACE
    surface[45] = Cell(GREEN, Point3D(-1,-1,1.1), infront);
    surface[46] = Cell(GREEN, Point3D(0,-1,1.1), infront);
    surface[47] = Cell(GREEN, Point3D(1,-1,1.1), infront);
    surface[48] = Cell(GREEN, Point3D(-1,0,1.1), infront);
    surface[49] = Cell(GREEN, Point3D(0,0,1.1), infront);
    surface[50] = Cell(GREEN, Point3D(1,0,1.1), infront);
    surface[51] = Cell(GREEN, Point3D(-1,1,1.1), infront);
    surface[52] = Cell(GREEN, Point3D(0,1,1.1), infront);
    surface[53] = Cell(GREEN, Point3D(1,1,1.1), infront);

}

Cube::Cube(const Cube& c){

}

Cube::~Cube(){
}

Cell* Cube::getSurface() {
    return surface;
}

void Cube::setSurface(Cell _surface[64]){
}

void Cube::drawCube(){
    for (int i = 0; i < 54; i++) {
        surface[i].drawCell();
    }
}

void Cube::rotateAll() {
    glRotatef(angleCube, 1.0f, 1.0f, 1.0f);  // Rotate about (1,1,1)-axis [NEW]
    drawCube();
    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

   angleCube -= 0.45f;
}

void Cube::rotateBottom(){
    /*//DETRANSPOSE FRONT SURFACE - 45~53
    int temp = color[45];
    color[45] = color[51];
    color[51] = color[53];
    color[53] = color[47];
    color[47] = temp;

    temp = color[46];
    color[46] = color[48];
    color[48] = color[52];
    color[52] = color[50];
    color[50] = temp;

    int matTemp[3] = {color[6],color[7],color[8]};
    color[6] = color[44];
    color[7] = color[41];
    color[8] = color[38];

    color[44] = color[11];
    color[41] = color[10];
    color[38] = color[9];

    color[11] = color[27];
    color[10] = color[30];
    color[9] = color[33];

    color[27] = matTemp[0];
    color[30] = matTemp[1];
    color[33] = matTemp[2];*/
    int count = 0;

    glRotatef(angleCube, 0.0f, -1.0f, 0.0f);  // Rotate about (1,1,1)-axis [NEW]
    for (int i = 0; i < 9; i++) {
        surface[i].drawCell();
    }

    surface[45].drawCell();
    surface[46].drawCell();
    surface[47].drawCell();

    surface[33].drawCell();
    surface[30].drawCell();
    surface[27].drawCell();

    surface[38].drawCell();
    surface[37].drawCell();
    surface[36].drawCell();

    surface[18].drawCell();
    surface[21].drawCell();
    surface[24].drawCell();

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

   angleCube -= 0.45f;


}


