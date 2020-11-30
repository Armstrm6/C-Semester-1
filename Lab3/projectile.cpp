#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   float V=0;
   double g=9.8;
   float s=1;
   int t=0;
   cout<<"Launch velocity? "<<endl;
   cin>>V;
   cout<<"Initial Velocity of Object: "<<V<<"m/s"<<endl;
   cout<<"Time"<<"  "<<"Heighty"<<endl;
   s=V*t-.5*(g)*pow(t,2);
   cout<<t<<'\t'<<s<<endl;
   t=t+1;
   do{
       s=(V*t)-(.5*(g)*pow(t,2));
       if(s<0){
           cout<<t<<'\t'<<"0"<<endl;
           break;
       }
       cout<<t<<'\t'<<s<<endl;
       t=t+1;
   }while(s>0);
}
