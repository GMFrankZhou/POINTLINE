#ifndef _POINTSET_
#define _POINTSET_

#include <iostream>
#include <fstream>
using std::ostream;
using std::istream;
using std::ifstream;


class Point;
class Line;
class Polygon;
class Pointset
{
    public:
        Pointset();
        Pointset(const Pointset &);
        Pointset(const Line&);
        Pointset(const Point&);
        Pointset(const Polygon&);
        ~Pointset();        
        Pointset & operator =(const Pointset &);
        Pointset operator -(const Point &) const;
        Pointset & append(const Point &);
        Pointset & append(const Line &);
        Polygon findboundary() const;
        void clear();
        bool has(const Point &) const;
        inline const Point * getpoint() const {return p_data;}
        inline int getcount() const {return count;}
    private:
        int count;
        Point *p_data;


    friend ostream & operator << (ostream &, const Pointset &);
    friend istream & operator >> (istream &, Pointset &);
    friend void operator >> (ifstream &, Pointset &);

};

#endif