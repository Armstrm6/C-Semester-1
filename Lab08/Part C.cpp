#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
using namespace std;


// Please replace this Point class with your version from Part B
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
class Line {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Line &L ){
        output << "Point 1: " << L.P1 << endl << "Point 2: " << L.P2;
        return output;
    }
    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Line &L ){
        input >> L.P1 >> L.P2;
        return input;
    }
public:
    Line(){
    setL(0,0,0,0);
    }
    Line(int a, int b, int c, int d){
        setL(a,b,c,d);
    }
    double setL(int a, int b, int c, int d){
        P1.setX(a);
        P1.setY(b);
        P2.setX(c);
        P2.setY(d);
    }
    double Slope(){
        double slope=(P2.gety()-P1.gety())/(P2.getx()-P1.getx());
        return slope;
    }
    double Length(){
        double length=sqrt(pow((P2.gety()-P1.gety()),2)+pow((P2.getx()-P1.getx()),2));
        return length;
    }
    double yintercept(){
        double yint=(P1.gety()-Slope()*P1.getx());
        return yint;
    }
    void vertical(){
        if(Slope()>999999999999||Slope()<-9999999999){
            cout<<"The line is vertical"<<endl;
        }
    }
    void horizontal(){
        if(Slope()==0){
            cout<<"Line is horzontal"<<endl;
    }
    }
private:
    Point P1, P2;
};
int main(){
    Line L1;
    Line L2(5,6,7,8);
    // Line L2(5,6,7,8);
    cout << "L1: should have all zeros for values" << endl;
    cout << L1 << endl;
    cout << "Enter Two Points For Line: ";
    cin >> L1;
    cout << L1 << endl;
//    cout<<L1<<endl;
    cout <<"Slope: "<<L1.Slope()<<endl;
    cout <<"Length: "<<L1.Length()<<endl;
    cout<<"Y-Intercept: "<<L1.yintercept()<<endl;
    L1.vertical();
    L1.horizontal();
    if(L1.Slope()==L2.Slope()){
        cout<<"The lines are parallel to each other."<<endl;
    }
    return 0;
}
