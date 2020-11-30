
#include <iostream>

#include <cmath>

#include <cstdlib>



using namespace std;



double factorial(double x){
    double y=1;
    double d=y;
    for(int i=x;i>0;i--){
        d=y*i;
        y=d;
    }
    return d;
}


double E_to_X(double x) {
    double y=0;
    double d;
    double c;
   for(int i=0; i<120;i++){
       d=(pow(x,i)/factorial(i));
       c=y+d;
       y=c;
   }

   return y; // Replace return statement with something more proper

}




int main() {



        cout << fixed << "E_to_X(0) is " << E_to_X(0) << " should be 1" << endl;

        cout << fixed << "E_to_X(1) is " << E_to_X(1) << " should be 2.718" << endl;

        cout << fixed << "E_to_X(2) is " << E_to_X(2) << " should be 7.38" << endl;

        cout << fixed << "E_to_X(5) is " << E_to_X(5) << " should be 120" << endl;

        cout << fixed << "E_to_X(10) is " << E_to_X(10) << " should be 22026" << endl;



        return 0;

}
