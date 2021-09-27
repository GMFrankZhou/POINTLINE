#ifndef _LINE_
#define _LINE_

#include <iostream>
#include "point.h"

using std::ostream;

class Pointset;
class Line
{
    public:
        Line():perp(true){}
        Line(const Point &, const Point &);

        bool operator == (const Line &) const;
        int isconnected (const Line &) const;
        int pointatside(const Point &) const;
        bool pointonline(const Point &) const;
        double getk() const {return k;}
        double getb() const {return b;}
        bool isperp() const {return perp;}
        int pointsatsameside(const Pointset &) const;
        void reverse();
        Point getsp()const;
        Point getep()const;

    private:
        Point sp,ep;
        double k,b;
        bool perp;

    friend ostream & operator << (ostream &, const Line &);
};


#endif