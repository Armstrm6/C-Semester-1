#include <iostream>

using namespace std;

class Cube {
public:
    Cube(){
        setW(0);
    }
    Cube(double in_w){
        setW(in_w);
    }
    double getW(){
        return w;
    }
    void setW(double in_w){
        w = in_w;
    }

    void display(){
        cout << "Cube Parameters: " << endl;
        cout << "Width: " << getW() << endl;
        cout << "Volume: " << getVolume() << endl;
        cout << "Surface Area: " << getSA() << endl << endl;
    }
private:
    double getVolume(){
        return w*w*w;
    }
    double getSA(){
        return 6*(w*w);
    }
    double w;
};



int main(){
    Cube rect1;
    rect1.display();
    Cube rect2(2);
    rect2.display();
    rect2.setW(3);
    rect2.display();
    return 0;

}
