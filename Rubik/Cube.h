#ifndef Cube_H
#define Cube_H

#include "Point3D.h"
#include "Cell.h"
#include <vector>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

class Cube
{
    public :
        Cube();
        Cube(const Cube& c);
        ~Cube();
        Cell* getSurface();
        void setSurface(Cell _surface[64]);
        void drawCube();
        void handleRotate(int face, int direction);
        void rotateAll(int axis, int direction);


    private :
        void rotateSlice(GLfloat angle,std::vector<int> rotate, Point3D axis);
        std::vector<int> getRotationVector(int face);
        Point3D getRotationAxis(int face);
        void rotateByAxis(GLfloat angle, int axis);
        Cell surface[54];
        GLfloat view[3];

};

#endif // Cube_H
