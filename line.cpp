#include <iostream>
#include "line.h"
#include "pointset.h"
#include <cmath>
using namespace std;       
       


template <class T>
bool inbetween(T a,T b, T x)
{
    if (a>=x && x>=b) return true;
    if (b>=x && x>=a) return true;
    return false;
}

int gcf(int a, int b)
{
    int r=a%b;
    if (r==0) return b;
    return gcf(b,r);
}

Line::Line(const Point &p1, const Point &p2):Lineabc(p1,p2)
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


    if((sp==l.getsp()&&ep==l.getep()) || (sp==l.getep()&&ep==l.getsp())) return true;
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
    if (p==sp || p==ep) return 0;
    if (perp)
    {
        if (p.getx()>b) return 1;
        if (p.getx()==b) return 0;
        if (p.getx()<b) return -1;
    }
    int l1kn=sp.gety()-p.gety();
    int l1kd=sp.getx()-p.getx();
    if (l1kd==0)
    {
        l1kn=ep.gety()-p.gety();
        l1kd=ep.getx()-p.getx();
    }
    int g=gcf(abs(l1kn),abs(l1kd));
    l1kn=l1kn/g;
    l1kd=l1kd/g;
    int l2kn=sp.gety()-ep.gety();
    int l2kd=sp.getx()-ep.getx();
    g=gcf(abs(l2kn),abs(l2kd));
    l2kn=l2kn/g;
    l2kd=l2kd/g;
    if((l1kn==l2kn && l1kd==l2kd) || (l1kn==-l2kn && l1kd==-l2kd)) return 0;
    if ((k*p.getx()+b)-p.gety()>0) return 1;
    else return -1;
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
}

bool Line::pointonline(const Point &p) const
{
    if (Lineabc::pointonline(p))
        return true;

    if (pointatside(p)!=0) return false;
    if (perp)
        {
            if (inbetween(getsp().gety(),getep().gety(),p.gety())) return true;
            else return false;
        }
    if (inbetween(getsp().getx(),getep().getx(),p.getx())) return true;
    else return false;
}