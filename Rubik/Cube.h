#ifndef Cube_H
#define Cube_H

#include "Point3D.h"
#include "Cell.h"


class Cube
{
    public :
        Cube();
        Cube(const Cube& c);
        ~Cube();
        Cell* getSurface();
        void setSurface(Cell _surface[64]);
        void drawCube();
        void rotateAll();
        void rotateBottom();

    private :
        Cell surface[54];
        int color[54];
};

#endif // Cube_H
