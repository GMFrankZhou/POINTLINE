#ifndef _POINT_
#define _POINT_

#include <iostream>

using std::ostream;
using std::istream;


class Point
{
    public:
    Point (int xx=0,int yy=0):x(xx),y(yy){}
    
    int getx() const;
    int gety() const;
    bool operator == (const Point &) const;

    private:
        int x,y;

    friend ostream & operator << (ostream &, const Point &);
    friend istream & operator >> (istream &, Point&);
};
#endif