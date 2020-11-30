#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

int sizeV();
vector<int> randN(int R,int S);
vector<int> comp(vector<int> V,vector<int> Ran);
void Print(vector<int> Cnt);
void PrintBar(int Cnt);
double min(vector<int> Cnt);
double max(vector<int> Cnt);
double sum(vector<int> Cnt);
double mean(vector<int> Cnt);
double min1=0;
double max1=0;
double sum1=0;
double mean1=0;
double scaler=0;
int R;
int S;

int main()
{
    sizeV();
}
//Creates a function with range "R" that will be compared to another vector "Ran"
int sizeV(){
    cout<<"Enter end Range: "<<endl;
    cin>>R;
    cout<<"Enter number of Samples: "<<endl;
    cin>>S;
    cout<<endl;
    vector<int> V;
    for(int i=0;i<R+1;i++){
       V.push_back(i);
    }
    cout<<endl;
    vector<int> Ran=randN(R,S);
    vector<int> Cnt=comp(V,Ran);
    min1=min(Cnt);
    max1=max(Cnt);
    sum1=sum(Cnt);
    mean1=mean(Cnt);
    Print(Cnt);
return 0;
}
//creates a vector of random numbers with the size specified as number of samples
vector<int> randN(int R,int S){
    vector<int> x;
    srand(time(NULL));
    for(unsigned i=0;i<S;i++){
        int g=rand()%(R+1);
        x.push_back(g);
    }
    return x;
}
//compares the values of Vector Size and Vector random numbers. From this it will count how many times
//vector random numbers has the same number at index "x" for vector size
vector<int> comp(vector<int> V,vector<int> Ran){
    vector<int> Cnt;
    for(unsigned o=0;o<V.size();o++){
        Cnt.push_back(0);
    }
    for(unsigned i=0; i<V.size();i++){
        for(unsigned y=0;y<Ran.size();y++){
            if(V.at(i)==Ran.at(y)){
                Cnt.at(i)=Cnt.at(i)+1;
            }
        }
    }
    return Cnt;
}
//Min value for counted numbers turning up in vector Rand
double min(vector<int> Cnt){
    int m=R+1;
    for(unsigned i=0;i<Cnt.size();i++){
        if(Cnt.at(i)<m){
            m=Cnt.at(i);
        }
    }
    return m;
}
//Finds the maximum value with in vector Cnt
double max(vector<int> Cnt){
    int m=0;
    for(unsigned i=0;i<Cnt.size();i++){
        if(Cnt.at(i)>m){
            m=Cnt.at(i);
        }
    }
    return m;
}
//finds the sum of the values in Cnt
double sum(vector<int> Cnt){
    int m=0;
    for(unsigned i=0;i<Cnt.size();i++){
        m=m+Cnt.at(i);
    }
    return m;
}
//finds  the mean of the vector cnt
double mean(vector<int> Cnt){
    double m=0;
    for(unsigned i=0;i<Cnt.size();i++){
        m=m+Cnt.at(i);
    }
    m=m/Cnt.size();
    return m;
}
//Code for printing the requred fields to screen
void Print(vector<int> Cnt){
    cout<<"Index"<<'\t'<<"Value"<<' '<<"Bar"<<endl;
    for(unsigned i=0;i<Cnt.size();i++){
        int x=Cnt.at(i);
        cout<<setw(5)<<i<<setw(8)<<Cnt.at(i)<<setw(2);
        PrintBar(x);
        cout<<endl;
    }
    cout<<"Scalar: "<<scaler<<" per *"<<endl;
    cout<<"Sample Count: "<<S<<endl;
    cout<<"Min Value: "<<min1<<endl;
    cout<<"Max Value: "<<max1<<endl;
    cout<<"Sum Value: "<<sum1<<endl;
    cout<<"Mean Value: "<<mean1<<endl;

}
//prints the bars given for each value.
void PrintBar(int x){
    scaler=max1/40;
    int B= 0;
    B=x/scaler;
    for(unsigned i=0; i<B;i++){
        cout<<'*';
    }
}
