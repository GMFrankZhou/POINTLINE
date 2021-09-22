#include <iostream>
#include "point.h"
#include "line.h"
#include "pointset.h"
#include "polygon.h"

using namespace std;

int main() 
{

Pointset ps;

cin >>ps;

//Polygon pg(ps);
Polygon pg=ps.findboundary();
cout <<pg;



}