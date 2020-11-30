
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double newtonRoot(double x);
double f(double x);
double fprime(double x);

int main()
{
    double r;
    char w;
    double guess;
    int i=0;
    do {
        cout<<"Enter a guess: "<<endl;
        cin>>guess;
        r=newtonRoot(guess);
        cout<<fixed<<setprecision(2)<<"Root: "<<r<<endl;
        cout<<"Enter Another Guess: y/n?"<<endl;
        cin>>w;
        i=0;

        if(w=='n'){
            i=1;
        }
    }while(i!=1);

    return 0;
}
double newtonRoot(double guess){
    float x1;
    for(int i=0;i<2;i++){
        x1=(f(guess)/fprime(guess));
        guess= guess-x1;
        if(x1>.00001){
            i=0;
        }
    }
    return guess;
}
double f(double x){
    double delt1= (pow(x,4)+2*pow(x,3)-31*pow(x,2)-32*x+60);
    x= delt1;
    return x;
}
double fprime(double x){
  x=4*pow(x,3)+6*pow(x,2)-62*x-32;
  return x;
}


