#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float Efield(double r,double a=1);
const double Q=pow(10,-9);
const double k=9*pow(10,9);
int main()
{
   double r;
   double a;
   float w;
   cout<<"Enter r: "<<endl;
   cin>>r;
   cout<<"Enter a: "<<endl;
   cin>>a;
   w=Efield(r,a);
   cout<<"Efield: "<<w<<endl;
   return 0;
}

float Efield(double r, double a){
    if (r<a){
        r=(k*Q)*(r/pow(a,3));
    }
    else{
        r=(k*Q)/pow(r,2);
    }
    return r;
}
