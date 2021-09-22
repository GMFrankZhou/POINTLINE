#include <iostream>
#include "polygon.h"
#include "line.h"
#include "pointset.h"

using namespace std;

Polygon::Polygon(const Point &p1, const Point &p2, const Point &p3)
{
        m_count=3;
        m_line=new Line[3];
        m_line[0]=Line(p1,p2);
        m_line[1]=Line(p2,p3);
        m_line[2]=Line(p3,p1);
        m_ps=Pointset(m_line[0]).append(p3);
        sort();
}

Polygon::Polygon(const Pointset &ps)
{
    int psc=ps.getcount();
    if (psc<=1) 
    {
        m_line=NULL;
        m_ps=Pointset();
        return;
    }
    if (psc==2)
    {
        m_count=1;
        m_line=new Line[1];
        m_line[0]=Line(*(ps.getpoint()),*(ps-*(ps.getpoint())).getpoint());
        m_ps=ps;
        return;
    }
    if (psc==3)
    {
        m_count=3;
        m_line=new Line[3];
        m_line[0]=Line(*(ps.getpoint()),*(ps.getpoint()+1));
        m_line[1]=Line(*(ps.getpoint()+2),*(ps.getpoint()+1));
        m_line[2]=Line(*(ps.getpoint()),*(ps.getpoint()+2));
        m_ps=ps;
        sort();
        return;
    }
    if (psc>3)
    {
        m_count=3;
        m_line=new Line[3];
        m_line[0]=Line(*(ps.getpoint()),*(ps.getpoint()+1));
        m_line[1]=Line(*(ps.getpoint()+2),*(ps.getpoint()+1));
        m_line[2]=Line(*(ps.getpoint()),*(ps.getpoint()+2));
        m_ps=ps;
        sort();
        for (int i=3;i<psc;i++)
            append(*(ps.getpoint()+i));
    }
}

Polygon::~Polygon()
{
    delete [] m_line;
}


Polygon::Polygon(const Polygon &pg)
{
    m_count=pg.m_count;
    m_line=new Line[m_count];
    for (int i=0;i<m_count;i++)
        m_line[i]=pg.m_line[i];
    m_ps=pg.m_ps;
}

Polygon & Polygon::operator = (const Polygon &pg)
{
    if (this==&pg) return *this;
    delete [] m_line;
    m_count=pg.m_count;
    m_ps=pg.m_ps;
    m_line=new Line[m_count];
    for (int i=0;i<m_count;i++)
        m_line[i]=pg.m_line[i];
    return *this;
}

void Polygon::sort()
{
    if (m_count<=1) return;
    int i=0;
    while (i<m_count-1)
    {   
        bool f=false;
        int j=i+1;
        while (j<m_count && !f)
            {
                if (m_line[i].isconnected(m_line[j])==1)
                    f=true;
                if (m_line[i].isconnected(m_line[j])==-1)
                {   
                    f=true;
                    m_line[j].reverse();
                }
                if (m_line[i].isconnected(m_line[j])==0)
                    j++;
            }
        i++;
        Line tl=m_line[i];
        m_line[i]=m_line[j];
        m_line[j]=tl;
    }
    m_ps.clear();
    for (int k=0;k<m_count;k++)
        m_ps.append(m_line[k].getsp());
}

void Polygon::clear()
{
    delete [] m_line;
    m_line=NULL;
    m_ps.clear();
    m_count=0;
}

ostream & operator << (ostream &os, const Polygon &pg)
{
    if (pg.m_count==0) return os<<"No lines"<<endl;
    else
    {
        os<<*pg.m_ps.getpoint();
        for (int i=1;i<pg.m_ps.getcount();i++)
        {
            os<<" -> "<<*(pg.m_ps.getpoint()+i);
        }
        return os<<" -> "<<*(pg.m_ps.getpoint())<<endl;
    }
}

Polygon & Polygon::append(const Point &p)
{
    Polygon pg=*this+p;
    *this=pg;
    return *this;
}

Polygon Polygon::operator + (const Point &p)
{           
    Line l[m_count+2];
    Pointset ps=m_ps;
    ps.append(p);
    int count=0;
    if (m_count==0){return *this;}
    if (m_count==1) 
    {
        count=3;
        l[0]=m_line[0];
        l[1]=Line(m_line[0].getsp(),p);
        l[2]=Line(m_line[0].getep(),p);
    }
    else
    {
        int i=0;
        bool ponl=false;
        while (i<m_count && !ponl)
            if (m_line[i++].pointonline(p)) {ponl=true;}
        if (ponl) 
            return *this;

        i=0;
        bool inside=true;
        int side;
        while (i<m_count)
        {
            Line tl=Line(p,m_line[i].getsp());
            side=tl.pointsatsameside(ps);
            if (side==-1 || side==1)
            {
                bool f=false;
                int j=0;
                while (j<count && !f)
                {
                    if ((p==l[j].getsp()) && (l[j].getk()==tl.getk()||(l[j].isperp() && tl.isperp())))
                    {
                        f=true;
                        if (tl.pointonline(l[j].getep())) l[j]=tl;
                    }
                    j++;
                }
                if (!f) l[count++]=tl;
                inside=false;
            }
            side=m_line[i].pointsatsameside(ps);
            if ((side==-1 || side==1)&& !(m_line[i].pointatside(p)==0))
                l[count++]=m_line[i];     
            i++;
        }
        if (inside==true) return *this;
    }
    
    Polygon pg;
    pg.m_line=new Line[count];
    pg.m_count=count;
    for (int i=0;i<count;i++)
        pg.m_line[i]=l[i];
    pg.sort();
    return pg;
}