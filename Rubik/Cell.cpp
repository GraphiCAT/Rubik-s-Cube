#include "Cell.h"

Cell::Cell(const Cell& c){
    color = c.color;
    location = c.location;
    normal = c.normal;
}

Cell::Cell(int _color, Point3D _location, Point3D _normal){
    color = _color;
    location = _location;
    normal = _normal;
}

Cell::~Cell(){
}

int Cell::getColor(){
    return color;
}

void Cell::setColor(int _color){
    color = _color;
}

Point3D Cell::getLocation(){
    return location;
}

void Cell::setLocation(Point3D _location){
    location = _location;
}

Point3D Cell::getNormal(){
    return normal;
}

void Cell::setNormal(Point3D _normal){
    normal = _normal;
}
