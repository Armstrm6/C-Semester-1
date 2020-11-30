// Please place your information here
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

// This prototype is complete
class stringManip {
    public:
    stringManip();
    stringManip(string in_string);
    string retrieve();
    void setString(string input);
    void chop();
    void padString(int n);
    void center(int length);
    void truncate(int n);
    void removeNonAlpha();
    void convertToUpperCase();
    void convertToLowerCase();
    private:
        string tobeEdited;
};
// Not all functions are defined here
// Default Constructor
stringManip::stringManip(){
    setString("");
}
// Overloaded Constructor
stringManip::stringManip(string in_string){
    setString(in_string);
}
// retrieve function
string stringManip::retrieve(){
    return tobeEdited;
}
// padString() function
void stringManip::padString(int n){
    string x=" ";
    while(tobeEdited.size()<n){
        tobeEdited.append(x);
    }
}
void stringManip::setString(string input){
    tobeEdited=input;
}
// Add rest of functions here

void stringManip::chop(){
    int x=tobeEdited.size();
    for(int i=0; i<x; i++){
            i=0;
            if(isalnum(tobeEdited.at(i))||ispunct(tobeEdited.at(i))){
                break;
            }
            tobeEdited.erase(tobeEdited.begin()+i);
            i=0;
    }
    x=0;
    int i=tobeEdited.size();
    while(i>0){
        x=0;
        while (x<tobeEdited.size()){
            x=x+1;
        }
            i=x-1;
            if(isalnum(tobeEdited.at(i))||ispunct(tobeEdited.at(i))){
                break;
            }
            tobeEdited.erase(tobeEdited.begin()+i);
    }
}

void stringManip::center(int length){
    int n=0;
    int d=tobeEdited.size();
    int isodd=0;
    length=length-d;
    string x=" ";
    chop();
    if(length%2>0){
        length=length-1;
        isodd=1;
    }
    length=length/2;
    while(n<length){
        tobeEdited.insert(0,x);
        n++;
    }
    n=0;
    while(n<length){
        tobeEdited.append(x);
        n++;
    }
    if(isodd==1){
        tobeEdited.append(x);
    }
}

void stringManip::truncate(int n){
    int i=tobeEdited.size();
    while(i>n){
        int x=0;
        while (x<tobeEdited.size()){
            x=x+1;
        }
            i=x-1;
            tobeEdited.erase(tobeEdited.begin()+i);
        i=tobeEdited.size();
    }
}

void stringManip::removeNonAlpha(){
    int x=tobeEdited.size()-1;
    for(int i=0; i<x; i++){
        if(!isalpha(tobeEdited.at(i))){
            tobeEdited.erase(tobeEdited.begin()+i);
            x=tobeEdited.size();
            i=0;
        }
    }
}

void stringManip:: convertToUpperCase(){
    int x=tobeEdited.size()-1;
    char t;
    for(int i=0; i<=x; i++){
            tobeEdited.at(i)=toupper(tobeEdited.at(i));
    }
}

void stringManip::convertToLowerCase(){
    int x=tobeEdited.size()-1;
    char t;
    for(int i=0; i<=x; i++){
            tobeEdited.at(i)=tolower(tobeEdited.at(i));
    }
}

// Add test cases to main()
int main(){
    stringManip S1;
    stringManip S2("testing 123");
    // Test case for padString() You should correct some of your own.
    cout << "S2 before padString(20): <" << S2.retrieve() << ">" << endl;
    S2.padString(20);
    cout << "S2 after padString(20): <" << S2.retrieve() << ">" << endl;
    cout << "Should be: <testing 123       >" << endl;
    cout<<"S1 initial: <"<<S1.retrieve()<<">"<<endl;
    S1.chop();
    cout<<"S1 after chop(): <"<<S1.retrieve()<<">"<<endl;
    S1.center(13);
    cout<<"S1 after center(13): <"<<S1.retrieve()<<">"<<endl;
    S1.truncate(13);
    cout<<"S1 after truncate(13): <"<<S1.retrieve()<<">"<<endl;
    S1.convertToUpperCase();
    cout<<"S1 after UPPERCASE: <"<<S1.retrieve()<<">"<<endl;
    S1.convertToLowerCase();
    cout<<"S1 after lowercase: <"<<S1.retrieve()<<">"<<endl;
    stringManip S3;
    S3.removeNonAlpha();
    cout<<"S3 after alpha removal: <"<<S3.retrieve()<<">"<<endl;
    return 0;
}
