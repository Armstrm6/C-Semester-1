#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double x;
    float w;
    float wt;
    int t=60;
    cout<<"Width: ";
    cin>>w;
    cout<<"Tolerance: ";
    cin>>wt;
    for(t=60;t<85;t++){
        x=w+(t-70)*(.0001);
        cout <<t<<'\t';
        cout<<fixed << setw(11) << setprecision(7) << x;
        if(x>=(w-wt)&&x<=(w+wt)){
            cout<<"\t"<<'*';
        }
        cout<<endl;
    }
}
