#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float hours;
    float minutes;
    float temp;
    float t;
    cout<<"Enter hours: "<<endl;
    cin>>hours;
    cout<<"Enter minutes: "<<endl;
    cin>>minutes;
    t=(hours)+(minutes/60);
    temp=  (4*pow(t,2))/(t + 2) - 20 ;
    cout<<"Temperature: "<<temp<<endl;
    return 0;
}
