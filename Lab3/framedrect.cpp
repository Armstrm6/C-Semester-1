#include <iostream>

using namespace std;

int main()
{
    int w;
    int h;
    cout<<"Width? "<<endl;
    cin>>w;
    cout<<"Height? "<<endl;
    cin>>h;

    for(int c=0;c<w;c++){
        cout<<'*';
    }
    cout<<endl;
    for(int i=2;i<h;i++ ){
        cout<<'*';
        for(int b=0;b<(w-2);b++){
            cout<<' ';
        }
        cout<<'*'<<endl;
    }
    for(int c=0;c<w;c++){
        cout<<'*';
    }

    return 0;
}
