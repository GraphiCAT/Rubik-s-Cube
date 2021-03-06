
#include "Cube5.h"

#include <iostream>
#include <vector>
#include <algorithm>

#define CLOCKWISE 0
#define COUNTER_CLOCKWISE -1
#define TOP 1
#define BOTTOM 2
#define LEFT 3
#define RIGHT 4
#define BACK 5
#define FRONT 6
#define MIDDLEX 7
#define MIDDLEY 8
#define MIDDLEZ 9
#define ALLX 10
#define ALLY 11
#define ALLZ 12

using namespace std;

Cube5::Cube5(){
    Point3D top(0,-1,0);
    Point3D bottom(0,1,0);
    Point3D right(1,0,0);
    Point3D left(-1,0,0);
    Point3D behind(0,0,-1);
    Point3D infront(0,0,1);

    //TOP SURFACE
    surface[0] = Cell(WHITE, Point3D(-2,-2.9,-2), top);
    surface[1] = Cell(WHITE, Point3D(-1,-2.9,-2), top);
    surface[2] = Cell(WHITE, Point3D(0,-2.9,-2), top);
    surface[3] = Cell(WHITE, Point3D(1,-2.9,-2), top);
    surface[4] = Cell(WHITE, Point3D(2,-2.9,-2), top);
    surface[5] = Cell(WHITE, Point3D(-2,-2.9,-1), top);
    surface[6] = Cell(WHITE, Point3D(-1,-2.9,-1), top);
    surface[7] = Cell(WHITE, Point3D(0,-2.9,-1), top);
    surface[8] = Cell(WHITE, Point3D(1,-2.9,-1), top);
    surface[9] = Cell(WHITE, Point3D(2,-2.9,-1), top);
    surface[10] = Cell(WHITE, Point3D(-2,-2.9,0), top);
    surface[11] = Cell(WHITE, Point3D(-1,-2.9,0), top);
    surface[12] = Cell(WHITE, Point3D(0,-2.9,0), top);
    surface[13] = Cell(WHITE, Point3D(1,-2.9,0), top);
    surface[14] = Cell(WHITE, Point3D(2,-2.9,0), top);
    surface[15] = Cell(WHITE, Point3D(-2,-2.9,1), top);
    surface[16] = Cell(WHITE, Point3D(-1,-2.9,1), top);
    surface[17] = Cell(WHITE, Point3D(0,-2.9,1), top);
    surface[18] = Cell(WHITE, Point3D(1,-2.9,1), top);
    surface[19] = Cell(WHITE, Point3D(2,-2.9,1), top);
    surface[20] = Cell(WHITE, Point3D(-2,-2.9,2), top);
    surface[21] = Cell(WHITE, Point3D(-1,-2.9,2), top);
    surface[22] = Cell(WHITE, Point3D(0,-2.9,2), top);
    surface[23] = Cell(WHITE, Point3D(1,-2.9,2), top);
    surface[24] = Cell(WHITE, Point3D(2,-2.9,2), top);



    //BOTTOM SURFACE
    surface[25] = Cell(YELLOW, Point3D(-2,2.9,-2), bottom);
    surface[26] = Cell(YELLOW, Point3D(-1,2.9,-2), bottom);
    surface[27] = Cell(YELLOW, Point3D(0,2.9,-2), bottom);
    surface[28] = Cell(YELLOW, Point3D(1,2.9,-2), bottom);
    surface[29] = Cell(YELLOW, Point3D(2,2.9,-2), bottom);
    surface[30] = Cell(YELLOW, Point3D(-2,2.9,-1), bottom);
    surface[31] = Cell(YELLOW, Point3D(-1,2.9,-1), bottom);
    surface[32] = Cell(YELLOW, Point3D(0,2.9,-1), bottom);
    surface[33] = Cell(YELLOW, Point3D(1,2.9,-1), bottom);
    surface[34] = Cell(YELLOW, Point3D(2,2.9,-1), bottom);
    surface[35] = Cell(YELLOW, Point3D(-2,2.9,0), bottom);
    surface[36] = Cell(YELLOW, Point3D(-1,2.9,0), bottom);
    surface[37] = Cell(YELLOW, Point3D(0,2.9,0), bottom);
    surface[38] = Cell(YELLOW, Point3D(1,2.9,0), bottom);
    surface[39] = Cell(YELLOW, Point3D(2,2.9,0), bottom);
    surface[40] = Cell(YELLOW, Point3D(-2,2.9,1), bottom);
    surface[41] = Cell(YELLOW, Point3D(-1,2.9,1), bottom);
    surface[42] = Cell(YELLOW, Point3D(0,2.9,1), bottom);
    surface[43] = Cell(YELLOW, Point3D(1,2.9,1), bottom);
    surface[44] = Cell(YELLOW, Point3D(2,2.9,1), bottom);
    surface[45] = Cell(YELLOW, Point3D(-2,2.9,2), bottom);
    surface[46] = Cell(YELLOW, Point3D(-1,2.9,2), bottom);
    surface[47] = Cell(YELLOW, Point3D(0,2.9,2), bottom);
    surface[48] = Cell(YELLOW, Point3D(1,2.9,2), bottom);
    surface[49] = Cell(YELLOW, Point3D(2,2.9,2), bottom);

    //LEFT SURFACE
    surface[50] = Cell(RED, Point3D(-2.1,-2,-2), left);
    surface[51] = Cell(RED, Point3D(-2.1,-1,-2), left);
    surface[52] = Cell(RED, Point3D(-2.1,0,-2), left);
    surface[53] = Cell(RED, Point3D(-2.1,1,-2), left);
    surface[54] = Cell(RED, Point3D(-2.1,2,-2), left);
    surface[55] = Cell(RED, Point3D(-2.1,-2,-1), left);
    surface[56] = Cell(RED, Point3D(-2.1,-1,-1), left);
    surface[57] = Cell(RED, Point3D(-2.1,0,-1), left);
    surface[58] = Cell(RED, Point3D(-2.1,1,-1), left);
    surface[59] = Cell(RED, Point3D(-2.1,2,-1), left);
    surface[60] = Cell(RED, Point3D(-2.1,-2,0), left);
    surface[61] = Cell(RED, Point3D(-2.1,-1,0), left);
    surface[62] = Cell(RED, Point3D(-2.1,0,0), left);
    surface[63] = Cell(RED, Point3D(-2.1,1,0), left);
    surface[64] = Cell(RED, Point3D(-2.1,2,0), left);
    surface[65] = Cell(RED, Point3D(-2.1,-2,1), left);
    surface[66] = Cell(RED, Point3D(-2.1,-1,1), left);
    surface[67] = Cell(RED, Point3D(-2.1,0,1), left);
    surface[68] = Cell(RED, Point3D(-2.1,1,1), left);
    surface[69] = Cell(RED, Point3D(-2.1,2,1), left);
    surface[70] = Cell(RED, Point3D(-2.1,-2,2), left);
    surface[71] = Cell(RED, Point3D(-2.1,-1,2), left);
    surface[72] = Cell(RED, Point3D(-2.1,0,2), left);
    surface[73] = Cell(RED, Point3D(-2.1,1,2), left);
    surface[74] = Cell(RED, Point3D(-2.1,2,2), left);


    //RIGHT SURFACE
    surface[75] = Cell(ORANGE, Point3D(2.1,-2,-2), right);
    surface[76] = Cell(ORANGE, Point3D(2.1,-1,-2), right);
    surface[77] = Cell(ORANGE, Point3D(2.1,0,-2), right);
    surface[78] = Cell(ORANGE, Point3D(2.1,1,-2), right);
    surface[79] = Cell(ORANGE, Point3D(2.1,2,-2), right);
    surface[80] = Cell(ORANGE, Point3D(2.1,-2,-1), right);
    surface[81] = Cell(ORANGE, Point3D(2.1,-1,-1), right);
    surface[82] = Cell(ORANGE, Point3D(2.1,0,-1), right);
    surface[83] = Cell(ORANGE, Point3D(2.1,1,-1), right);
    surface[84] = Cell(ORANGE, Point3D(2.1,2,-1), right);
    surface[85] = Cell(ORANGE, Point3D(2.1,-2,0), right);
    surface[86] = Cell(ORANGE, Point3D(2.1,-1,0), right);
    surface[87] = Cell(ORANGE, Point3D(2.1,0,0), right);
    surface[88] = Cell(ORANGE, Point3D(2.1,1,0), right);
    surface[89] = Cell(ORANGE, Point3D(2.1,2,0), right);
    surface[90] = Cell(ORANGE, Point3D(2.1,-2,1), right);
    surface[91] = Cell(ORANGE, Point3D(2.1,-1,1), right);
    surface[92] = Cell(ORANGE, Point3D(2.1,0,1), right);
    surface[93] = Cell(ORANGE, Point3D(2.1,1,1), right);
    surface[94] = Cell(ORANGE, Point3D(2.1,2,1), right);
    surface[95] = Cell(ORANGE, Point3D(2.1,-2,2), right);
    surface[96] = Cell(ORANGE, Point3D(2.1,-1,2), right);
    surface[97] = Cell(ORANGE, Point3D(2.1,0,2), right);
    surface[98] = Cell(ORANGE, Point3D(2.1,1,2), right);
    surface[99] = Cell(ORANGE, Point3D(2.1,2,2), right);


    //BACK SURFACE
    surface[100] = Cell(BLUE, Point3D(-2,-2,-2.1), behind);
    surface[101] = Cell(BLUE, Point3D(-1,-2,-2.1), behind);
    surface[102] = Cell(BLUE, Point3D(0,-2,-2.1), behind);
    surface[103] = Cell(BLUE, Point3D(1,-2,-2.1), behind);
    surface[104] = Cell(BLUE, Point3D(2,-2,-2.1), behind);
    surface[105] = Cell(BLUE, Point3D(-2,-1,-2.1), behind);
    surface[106] = Cell(BLUE, Point3D(-1,-1,-2.1), behind);
    surface[107] = Cell(BLUE, Point3D(0,-1,-2.1), behind);
    surface[108] = Cell(BLUE, Point3D(1,-1,-2.1), behind);
    surface[109] = Cell(BLUE, Point3D(2,-1,-2.1), behind);
    surface[110] = Cell(BLUE, Point3D(-2,0,-2.1), behind);
    surface[111] = Cell(BLUE, Point3D(-1,0,-2.1), behind);
    surface[112] = Cell(BLUE, Point3D(0,0,-2.1), behind);
    surface[113] = Cell(BLUE, Point3D(1,0,-2.1), behind);
    surface[114] = Cell(BLUE, Point3D(2,0,-2.1), behind);
    surface[115] = Cell(BLUE, Point3D(-2,1,-2.1), behind);
    surface[116] = Cell(BLUE, Point3D(-1,1,-2.1), behind);
    surface[117] = Cell(BLUE, Point3D(0,1,-2.1), behind);
    surface[118] = Cell(BLUE, Point3D(1,1,-2.1), behind);
    surface[119] = Cell(BLUE, Point3D(2,1,-2.1), behind);
    surface[120] = Cell(BLUE, Point3D(-2,2,-2.1), behind);
    surface[121] = Cell(BLUE, Point3D(-1,2,-2.1), behind);
    surface[122] = Cell(BLUE, Point3D(0,2,-2.1), behind);
    surface[123] = Cell(BLUE, Point3D(1,2,-2.1), behind);
    surface[124] = Cell(BLUE, Point3D(2,2,-2.1), behind);

    //FRONT SURFACE
    surface[125] = Cell(GREEN, Point3D(-2,-2,2.1), infront);
    surface[126] = Cell(GREEN, Point3D(-1,-2,2.1), infront);
    surface[127] = Cell(GREEN, Point3D(0,-2,2.1), infront);
    surface[128] = Cell(GREEN, Point3D(1,-2,2.1), infront);
    surface[129] = Cell(GREEN, Point3D(2,-2,2.1), infront);
    surface[130] = Cell(GREEN, Point3D(-2,-1,2.1), infront);
    surface[131] = Cell(GREEN, Point3D(-1,-1,2.1), infront);
    surface[132] = Cell(GREEN, Point3D(0,-1,2.1), infront);
    surface[133] = Cell(GREEN, Point3D(1,-1,2.1), infront);
    surface[134] = Cell(GREEN, Point3D(2,-1,2.1), infront);
    surface[135] = Cell(GREEN, Point3D(-2,0,2.1), infront);
    surface[136] = Cell(GREEN, Point3D(-1,0,2.1), infront);
    surface[137] = Cell(GREEN, Point3D(0,0,2.1), infront);
    surface[138] = Cell(GREEN, Point3D(1,0,2.1), infront);
    surface[139] = Cell(GREEN, Point3D(2,0,2.1), infront);
    surface[140] = Cell(GREEN, Point3D(-2,1,2.1), infront);
    surface[141] = Cell(GREEN, Point3D(-1,1,2.1), infront);
    surface[142] = Cell(GREEN, Point3D(0,1,2.1), infront);
    surface[143] = Cell(GREEN, Point3D(1,1,2.1), infront);
    surface[144] = Cell(GREEN, Point3D(2,1,2.1), infront);
    surface[145] = Cell(GREEN, Point3D(-2,2,2.1), infront);
    surface[146] = Cell(GREEN, Point3D(-1,2,2.1), infront);
    surface[147] = Cell(GREEN, Point3D(0,2,2.1), infront);
    surface[148] = Cell(GREEN, Point3D(1,2,2.1), infront);
    surface[149] = Cell(GREEN, Point3D(2,2,2.1), infront);
}

Cube5::Cube5(const Cube5& c){

}

Cube5::~Cube5(){
}

Cell* Cube5::getSurface(){
    return surface;
}

void Cube5::setSurface(Cell _surface[150]){

}

void Cube5::drawCube(){
    for (int i = 0; i < 150; i++) {
        surface[i].drawCell();
    }
}

void Cube5::rotateAll(int axis, int direction) {
  float degrees_per_frame = 5.0f;
  int frames = 45.0f/degrees_per_frame;

  if (direction==CLOCKWISE) {
    for (int i=0;i<=frames;i++) {
      rotateByAxis(degrees_per_frame,axis);
      Sleep(100);
    }
  } else {
    for (int i=0;i<=frames;i++) {
      rotateByAxis(-degrees_per_frame,axis);
      Sleep(100);
    }
  }
}

void Cube5::rotateByAxis(GLfloat angle, int axis) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

  switch (axis) {
    case ALLX:
      glRotatef(angle,1.0f,0.0f,0.0f);
      break;
    case ALLY:
      glRotatef(angle,0.0f,1.0f,0.0f);
      break;
    case ALLZ:
      glRotatef(angle,0.0f,0.0f,1.0f);
      break;
    default:
      break;
  }
  drawCube();

  glutSwapBuffers();
}

void Cube5::handleRotate(int face, int direction) {
  float degrees_per_frame = 10.0f;
  int frames = 90.0f/degrees_per_frame;
  GLfloat angleCube = 0.0f;

  if (direction==CLOCKWISE) {
    for (int i=0;i<=frames;i++) {
      rotateSlice(angleCube,getRotationVector(face),getRotationAxis(face));
      angleCube += degrees_per_frame;
      Sleep(100);
    }
  } else {
    for (int i=0;i<=frames;i++) {
      rotateSlice(angleCube,getRotationVector(face),getRotationAxis(face));
      angleCube -= degrees_per_frame;
      Sleep(100);
    }
  }
}

vector<int> Cube5::getRotationVector(int face) {
  switch (face) {
    case BOTTOM: {
      int arr[] = {0,1,2,3,4,5,6,7,8,18,21,24,36,37,38,27,30,33,45,46,47}; //clockwise
      return vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));
      } break;
    case TOP: {
      int arr[] = {9,10,11,12,13,14,15,16,17,20,23,26,42,43,44,29,32,35,51,52,53}; //clockwise
      return vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));
      } break;
    case RIGHT: {
      int arr[] = {27,28,29,30,31,32,33,34,35,2,5,8,38,41,44,11,14,17,47,50,53}; //clockwise
      return vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));
      } break;
    case LEFT: {
      int arr[] = {18,19,20,21,22,23,24,25,26,0,3,6,36,39,42,9,12,15,45,48,51}; //clockwise
      return vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));
      } break;
    case BACK: {
      int arr[] = {36,37,38,39,40,41,42,43,44,27,28,29,9,10,11,18,19,20,0,1,2}; //clockwise
      return vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));
      } break;
    case FRONT: {
      int arr[] = {45,46,47,48,49,50,51,52,53,24,25,26,33,34,35,15,16,17,6,7,8}; //clockwise
      return vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));
      } break;
    case MIDDLEY: {
      int arr[] = {48,49,50,19,22,25,39,40,41,28,31,34}; //clockwise
      return vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));
      } break;
    case MIDDLEX: {
      int arr[] = {1,4,7,37,40,43,10,13,16,46,49,52}; // clockwise
      return vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));
      } break;
    case MIDDLEZ: {
      int arr[] = {3,4,5,21,22,23,12,13,14,30,31,32}; //clockwise
      return vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));
      } break;
    default:
      break;
  }
  return vector<int>();
}

Point3D Cube5::getRotationAxis(int face) {
  switch (face) {
    case BOTTOM:
    case TOP:
    case MIDDLEY:
      return Point3D(0.0,1.0,0.0);
      break;
    case RIGHT:
    case LEFT:
    case MIDDLEX:
      return Point3D(1.0,0.0,0.0);
      break;
    case BACK:
    case FRONT:
    case MIDDLEZ:
      return Point3D(0.0,0.0,-1.0);
      break;
    default:
      break;
  }
  return Point3D();
}

void Cube5::rotateSlice(GLfloat angle, vector<int> rotate, Point3D axis) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

    glPushMatrix();

    //Draw cube unrotated
    for (int i = 0; i < 54; i++) {
        if(std::find(rotate.begin(), rotate.end(), i) == rotate.end()) {
            surface[i].drawCell();
        }
    }

    glPopMatrix();

    glPushMatrix();
    //Rotate around axis
    glRotatef(angle,(GLfloat)axis.getX(),(GLfloat)axis.getY(),(GLfloat)axis.getZ());

    //Draw rotated
    for (int i = 0; i < rotate.size(); i++) {
        surface[rotate.at(i)].drawCell();
    }

    glPopMatrix();

    glutSwapBuffers();
}
