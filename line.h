#ifndef _LINE_
#define _LINE_

#include <iostream>
#include "point.h"
using namespace std;

class Line
{
    public:
        Line():perp(true){}
        Line(const Point &, const Point &);

        bool operator == (const Line &) const;
        bool isconnected (const Line &) const;
      //  bool pointatside(Point &) const;
        Point getsp()const;
        Point getep()const;

    private:
        Point sp,ep;
        double k,b;
        bool perp;

    friend ostream & operator << (ostream &, const Line &);
};


#endif