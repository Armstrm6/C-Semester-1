#include <iostream>

using namespace std;

int main()
{
    double inp;
    cout<<"For an input value of: ";
    cin>>inp;

    for(double i=inp;i>0;i=i-0.5){
      cout<<i<<',';
    }
    cout<<'0';
    return 0;
}
