#ifndef Cell_H
#define Cell_H

#include "Point3D.h"
#define RED 0
#define GREEN 1
#define WHITE 2
#define BLUE 3
#define ORANGE 4
#define YELLOW 5


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


    private :
        int color;
        Point3D location;
        Point3D normal;
};

#endif // Cell_H
