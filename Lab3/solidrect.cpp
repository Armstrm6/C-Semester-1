#include <iostream>

using namespace std;

int main()
{
    int w;
    int h;
    cout<<"Width? ";
    cin>>w;
    cout<<"Height? ";
    cin>>h;

    for(int c=0;c<h;c=c+1){
        for(int i=0;i<w;i++){
            cout<<'*';
        }
        cout<<endl;
    }
    return 0;
}
