#include <iostream>
#include "point.h"
#include "line.h"
#include "pointset.h"
using namespace std;

int main() 
{
  
Point p1,p2,p3;

cin >>p1>>p2>>p3;

Point p4=p1;

Point p5(p2);
Line l1(p1,p2);
Line l2;
Pointset ps(100);
ps.append(l1);
ps.append(l2);
ps.append(p5);
ps.append(p3);

cout<<ps.getcapacity()<<" "<<ps.getcount()<<endl;
cout<<ps;

Point p6=ps.getpoint();
ps.remove(p6);

cout<<ps.getcapacity()<<" "<<ps.getcount()<<endl;
cout<<ps;

}