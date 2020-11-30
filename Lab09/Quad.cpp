#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

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
    Point(float in_x, float in_y){
        x = in_x;
        y = in_y;
    }
    float getx(){
        return x;
    }
    float gety(){
        return y;
    }
    float setX(float in_X){
        x=in_X;
    }
    float setY(float in_Y){
        y=in_Y;
    }

private:
    float x,y;
};
class Quad {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Quad &L ){
        output <<L.F<<endl;
        output << "Area: " <<setprecision(5)<< L.A <<" sq. units"<<endl;
        output <<"Perimeter: "<<setprecision(5)<<L.c<<" units"<<endl;
        return output;
    }
    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Quad &L ){
        input >> L.A >> L.P2>>L.P3>>L.P4;
        return input;
    }
public:
    Quad(){
        setL(0,0,1,1,1,9,0,9);

    }
    Quad(float a, float b, float c, float d,float e, float f,float g, float h){
        setL(a,b,c,d,e,f,g,h);
    }
    double setL(float a, float b, float c, float d,float e, float f,float g, float h){
        P1.setX(a);
        P1.setY(b);
        P2.setX(c);
        P2.setY(d);
        P3.setX(e);
        P3.setY(f);
        P4.setX(g);
        P4.setY(h);
        if(isQ()==true){
            base1();
            base2();
            L1();
            L2();
            perimeter();
            Area();
        }
    }
    float base1(){
        length1=sqrt(pow((P2.gety()-P1.gety()),2)+pow((P2.getx()-P1.getx()),2));
        return length1;
    }
    float base2(){
        length2=sqrt(pow((P4.gety()-P3.gety()),2)+pow((P4.getx()-P3.getx()),2));
        return length2;
    }
    float L1(){
        length3=sqrt(pow((P3.gety()-P2.gety()),2)+pow((P3.getx()-P2.getx()),2));
        return length3;
    }
    float L2(){
        length4=sqrt(pow((P1.gety()-P4.gety()),2)+pow((P1.getx()-P4.getx()),2));
        return length4;
    }
    float perimeter(){
        c=base1()+base2()+L1()+L2();
        return c;
    }
    float Area(){
        A=(.5)*abs((P1.getx()*P2.gety())+(P2.getx()*P3.gety())+(P3.getx()*P4.gety())+(P4.getx()*P1.gety())-(P2.getx()*P1.gety())-(P3.getx()*P2.gety())-(P4.getx()*P3.gety())-(P1.getx()*P4.gety()));
        return A;
    }
    bool isQ(){
        float T=(P1.getx())*(P2.gety()-P3.gety())+(P2.getx())*(P3.gety()-P1.gety())+(P3.getx())*(P1.gety()-P2.gety());
        float T2=(P2.getx())*(P3.gety()-P4.gety())+(P3.getx())*(P4.gety()-P2.gety())+(P4.getx())*(P2.gety()-P3.gety());
        float T3=(P1.getx())*(P3.gety()-P4.gety())+(P3.getx())*(P4.gety()-P1.gety())+(P4.getx())*(P3.gety()-P1.gety());
        float T4=(P1.getx())*(P2.gety()-P4.gety())+(P2.getx())*(P4.gety()-P1.gety())+(P4.getx())*(P1.gety()-P2.gety());
        if((T==0)||(T2==0)||(T3==0)||(T4==0)){
            F="The object is not a Quadrilateral";
            return false;
        }else{
            F="The object is a Quadrilateral";
            return true;
        }
    }
private:
    Point P1, P2, P3,P4;
    double length1,length2,length3,length4,c,A;
    string E,F;
};


int main()
{
    Quad C1(0,0,2.5,0,2.5,2.5,0,2.5);
    Quad C2;
    cout<<C1<<endl;

}
