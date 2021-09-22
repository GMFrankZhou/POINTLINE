#include <iostream>
#include "line.h"
#include "pointset.h"
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

bool inbetween(int a,int b, int x)
{
    if (a>=x && x>=b) return true;
    if (b>=x && x>=a) return true;
    return false;
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
        k=double((p1.gety()-p2.gety()))/double((p1.getx()-p2.getx()));
        b=p1.gety()-k*p1.getx();
    }
}

bool Line::operator == (const Line &l) const
{
    if((sp==l.sp&&ep==l.ep) || (sp==l.ep&&ep==l.sp)) return true;
    else return false;
}

int Line::isconnected (const Line &l) const
{
    if (*this==l) return 0;
    if (ep==l.sp) return 1;
    if (ep==l.ep) return -1;
    return 0;
}

void Line::reverse()
{
    Point tp;
    tp=sp;
    sp=ep;
    ep=tp;
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

int Line::pointsatsameside(const Pointset &ps) const
{
    if (ps.getcount()==0) return 0;

    Point firstpoint=*ps.getpoint();
    int fpside=pointatside(firstpoint);
    if (ps.getcount()==1) return fpside;

    int rpside=pointsatsameside(ps-firstpoint);
    if (rpside==-2) return -2;
    if (fpside>=0 && rpside>=0) return (fpside || rpside);
    if (fpside==-rpside) return -2;
    return -1;
};

bool Line::pointonline(const Point &p) const
{
    if (pointatside(p)!=0) return false;
    if (perp)
        {
            if (inbetween(getsp().gety(),getep().gety(),p.gety())) return true;
            else return false;
        }
    if (inbetween(getsp().getx(),getep().getx(),p.getx())) return true;
    else return false;
};