#ifndef _LINE_
#define _LINE_

#include <iostream>
#include "point.h"
#include "lineabc.h"

using std::ostream;

class Pointset;
class Line:public Lineabc
{
    public:
        Line():Lineabc(),perp(true){}
        Line(const Point &, const Point &);

        virtual bool operator == (const Line &) const;
        int isconnected (const Line &) const;
        virtual int pointatside(const Point &) const;
        virtual bool pointonline(const Point &) const;
        double getk() const {return k;}
        double getb() const {return b;}
        bool isperp() const {return perp;}
        virtual int pointsatsameside(const Pointset &) const;
        void reverse();

    private:
        double k,b;
        bool perp;
};


#endif