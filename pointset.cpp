#include <iostream>
#include "pointset.h"
using namespace std;    

Pointset::Pointset(const int cap):capacity(cap),count(0)
{
    p_data=new Point[capacity];
}

Pointset::Pointset(const Pointset & ps)
{
    capacity=ps.capacity;
    count=ps.count;
    p_data=new Point[capacity];
    Point *p=p_data;
    Point *q=ps.p_data;
    for (int i=0;i<count;i++)
    {
        *(p+i)=*(q+i);
    }
}

Pointset::~Pointset()
{
    delete [] p_data;
}  

Pointset & Pointset::operator =(const Pointset &ps)
{  
    if (this==&ps)
    {
        return *this;
    }
    else
    {
        capacity=ps.capacity;
        count=ps.count;
        p_data=new Point[capacity];
        Point *p=p_data;
        Point *q=ps.p_data;
        for (int i=1;i<=count;i++)
        {
            *p=*q;
            p++;
            q++;
        }
        return *this;
    }
}

bool Pointset::append(const Point &p)
{
    for(int i=0;i<count;i++)
        if (p_data[i]==p) return true;
    if (count>=capacity) return false;
    p_data[count++]=p;
    return true;
}

bool Pointset::append(const Line &l)
{
    if (append(l.getsp()))
        {
            if (append(l.getep()))
                return true;
            else return false;
        }
    else return false;
}

ostream & operator << (ostream &os, const Pointset &p)
{
    Point *q=p.p_data;
    for(int i=0;i<p.count;i++)
        os<<q[i]<<endl;
    return os;
};

Pointset & Pointset::remove(const Point & p)
{
    for(int i=0;i<count;i++)
        if (p_data[i]==p) 
        {
            p_data[i]=p_data[count-1];
            count--;
            return *this;
        }
    return *this;
}

bool Pointset::has(const Point &p) const
{
    for(int i=0;i<count;i++)
        if (p_data[i]==p) return true;
    return false;
}
