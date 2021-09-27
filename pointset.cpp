#include <iostream>
#include "pointset.h"
#include "point.h"
#include "line.h"
#include "polygon.h"
using namespace std;    



Pointset::Pointset():count(0)
{
    p_data=NULL;
}

Pointset::Pointset(const Pointset & ps)
{
    count=ps.count;
    if (count!=0)
    {
        p_data=new Point[count];
        Point *p=p_data;
        Point *q=ps.p_data;
        for (int i=0;i<count;i++)
        {
            *(p+i)=*(q+i);
        }
    }
    else
        p_data=NULL;
}

Pointset::Pointset(const Line& l):count(2)
{
    p_data=new Point[count];
    p_data[0]=l.getsp();
    p_data[1]=l.getep();
}

Pointset::Pointset(const Point &p):count(1)
{
    p_data=new Point[count];
    p_data[0]=p;
}

Pointset::Pointset(const Polygon &pg)
{
    Pointset ps=pg.getpoints();
    count=ps.count;
    if (count>0)
    {
        p_data=new Point[count];
        Point *p=p_data;
        Point *q=ps.p_data;
        for (int i=0;i<count;i++)
        {
            *(p+i)=*(q+i);
        }
    }
    else
        p_data=NULL;
}

Pointset::~Pointset()
{
    if (p_data) delete [] p_data;
}  

Pointset & Pointset::operator =(const Pointset &ps)
{  
    if (this==&ps)
    {
        return *this;
    }
    else
    {
        count=ps.count;
        if (p_data) delete[] p_data;
        p_data=new Point[count];
        for (int i=0;i<count;i++)
            p_data[i]=ps.p_data[i];
        return *this;
    }
}

Pointset & Pointset::append(const Point &p)
{

    for(int i=0;i<count;i++)
        if (p_data[i]==p) return *this;
    
    Pointset tempps(*this);

    if (p_data) delete[] p_data;
    p_data=new Point[count+1];
    for (int i=0;i<count;i++)
        p_data[i]=tempps.p_data[i];
    p_data[count++]=p;
    return *this;
}

Pointset & Pointset::append(const Line &l)
{
    return append(l.getsp()).append(l.getep());
}

ostream & operator << (ostream &os, const Pointset &p)
{
    Point *q=p.p_data;
    os<<endl;
    for(int i=0;i<p.count;i++)
        os<<q[i]<<endl;
    return os;
};

bool Pointset::has(const Point &p) const
{
    for(int i=0;i<count;i++)
        if (p_data[i]==p) return true;
    return false;
}

istream & operator >> (istream &is, Pointset &ps)
{
    cout <<"Enter the number of points: ";
    int n;
    is >>n;
    if (n>=1)
    {
        ps=Pointset();
        for (int i=1;i<=n;i++)
        {
            cout <<"Enter point "<<i<<": ";
            Point p;
            is >>p;
            ps.append(p);
        }
    }
    else cout <<"Nothing added";
    return is;
}

void operator >> (ifstream &ifs, Pointset &ps)
{
    ps.clear();
    Point p;
    bool e=false;
    while (!e)
        if(ifs>>p) ps.append(p);
        else e=true;
    cout <<endl<<ps.getcount()<<" Point(s) have been read:"<<endl;
    cout <<ps;
}


Pointset Pointset::operator -(const Point &p) const
{
    Pointset ps;
    for (int i=0;i<count;i++)
        if (!(p_data[i]==p)) ps.append(p_data[i]);
    return ps;
}

void Pointset::clear()
{
    if (p_data) delete[] p_data;
    p_data=NULL;
    count=0;
}

Polygon Pointset::findboundary() const
{
    if (count<=1) 
    {
        Polygon pg;
        return pg;
    }
    if (count==2)
    {
        Polygon pg(*this);
        return pg;
    }
    Point p=*getpoint();
    Pointset ps=*this-p;
    Polygon pg=ps.findboundary()+p;
    return pg;
}