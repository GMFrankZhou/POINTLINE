#ifndef _POINT_
#define _POINT_

#include <iostream>
#include <fstream>

using std::ostream;
using std::istream;
using std::ifstream;

class Point
{
    public:
    Point (double xx=0,double yy=0):x(xx),y(yy){}
    
    int getx() const;
    int gety() const;
    bool operator == (const Point &) const;

    private:
        int x,y;

    friend ostream & operator << (ostream &, const Point &);
    friend istream & operator >> (istream &, Point&);
    friend bool operator >> (ifstream &, Point&);
};


#endif