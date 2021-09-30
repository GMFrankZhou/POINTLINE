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

    private:
        int area;
        int sidelength;
};



#endif