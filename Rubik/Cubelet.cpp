#include "Cubelet.h"
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

Cubelet::Cubelet(){
    for (int i = 0; i < 6; i++) {
        color[i] = DEFAULT;
    }
};

Cubelet::Cubelet(int _color[], Point3D _position){
    for (int i = 0; i < 6; i++) {
        color[i] = _color[i];

    }
    position = _position;
}

Cubelet::Cubelet(const Cubelet& c){

}

Cubelet::~Cubelet(){

}

void Cubelet::setPosition(Point3D _position){
    position = _position;
}

Point3D Cubelet::getPosition(){
    return position;
}

void Cubelet::setSize(float _size) {
    size = _size;
}

float Cubelet::getSize(){
    return size;
}

void Cubelet::moveCubelet(float x, float y, float z) {
    position.setX(position.getX()+x);
    position.setY(position.getY()+y);
    position.setZ(position.getZ()+z);
}

void Cubelet::rotateCubelet(Point3D center, float radian){

}

void Cubelet::printCubelet(){

}

void Cubelet::drawCubelet(){
    float x = position.getX();
    float y = position.getY();
    float z = position.getZ();

    glBegin(GL_QUADS);		// Draw The Cube Using quads
    glColor3f(1.0f,0.0f,0.0f);	// Color Red
    glVertex3f(x+size, y+size, z-size);	// Top Right Of The Quad (Top)
    glVertex3f(x-size, y+size, z-size);	// Top Left Of The Quad (Top)
    glVertex3f(x-size, y+size, z+size);	// Bottom Left Of The Quad (Top)
    glVertex3f(x+size, y+size, z+size);	// Bottom Right Of The Quad (Top)
    glColor3f(1.0f,0.5f,0.0f);	// Color Orange
    glVertex3f(x+size, y-size, z+size);	// Top Right Of The Quad (Bottom)
    glVertex3f(x-size, y-size, z+size);	// Top Left Of The Quad (Bottom)
    glVertex3f(x-size, y-size, z-size);	// Bottom Left Of The Quad (Bottom)
    glVertex3f(x+size, y-size, z-size);	// Bottom Right Of The Quad (Bottom)
    glColor3f(1.0f,1.0f,1.0f);	// Color White
    glVertex3f(x+size, y+size, z+size);	// Top Right Of The Quad (Front)
    glVertex3f(x-size, y+size, z+size);	// Top Left Of The Quad (Front)
    glVertex3f(x-size, y-size, z+size);	// Bottom Left Of The Quad (Front)
    glVertex3f(x+size, y-size, z+size);	// Bottom Right Of The Quad (Front)
    glColor3f(1.0f,1.0f,0.0f);	// Color Yellow
    glVertex3f(x+size, y-size, z-size);	// Top Right Of The Quad (Back)
    glVertex3f(x-size, y-size, z-size);	// Top Left Of The Quad (Back)
    glVertex3f(x-size, y+size, z-size);	// Bottom Left Of The Quad (Back)
    glVertex3f(x+size, y+size, z-size);	// Bottom Right Of The Quad (Back)
    glColor3f(0.0f,0.0f,1.0f);	// Color Blue
    glVertex3f(x-size, y+size, z+size);	// Top Right Of The Quad (Left)
    glVertex3f(x-size, y+size, z-size);	// Top Left Of The Quad (Left)
    glVertex3f(x-size, y-size, z-size);	// Bottom Left Of The Quad (Left)
    glVertex3f(x-size, y-size, z+size);	// Bottom Right Of The Quad (Left)
    glColor3f(0.0f,1.0f,0.0f);	// Color Green
    glVertex3f(x+size, y+size, z-size);	// Top Right Of The Quad (Right)
    glVertex3f(x+size, y+size, z+size);	// Top Left Of The Quad (Right)
    glVertex3f(x+size, y-size, z+size);	// Bottom Left Of The Quad (Right)
    glVertex3f(x+size, y-size, z-size);	// Bottom Right Of The Quad (Right)
  glEnd();			// End Drawing The Cube
}
