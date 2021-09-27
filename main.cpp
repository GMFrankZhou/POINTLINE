#include <iostream>
#include <fstream>
#include "point.h"
#include "line.h"
#include "pointset.h"
#include "polygon.h"

using std::cin,std::cout;

int main() 
{
    ifstream fin("input.in");
    Pointset ps;
    fin >>ps;
    Polygon pg(ps);
 //   Polygon pg=ps.findboundary();
    cout <<pg<<std::endl;
    if ((pg.getcount()>2)&&(ps.getcount()>pg.getcount())) cout <<"The remaining "<<ps.getcount()-pg.getcount()<<" point(s) are covered within the area.\n";
    fin.close();
}