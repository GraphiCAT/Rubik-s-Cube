#include "Cube.h"
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

#include <iostream>
#include <vector>

using namespace std;
GLfloat angleCube = 0.0f;     // Rotational angle for cube [NEW]

Cube::Cube() {
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
    static const int arr[] = {0,1,2,3,4,5,6,7,8,18,21,24,27,30,33,36,37,38,45,46,47};
    vector<int> bottom (arr, arr + sizeof(arr) / sizeof(arr[0]));

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

    // glRotatef(angleCube, 1.0f, 1.0f, 1.0f);  // Rotate about (1,1,1)-axis [NEW]

    for (int i = 0; i < 54; i++) {
        bool cek = false;
        for (int j = 0; j < bottom.size(); j++) {
            if (i == bottom.at(j)) {
                cek = true;
                break;
            }
        }
        if (!cek) {
            surface[i].drawCell();
        }
    }

    glRotatef(angleCube, 0.0f, -1.0f, 0.0f);  // Rotate about (1,1,1)-axis [NEW]
    for (int i = 0; i < bottom.size(); i++) {
        surface[bottom.at(i)].drawCell();
    }

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

    angleCube -= 0.45f;
}

void Cube::rotateTop(){
    static const int arr[] = {9,10,11,12,13,14,15,16,17,20,23,26,29,32,35,42,43,44,51,52,53};
    vector<int> bottom (arr, arr + sizeof(arr) / sizeof(arr[0]));

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

    glRotatef(angleCube, 1.0f, 1.0f, 1.0f);  // Rotate about (1,1,1)-axis [NEW]

    for (int i = 0; i < 54; i++) {
        bool cek = false;
        for (int j = 0; j < bottom.size(); j++) {
            if (i == bottom.at(j)) {
                cek = true;
                break;
            }
        }
        if (!cek) {
            surface[i].drawCell();
        }
    }

    glRotatef(angleCube, 0.0f, -1.0f, 0.0f);  // Rotate about (1,1,1)-axis [NEW]
    for (int i = 0; i < bottom.size(); i++) {
        surface[bottom.at(i)].drawCell();
    }

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

   angleCube -= 0.45f;

}

void Cube::rotateRight(){
    static const int arr[] = {27,28,29,30,31,32,33,34,35,2,5,8,47,50,53,11,14,17,38,41,44};
    vector<int> bottom (arr, arr + sizeof(arr) / sizeof(arr[0]));

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

    glRotatef(angleCube, 1.0f, 1.0f, 1.0f);  // Rotate about (1,1,1)-axis [NEW]


    for (int i = 0; i < 54; i++) {
        bool cek = false;
        for (int j = 0; j < bottom.size(); j++) {
            if (i == bottom.at(j)) {
                cek = true;
                break;
            }
        }
        if (!cek) {
            surface[i].drawCell();
        }
    }

    glRotatef(angleCube, 1.0f, 0.0f, 0.0f);  // Rotate about (1,1,1)-axis [NEW]
    for (int i = 0; i < bottom.size(); i++) {
        surface[bottom.at(i)].drawCell();
    }

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

   angleCube -= 0.45f;

}

void Cube::rotateLeft(){

    static const int arr[] = {18,19,20,21,22,23,24,25,26,0,3,6,45,48,51,9,12,15,36,39,42};
    vector<int> bottom (arr, arr + sizeof(arr) / sizeof(arr[0]));

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

    glRotatef(angleCube, 1.0f, 1.0f, 1.0f);  // Rotate about (1,1,1)-axis [NEW]


    for (int i = 0; i < 54; i++) {
        bool cek = false;
        for (int j = 0; j < bottom.size(); j++) {
            if (i == bottom.at(j)) {
                cek = true;
                break;
            }
        }
        if (!cek) {
            surface[i].drawCell();
        }
    }

    glRotatef(angleCube, 1.0f, 0.0f, 0.0f);  // Rotate about (1,1,1)-axis [NEW]
    for (int i = 0; i < bottom.size(); i++) {
        surface[bottom.at(i)].drawCell();
    }

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

   angleCube -= 0.45f;

}

void Cube::rotateFront(){

    static const int arr[] = {45,46,47,48,49,50,51,52,53,33,34,35,24,25,26,6,7,8,15,16,17};
    vector<int> bottom (arr, arr + sizeof(arr) / sizeof(arr[0]));

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

    glRotatef(angleCube, 1.0f, 1.0f, 1.0f);  // Rotate about (1,1,1)-axis [NEW]


    for (int i = 0; i < 54; i++) {
        bool cek = false;
        for (int j = 0; j < bottom.size(); j++) {
            if (i == bottom.at(j)) {
                cek = true;
                break;
            }
        }
        if (!cek) {
            surface[i].drawCell();
        }
    }

    glRotatef(angleCube, 0.0f, 0.0f, 1.0f);  // Rotate about (1,1,1)-axis [NEW]
    for (int i = 0; i < bottom.size(); i++) {
        surface[bottom.at(i)].drawCell();
    }

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

   angleCube -= 0.45f;

}

void Cube::rotateBack(){

    static const int arr[] = {36,37,38,39,40,41,42,43,44,27,28,29,18,19,20,0,1,2,9,10,11};
    vector<int> bottom (arr, arr + sizeof(arr) / sizeof(arr[0]));

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

    glRotatef(angleCube, 1.0f, 1.0f, 1.0f);  // Rotate about (1,1,1)-axis [NEW]


    for (int i = 0; i < 54; i++) {
        bool cek = false;
        for (int j = 0; j < bottom.size(); j++) {
            if (i == bottom.at(j)) {
                cek = true;
                break;
            }
        }
        if (!cek) {
            surface[i].drawCell();
        }
    }

    glRotatef(angleCube, 0.0f, 0.0f, 1.0f);  // Rotate about (1,1,1)-axis [NEW]
    for (int i = 0; i < bottom.size(); i++) {
        surface[bottom.at(i)].drawCell();
    }

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

   angleCube -= 0.45f;

}


