#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a;
    double b;
    double c;
    double d;
    double form1;
    double form2;
    double form3;

    cout<<"Enter four numbers: "<<endl;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    form1= (a + b + c)/(2*a*c);
    form2= pow(a,2)/b + (c/d)*(a+b);
    form3= pow(a,(2 + b + c)) + a - c + 4;

    cout<<"Formula 1: "<<form1<<endl;
    cout<<"Formula 2: "<<form2<<endl;
    cout<<"Formula 3: "<<form3<<endl;
    return 0;
}
