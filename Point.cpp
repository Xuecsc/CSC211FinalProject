#include "Point.h"
using namespace std;

Point::Point(){
  x=0;
  y=0;
}

Point::Point(int x,int y):x(x),y(y){

}

int Point::getX(){
  return x;
}

int Point::getY(){
  return y;
}

void Point::print(){
  cout << "x:" << this->getX() << endl;
  cout << "y:" << this->getY() << endl;
}
