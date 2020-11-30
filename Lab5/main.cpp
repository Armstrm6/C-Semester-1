#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int win=0;
double loss=0;
double Bank=100;

int rollDie();
bool playOneGame();
int wager();
float winloss();
void highroller();

int main()
{
    int endGame=1;
    int ply;
    int EG;
    srand(time(NULL));
    do{
       EG=wager();
       if(EG==0){
           endGame=0;
       }
       if(endGame==1){
           highroller();
           if(playOneGame()==true){
               Bank=Bank+EG;
           }
           else{
               Bank=Bank-EG;
           }
        }
    }while(endGame!=0);
    cout<<"Final account balance is $"<<Bank<<endl;
    cout<<"You won "<<win<<" time out of "<<(win+loss)<<" times for a winnining percentage of %"<<winloss()<<endl;
return 0;
}

int rollDie(){//roll a die from 1-6
    int x= rand()%6;
    return x;
}
bool playOneGame(){ //plays one round of the dice game
    int point;
    cout<<"Enter your point value (1-6): ";
    cin>>point;
    while(point<1 or point>6 ){
        cout<<"Error: Enter a number between 1 and 6"<<endl;
        cin>>point;
    }
    for(int i=0;i<3;i++){
        int roll=rollDie();
        cout<<"Roll #"<<i+1<<" is "<<roll<<endl;
            if(roll==point){
                cout<<"You Win!!"<<endl;
                win=win+1.0;
                return true;
            }
        }
    cout<<"You Lose!!"<<endl;
    loss=loss+1.0;
    return false;
}
int wager(){ //Calls for the user to select their wager on the match
    int wager;
    if(Bank<=0){
        cout<<"Game over, you are out of money!"<<endl;
        return 0;
    }
    cout<<"Account balance $"<<Bank<<endl;
    cout<<"Enter wager (0 to exit): $";
    cin>>wager;
    while(wager>Bank || wager<0){
        cout<<"Error: You must wager between $1 and $"<<Bank<<" (type 0 to exit) ";
        cin>>wager;
    }
    return wager;
}
float winloss(){//Calculates the win loss ratio as a percent
    double percent=(win/(win+loss))*100;
    return percent;
}
void highroller(){//will grant the player an extra chip for excellent gambling skill.
    if(Bank>1000){
        cout<<"You are a HIGHROLLER Casino grants you a free chip :)"<<endl;
        cout<<"$"<<Bank<<"+$100"<<endl;
    }
}
