#ifndef _POINTSET_
#define _POINTSET_

#include <iostream>
#include "point.h"
#include "line.h"

class Pointset
{
    public:
        Pointset(const int cap=10);
        Pointset(const Pointset &);
        ~Pointset();        
        Pointset & operator =(const Pointset &);
        bool append(const Point &);
        bool append(const Line &);
        Pointset & remove(const Point &);
        bool has(const Point &) const;
        inline Point & getpoint() const {return *p_data;}
        inline int getcapacity() const {return capacity;}
        inline int getcount() const {return count;}
    private:
        int capacity;
        int count;
        Point *p_data;

    friend ostream & operator << (ostream &, const Pointset &);
};

#endif