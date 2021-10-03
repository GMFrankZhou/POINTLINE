#ifndef _LINEABC_
#define _LINEABC_

#include <iostream>
#include "point.h"

using std::ostream;

class Pointset;
class Lineabc
{
    public:
        Lineabc(const Point &, const Point &);
        Lineabc();
        virtual bool operator==(const Lineabc &) const {return false;}
        int isconnected (const Lineabc &) const;
        virtual int pointatside(const Point &) const=0;
        virtual bool pointonline(const Point &) const;
        virtual int pointsatsameside(const Pointset &) const = 0;
        void reverse();
        Point getsp()const;
        Point getep()const;
    protected:
        Point sp,ep;
    friend ostream & operator << (ostream &, const Lineabc &);
};


#endif