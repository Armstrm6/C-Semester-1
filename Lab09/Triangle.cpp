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
class Triangle {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Triangle &L ){
        output <<L.F<<endl
               << "Area of the triangle: " << L.a << endl
               << "Perimeter of the triangle: " <<setprecision(4)<< L.c<<endl
               <<L.E<<endl;
        return output;
    }
    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Triangle &L ){
        input;
        return input;
    }
public:
    Triangle(){
    setL(0,0,1,1,1,9);
    if (isT()==true){
        base();
        height();
        hypotnuse();
        equilateral();
        perimeter();
        Area();
    }
    }
    Triangle(int a, int b, int c, int d,int e, int f){
        setL(a,b,c,d,e,f);
        if (isT()==true){
            base();
            height();
            hypotnuse();
            equilateral();
            perimeter();
            Area();
        }
    }
    double setL(int a, int b, int c, int d,int e, int f){
        P1.setX(a);
        P1.setY(b);
        P2.setX(c);
        P2.setY(d);
        P3.setX(e);
        P3.setY(f);
    }
    double base(){
        length1=sqrt(pow((P2.gety()-P1.gety()),2)+pow((P2.getx()-P1.getx()),2));
        return length1;
    }
    double height(){
        length2=sqrt(pow((P3.gety()-P2.gety()),2)+pow((P3.getx()-P2.getx()),2));
        return length2;
    }
    double hypotnuse(){
        length3=sqrt(pow((P3.gety()-P1.gety()),2)+pow((P3.getx()-P1.getx()),2));
        return length3;
    }
    void equilateral(){
        if(height()==base()){
            if(base()==hypotnuse()){
                E="The triangle is an equilateral triangle";
            }
        }else{
            E="The triangle is not an equilateral triangle";
        }

    }
    double perimeter(){
        c=hypotnuse()+base()+height();
        return c;
    }
    double Area(){
        double p=perimeter()/2.0;
        a=sqrt(p*(p-base())*(p-height())*(p-hypotnuse()));
        return a;
    }
    bool isT(){
        float T=(P1.getx())*(P2.gety()-P3.gety())+(P2.getx())*(P3.gety()-P1.gety())+(P3.getx())*(P1.gety()-P2.gety());
        if(T==0){
            F="This object is not a triangle";
            return false;
        }else{
            F="This object is a triangle";
            return true;
        }
    }
private:
    Point P1, P2, P3;
    double length1,length2,length3,a,c;
    string E,F;
};


int main()
{
    Triangle C1(0,0,1,0,0,1);
    Triangle C2;
    cout<<C1<<endl;

}
