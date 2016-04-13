#ifndef Point3D_H
#define Point3D_H

class Point3D
{
    public:
        Point3D(){};
        Point3D(float _x, float _y, float _z);
        Point3D(const Point3D& p);
        ~Point3D();
        int getX(){return x;};
        int getY(){return y;};
        int getZ(){return z;};


    private:
        float x;
        float y;
        float z;

};
#endif // Point3D_H
