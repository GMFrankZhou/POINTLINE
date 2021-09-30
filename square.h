#ifndef _SQUARE_
#define _SQUARE_
#include "polygon.h"

class Square:public Polygon
{
    public:
        Square() : Polygon() 
        { 
            area = 0;
            sidelength = 0;
        }
        Square(const Point &, int);
        virtual int getarea() const;

    protected:
        int area;
        int sidelength;
};

class Squaresq:public Square
{
    public:
        Squaresq() : Square(){};
        Squaresq(const Point &, int);
        virtual   int getarea() const;
};



#endif