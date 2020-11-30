#include <iostream>

using namespace std;

int main()
{
 double a=1;
 double b=0.0;
 while(a!=0||a>0){
     cout<<"Enter Positive Number to Add or Enter Zero or Negative Number to End:";
     cin>>a;
     if(a<=0){
     break;
     }
     b=b+a;

 }
 cout<<"Sum of Entered Numbers: "<<b<<endl;
}
