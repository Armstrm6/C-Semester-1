#include <iostream>

using namespace std;

class Torus {
public:
    Torus(){
        setr(0);
        setR(0);
    }
    Torus(double in_R, double in_r){
        setR(in_R);
        setr(in_r);
    }
    double getr(){
        return r;
    }
    double getR(){
        return R;
    }
    void setR(double in_R){
        R = in_R;
    }
    void setr(double in_r){
        r=in_r;
    }
    void display(){
        cout << "Torus Parameters: " << endl;
        cout << "Large Radius " << getR() << endl;
        cout << "Inner Radius " << getr() << endl;
        cout << "Volume: " << getVolume() << endl;
        cout << "Surface Area: " << getSA() << endl << endl;
    }
private:
    double getVolume(){
        return 2*(3.1415*3.1415)*(r*r)*R;
    }
    double getSA(){
        return 4*(3.1415*3.1415)*R*r;
    }
    double R;
    double r;
};



int main(){
    Torus rect1;
    rect1.display();
    Torus rect2(7,3);
    rect2.display();
    rect2.setR(3);
    rect2.display();
    return 0;

}
