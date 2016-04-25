#ifndef Cell_H
#define Cell_H

#include "Point3D.h"
#define RED 0
#define GREEN 1
#define WHITE 2
#define BLUE 3
#define ORANGE 4
#define YELLOW 5

#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdio.h>


class Cell
{
    public :
        Cell(){};
        Cell(int _color, Point3D _location, Point3D _normal);
        Cell(const Cell& c);
        ~Cell();
        int getColor();
        void setColor(int _color);
        Point3D getLocation();
        void setLocation(Point3D _location);
        Point3D getNormal();
        void setNormal(Point3D _normal);
        void drawCell();
        void setColor();
        int getFace();
        GLuint LoadTextureRAW( const char * filename, int wrap );
        void FreeTexture( GLuint texture );

    private :
        int color;
        Point3D location;
        Point3D normal;
        GLuint cellTexture;
};

#endif // Cell_H
