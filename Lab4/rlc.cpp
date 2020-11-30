#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float VT(double E, double t);
double VC(double C,double t,double A, double ang);
double I(double A, double t, double ang);
double VL(double L, double A, double t, double ang);
double amp(double E, double L, double C, double R);
double angle(double L, double R, double C);
double VR(double VL, double VC, double VT);


  double E=0;
  double R=0;
  double L=0;
  double C=0;
  double A=0;
  double t=0.000;
  double dT=.04;
  double ang=0;
  double w=100*(3.14159265);

int main()
{
    cout<<"Enter Applied Voltage: ";
    cin>>E;
    cout<<"Enter Resistor Value: ";
    cin>>R;
    cout<<"Enter Inductor value (L): ";
    cin>>L;
    cout<<"Enter Capasitor Value (C): ";
    cin>>C;
    cout<<endl;
    A=amp(E,L,C,R);
    ang=angle(L,R,C);
    cout<<"Calculated Parameters:"<< endl<<"Current Amplitude: \t"<<setw(17)<<setprecision(3)<<A
    <<"-amps"<<endl<<"Phase Angle: "<<setw(26)<<ang<<"-degrees\n"<<endl;
    cout<<'\t'<<"Iter.Time\t"<<"I\t"<<"VR\t"<<"VL\t"<<"VC\t"<<"VT"<<endl;
    int i =0;
    for(t=0.000;t<dT;t=t+.001){
        cout<<'\t'<<setw(3)<<fixed<<setprecision(3)<<i<<"  "<<t<<'\t'<<setw(6)<<I(A,t,ang)<<
        '\t'<<setw(6)<<VR(VL(L,A,t,ang),VC(C,t,A,ang),VT(E,t))<<'\t'<<setw(7)<<VL(L,A,t,ang)<<
        '\t'<<setw(7)<<VC(C,t,A,ang)<<'\t'<<setw(7)<<VT(E,t)<<endl;
        i=i+1;

    }
}
double amp(double E, double L, double C, double R){
    double y= (w*E)/(sqrt(pow((L*pow(w,2)-(1/C)),2)+pow(R,2)*pow(w,2)));
    return y;
}
double angle(double L, double R, double C){
    double y= atan(((L*w)/R)-1/(R*C*w));
    return y;
}


float VT(double E, double t){
    double y= E*sin(w*t);
    return y;
}
double VC(double C,double t,double A, double ang){
    float y= (-A/(C*w))*cos(w*t-ang);
    return y;
}
double I(double A, double t, double ang){
    double y=A*sin(w*t-ang);
    return y;
}
double VR(double VL, double VC, double VT){
    double y= VT-VL-VC;
    return y;
}
double VL(double L, double A, double t, double ang){
    double y= (L*w*A*cos(w*t-ang));
    return y;
}

