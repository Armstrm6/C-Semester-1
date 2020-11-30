#include <iostream>

using namespace std;

int main()
{
    double userNum;
    cout<<"Enter Richter Scale Number:"<<endl;
    cin>>userNum;
    if(userNum<5.0)
        cout<<"Little Damage"<<endl;
    else if(userNum>=5.0&&userNum<5.5)
        cout<<"Some Damage"<<endl;
    else if(userNum>=5.5&&userNum<6.5)
        cout<<"Serious Damage"<<endl;
    else if(userNum>=6.5&&userNum<7.5)
        cout<<"Disastrous Damage"<<endl;
    else if(userNum>=7.5)
        cout<<"Catastrophic Damage"<<endl;
    return 0;
}
