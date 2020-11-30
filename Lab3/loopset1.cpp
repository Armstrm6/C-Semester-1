#include <iostream>

using namespace std;

int main()
{
    int x=0;
    int y=0;
    double a;
    for(int i=2;i<=35;i=i+3){
        x=x+i;
        y=y+1;
        a=x/float(y);
    }
    cout<<"SUM: "<<x<<endl;
    cout<<"AVERAGE: "<<a<<endl;
    return 0;
}
