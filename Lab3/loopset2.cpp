#include <iostream>

using namespace std;

int main()
{
    int x =0;
    int a;
    int y=0;
    int SI;
    int EI;
    int stepC;
    cout<<"Start index: ";
    cin>>SI;
    cout<<endl<<"Ending index: ";
    cin>>EI;
    cout<<endl<<"Step count: ";
    cin>>stepC;
    for(int i=SI;i<=EI;i=i+stepC){
        x=x+i;
        y=y+1;
        a=x/y;
    }
    cout<<"SUM: "<<x<<endl;
    cout<<"AVERAGE: "<<a<<endl;
    return 0;
}
