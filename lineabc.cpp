#include <iostream>
#include "lineabc.h"
#include "pointset.h"
using namespace std;       
       
Point Lineabc::getsp() const
{
    return sp;
}

Point Lineabc::getep() const
{
    return ep;
}

ostream & operator << (ostream &os, const Lineabc & l)
{
    return os << "[" << l.sp << " , " << l.ep << "]" << endl;
}


Lineabc::Lineabc(const Point &p1, const Point &p2):sp(p1),ep(p2)
{


}
Lineabc::Lineabc():sp(Point(0,0)),ep(Point(0,0))
{
}

int Lineabc::isconnected (const Lineabc &l) const
{
    if (*this==l) return 0;
    if (ep==l.sp) return 1;
    if (ep==l.ep) return -1;
    return 0;
}

void Lineabc::reverse()
{
    Point tp;
    tp=sp;
    sp=ep;
    ep=tp;
}

bool Lineabc::pointonline(const Point &p) const
{
    if (p==sp ||p==ep )
        return true;
    else
        return false;
}