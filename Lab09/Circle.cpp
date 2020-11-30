#include <iostream>
#include <cmath>
#include <fstream>
#include<iomanip>
using namespace std;

class Point {
    friend ostream & operator<<( ostream &output, const Point &P ){
        output << "x: " << P.x << " y: " << P.y;
        return output;
    }
    friend istream & operator>>( istream &input, Point &P ){
        input >> P.x >> P.y;
        return input;
    }
public:
    bool operator==(Point &rhs) {
        return (rhs.getx() == x && rhs.gety() == y);
    }
    Point(){
        x = 0;
        y = 0;
    }
    Point(int in_x, int in_y){
        x = in_x;
        y = in_y;
    }
    double getx(){
        return x;
    }
    double gety(){
        return y;
    }
    double setX(int in_X){
        x=in_X;
    }
    double setY(int in_Y){
        y=in_Y;
    }
private:
    int x,y;
};
class circle {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const circle &L ){
        output <<L.F<<endl
               << "Radius: " <<setprecision(4)<< L.length << endl
               << "Diameter: " <<setprecision(4)<< L.d<<endl
               << "Area: "<<setprecision(4)<<L.a<<endl
               << "Circumference: "<<setprecision(4)<<L.c<<endl;
        return output;
    }
    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, circle &L ){
        input >> L.length >> L.c>>L.a>>L.d;
        return input;
    }
public:
    circle(){
    setL(0,0,1,1);
    if(pointT()==true){
        Radius();
        circumferance();
        diameter();
        Area();
    }
    }
    circle(int a, int b, int c, int d){
        setL(a,b,c,d);
        if(pointT()==true){
            Radius();
            circumferance();
            diameter();
            Area();
        }
    }
    double setL(int a, int b, int c, int d){
        P1.setX(a);
        P1.setY(b);
        P2.setX(c);
        P2.setY(d);
    }
    double Radius(){
        length=sqrt(pow((P2.gety()-P1.gety()),2)+pow((P2.getx()-P1.getx()),2));
        return length;
    }
    double circumferance(){
        c=2*3.14159*Radius();
        return c;
    }
    double diameter(){
        d=Radius()*2;
        return d;
    }
    double Area(){
        a=3.14159*pow(length,2);
        return a;
    }
    bool pointT(){
        if((P1.getx() == P2.getx())&&(P1.gety()==P2.gety())){
            F="The object is not a circle";
            return false;
        }
        else{
            F="The object is a Circle";
            return true;
        }
    }
private:
    Point P1, P2;
    double length, c,d,a;
    string E,F;
};


int main()
{
    circle C1(1,3,5,10);
    circle C2;
    cout<<C2<<endl;
}
