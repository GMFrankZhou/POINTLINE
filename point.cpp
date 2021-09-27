#include <iostream>
#include "point.h"
using namespace std;



ostream & operator << (ostream & os, const Point & p)
{
    return os <<"("<<p.x<<","<<p.y<<")";
}


istream & operator >> (istream & is, Point & p)
{
    is>>p.x>>p.y;
    return is;
}


bool operator >> (ifstream &ifs, Point & p)
{
    if ((ifs>>p.x)&&(ifs>>p.y)) return true;
    else return false;
}


int Point::getx() const
{
    return x;
}


int Point::gety() const
{
    return y;
}


bool Point::operator == (const Point &p) const
{
    if (x==p.x && y==p.y) return true;
    return false;
}