#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <fstream>

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

vector<double> breakupstring(string str){
    vector<double> numdata;
    stringstream ss;     //requires sstream library included
    ss << str;

    while(!ss.eof()){
        double temp;
        ss >> temp;
        numdata.push_back(temp);
    }

    return numdata;
}

int main(){
    bool isnum=false;
    string s1;
    vector<double> numbers;
    vector<string> lines;
    ifstream infile;
    ofstream outfile;
    infile.open("C:\\Users\\Matt\\Desktop\\Qt\\Lab09\\shapes.txt");
    if(infile.is_open()){
        cout<<"file found"<<endl;
    }
    else{
        cout<<"error"<<endl;
    }
    while (getline(infile,s1)){
        lines.push_back(s1);
    }
    infile.close();
    outfile.open("C:\\Users\\Matt\\Desktop\\Qt\\Lab09\\shape-info.txt");

    for(int i=0;i<lines.size();i++){
    numbers = breakupstring(lines.at(i));
    if(numbers.size()==4){
        outfile<<"Valid points inputed"<<endl;
        isnum=true;
        circle C1(numbers.at(0),numbers.at(1),numbers.at(2),numbers.at(3));
        outfile<<C1<<endl;
    }else if(numbers.size()==6){
        outfile<<"Valid points inputed"<<endl;
        isnum=true;
        Triangle T1(numbers.at(0),numbers.at(1),numbers.at(2),numbers.at(3),numbers.at(4),numbers.at(5));
        outfile<<T1<<endl;
    }else if(numbers.size()==8){
        outfile<<"Valid points inputed"<<endl;
        isnum=true;
        Quad Q1(numbers.at(0),numbers.at(1),numbers.at(2),numbers.at(3),numbers.at(4),numbers.at(5),numbers.at(6),numbers.at(7));
        outfile<<Q1<<endl;
    }else{
        outfile<<"Invalide cordinate input"<<endl;
        isnum=false;
    }
    }
    outfile.close();
    return 0;
}
