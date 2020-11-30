#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int factorial(int);
int main()
{
    int g;
    int p;
    cout<<"Enter a number: ";
    cin>>g;
    p= factorial(g);
    cout<<"The factorial of the number you entered is: "<<p;
}
int factorial(int x){
    int y=1;
    int d=y;
    for(int i=x;i>0;i--){
        d=y*i;
        y=d;
    }
    return d;
}
