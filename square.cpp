#include "square.h"
#include "line.h"
#include "point.h"


Square::Square(const Point &p, int len) : Polygon(),sidelength(len),area(len*len)
{
    m_count = 4;
    m_line = new Line[4];
    *m_line = Line(p, Point(p.getx(), p.gety() + sidelength));
    *(m_line+1) = Line(p, Point(p.getx()+sidelength, p.gety()));
    *(m_line+2) = Line(Point(p.getx()+sidelength, p.gety() + sidelength), Point(p.getx(), p.gety() + sidelength));
    *(m_line+3) =Line(Point(p.getx()+sidelength, p.gety() + sidelength), Point(p.getx()+sidelength, p.gety()));
    sort();
}

int Square::getarea() const
{
    return area;
}

Squaresq::Squaresq(const Point &p, int len) : Square(p,len)
{
}


int Squaresq::getarea() const
{
    return Square::getarea();
}
