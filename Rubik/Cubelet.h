#ifndef Cubelet_H
#define Cubelet_H

#include "Point3D.h"
#define DEFAULT 0;
#define RED 1;
#define GREEN 2;
#define WHITE 3;
#define BLUE 4;
#define ORANGE 5;
#define YELLOW 6;

class Cubelet
{
    public :
        Cubelet();
        Cubelet(int _color[], Point3D _position);
        Cubelet(const Cubelet& c);
        ~Cubelet();
        void setPosition(Point3D _position);
        Point3D getPosition();
        void setSize(float _size);
        float getSize();
        void scaleCubelet(int num);
        void moveCubelet(float x, float y, float z);
        void rotateCubelet(Point3D center, float radian);
        void printCubelet();
        void drawCubelet();


    private :
        int color[6];
        Point3D position;
        int size;



};

#endif // Cubelet_H

