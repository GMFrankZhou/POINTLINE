#include <iostream>
#include "line.h"
using namespace std;       
       
Point Line::getsp() const
{
    return sp;
}

Point Line::getep() const
{
    return ep;
}

ostream & operator << (ostream &os, const Line & l)
{
    return os<<"["<<l.sp<<" , "<<l.ep<<"]"<<endl;
}

Line::Line(const Point &p1, const Point &p2):sp(p1),ep(p2)
{
    if (p1.getx()==p2.getx()) 
    {
        perp=true;
        b=p1.getx();
    }
    else 
    {
        perp=false;
        k=(p1.gety()-p2.gety())/(p1.getx()-p2.getx());
        b=p1.gety()-k*p1.getx();
    }
}

bool Line::operator == (const Line &l) const
{
    if((sp==l.sp&&ep==l.ep) || (sp==l.ep&&ep==l.sp)) return true;
    else return false;
}

bool Line::isconnected (const Line &l) const
{
    if (*this==l) return false;
    if (sp==l.sp||ep==l.ep||sp==l.ep||ep==l.sp) return true;
    return false;
}

int Line::pointatside(const Point &p) const
{
    if (perp)
    {
        if (p.getx()>b) return 1;
        if (p.getx()==b) return 0;
        if (p.getx()<b) return -1;
    }
    else
    {
        if (k*p.getx()+b>p.gety()) return 1;
        if (k*p.getx()+b<p.gety()) return -1;
    }
    return 0;
}