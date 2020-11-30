#include <iostream>

using namespace std;

int main()
{
  float x;
  float y;
  cout<<"x,y input: "<<endl;
  cin>>x;
  cin>>y;
  if(x==0&&y!=0)
      cout<<"On Y-Axis"<<endl;
  else if(x!=0&&y==0)
      cout<<"On X-Axis"<<endl;
  else if(x==0&&y==0)
      cout<<"Center Point"<<endl;
  else if(x<0&&y<0)
      cout<<"Pair is quadrant Q3"<<endl;
  else if(x<0&&y>0)
      cout<<"Pair is quadrant Q2"<<endl;
  else if(x>0&&y>0)
      cout<<"Pair is quadrant Q1"<<endl;
  else if(x>0&&y<0)
      cout<<"Pair is quadrant Q4"<<endl;
}
