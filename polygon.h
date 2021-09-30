#ifndef _POLYGON_
#define _POLYGON_

#include <iostream>
#include "pointset.h"
using std::ostream;

class Line;
class Point;
class Polygon
{
    public:
        Polygon():m_count(0) {m_line=NULL;};
        Polygon(const Pointset &);
        Polygon(const Polygon &);
        Polygon(const Point &, const Point &, const Point &);
        Polygon & operator = (const Polygon &);
        int getcount() const {return m_count;}
        Pointset getpoints() const {return m_ps;}
        const Line *getlines() const {return m_line;}
        void sort();
        void clear();
        Polygon operator + (const Point &);
        Polygon & append(const Point &);
        virtual int area() const {return 0;}
        void printarea() const;

        ~Polygon();

    private:
        Line *m_line;
        Pointset m_ps;
        int m_count;
    friend ostream & operator << (ostream &, const Polygon &);
};

#endif