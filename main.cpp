#include <iostream>
#include "point.h"
#include "line.h"
using namespace std;

int main() 
{
  
Point p1,p2;

cin >> p1;
cin >> p2;


Line l1(p1,p2);
Line l2(Point(1,2),Point(3,4));

if (l1.isconnected(l2))
{
    cout <<"connected";
}
else cout <<"not connected";

}