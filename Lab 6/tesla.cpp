#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

void Start();
int Design();
int play();
char UMove();
int Emusk();
int bubble();
int Fail();
char Game[15][15];
char Obj[15][15];
int x=0;
int y=0;
int a1;
int a2;
int b1;
int b2;
int c1;
int c2;
int d1;
int d2;
int p1;
int p2;
int p3;
int p4;
int C=0;
int F=0;
int W=0;
int L=0;
int main()
{
    cout<<"The rules of the game are simple\n1: Avoid Elon Musk he will only let you escape once\n2: Find the Roadster labeled by \'R\'\n3: If Elon Musk Captures you or you enter the wrong vehichle, YOU LOSE!"<<endl;
    Start();
}
//intitializes all the functions and game board
void Start(){
    int p=0;
    char ans;
    while(p!=2){
        Design();
        play();
        cout<<"Do you want to play again? [y/n] "<<endl;
        cin>>ans;
        if(ans=='y'||ans=='Y'){
            p=0;
        }
        if(ans=='n'||ans=='N'){
            p=2;
            cout<<"Wins: "<<W<<" \nTimes you became STARMAN: "<<L<<endl;
        }
}
}
//Designs the Game board an initializes all the game pieces in a second array stored in (x,y) varaibles... All random
int Design(){
    C=0;
    srand(time(NULL));
    int x=0;
    int y=0;
    for(x=0;x<15;x++){
        for(y=0;y<15;y++){
            Game[x][y]='*';
        }
    }
    a1=rand()%15;
    a2=rand()%15;
    b1=rand()%15;
    b2=rand()%15;
    c1=rand()%15;
    c2=rand()%15;
    d1=rand()%15;
    d2=rand()%15;
    p1=rand()%15;
    p2=rand()%15;
    Obj[a1][a2]='R';
    while(b1==a1&&b2==a2){
        b1=rand()%15;
        b2=rand()%15;
    }
    while((c1==b1&&c2==b2)||(c1==a1&&c2==a2)){
        c1=rand()%15;
        c2=rand()%15;
    }
    while((d1==b1&&d2==b2)||(d1==a1&&d2==a2)||(d1==c1&&d2==c2)){
        d1=rand()%15;
        d2=rand()%15;
    }
    while((p1==b1&&p2==b2)||(p1==a1&&p2==a2)||(p1==c1&&p2==c2)||(p1==d1&&p2==d2)){
        p1=rand()%15;
        p2=rand()%15;
    }
    Obj[b1][b2]='P';
    Obj[c1][c2]='Y';
    Obj[d1][d2]='E';
    Game[p1][p2]='@';

    return 0;
}
//Analysis the player's input to move the piece around the board, it also will alert the player if they are colder or warmer to the desiered end.
char UMove(){
    char M;
    cin>>M;
    p3=p1;
    p4=p2;
    Game[p1][p2]='*';
    switch(M){
        case 'w':
            if(p1==0){
            }else{
            p1=p1-1;
            }
            if(((p3>=a1)&&(p1>=a1))){
                cout<<"Warmer"<<endl;
            }
            else{
                cout<<"Colder"<<endl;
            }
        break;
        case 's':
            if(p1==14){
            }
            else{
            p1=p1+1;
            }
            if((p3<=a1)&&(p1<=a1)){
                cout<<"Warmer"<<endl;
            }
            else{
                cout<<"Colder"<<endl;
            }
        break;
        case 'd':
            if(p2==14){
            }else{
            p2=p2+1;
            }
            if((p4<=a2)&&(p2<=a2)){
                cout<<"Warmer"<<endl;
            }
            else{
                cout<<"Colder"<<endl;
            }
        break;
        case 'a':
            if(p2==0){
            }else{
            p2=p2-1;
            }
            if((p4>=a2)&&(p2>=a2)){
                cout<<"Warmer"<<endl;
            }
            else{
                cout<<"Colder"<<endl;
            }
        default:
            break;
    }
    return 0;
}
int play(){
    while(p1!=a1||p2!=a2){
        for(x=0;x<15;x++){
            for(y=0;y<15;y++){
               cout<<Game[x][y];
            }
        cout<<endl;
        }
        UMove();
        Game[p1][p2]='@';
        C=C+1;
        bubble();
        Emusk();
        bubble();
//        CW();
        cout<<"Count: "<<C<<endl;
        if(Fail()==1){
            L=L+1;
            return 1;
        }
    }
    cout<<"You got away!!"<<endl;
    W=W+1;
    return 0;
}
//randomizes the movements of Elon Musk after the player makes 20 moves on the board
int Emusk(){
    int x;
    srand(time(NULL));
    if(C>=20){
        x=rand()%4+1;
        if(p1!=d1&&p2!=d2){
            if(x==1&&d1!=14){
                d1=d1+1;
            }
            else if(x==1&&d1==14){
                d1=d1-1;
            }
            else if(x==2&&d1!=0){
                d1=d1-1;
            }
            else if(x==2&&d1==0){
                d1=d1+1;
            }
            else if(x==3&&d2!=14){
                d2=d2+1;
            }
            else if(x==3&&d2==14)
            {
                d2=d2-1;
            }
            else if(x==4&&d2!=0){
                d2=d2-1;
            }
            else if(x==4&&d2==0){
                d2=d2+1;
            }
        }
    }
    return 0;
}
//places a 3x3 grid around the player allowing them to see that many spaces around them.. Will pop up associated characters if within range of game pieces.
int bubble(){
    if((d1-1==p1&&d2-1==p2)||(d1+1==p1&&d2-1==p2)||(d1+1==p1&&d2+1==p2)||((d1-1)==p1&&(d2+1)==p2)||(d1-1==p1&&d2==p2)||(d1+1==p1&&d2==p2)||(d2-1==p2&&d1==p1)||(d2+1==p2&&d1==p1)){
        Game[d1][d2]='E';
    }
    else{
        Game[d1][d2]='*';
    }
    if((c1-1==p1&&c2-1==p2)||(c1+1==p1&&c2-1==p2)||(c1+1==p1&&c2+1==p2)||((c1-1)==p1&&(c2+1)==p2)||(c1-1==p1&&c2==p2)||(c1+1==p1&&c2==p2)||(c2-1==p2&&c1==p1)||(c2+1==p2&&c1==p1)){
        Game[c1][c2]='Y';
    }
    else{
        Game[c1][c2]='*';
    }
    if((b1-1==p1&&b2-1==p2)||(b1+1==p1&&b2-1==p2)||(b1+1==p1&&b2+1==p2)||(b1-1==p1&&b2+1==p2)||(b1-1==p1&&b2==p2)||(b1+1==p1&&b2==p2)||(b2-1==p2&&b1==p1)||(b2+1==p2&&b1==p1)){
        Game[b1][b2]='P';
    }
    else{
        Game[b1][b2]='*';
    }
    if((a1-1==p1&&a2-1==p2)||(a1+1==p1&&a2-1==p2)||(a1+1==p1&&a2+1==p2)||(a1-1==p1&&a2+1==p2)||(a1-1==p1&&a2==p2)||(a1+1==p1&&a2==p2)||(a2-1==p2&&a1==p1)||(a2+1==p2&&a1==p1)){
        Game[a1][a2]='R';
    }
    else{
        Game[a1][a2]='*';
    }
    return 0;
}
//sets the parameters for lossing the game and returns integer 1 to alert the code a failed attempt has happend.
int Fail(){
    if(F==0&&((d1-1==p1&&d2==p2)||(d1+1==p1&&d2==p2)||(d2-1==p2&&d1==p1)||(d2+1==p2&&d1==p1))){
        cout<<"Elon Musk has found you but you get away this time."<<endl;
        F=1;
        return 0;
    }
    else if(F==1&&((d1-1==p1&&d2==p2)||(d1+1==p1&&d2==p2)||(d2-1==p2&&d1==p1)||(d2+1==p2&&d1==p1)||(d1==p1&&d2==p2))){
        cout<<"You have been caught and are now STARMAN."<<endl;
        return 1;
    }
    if((p1==b1&&p2==b2)||(p1==c1&&p2==c2)){
        cout<<"You have been caught and are now STARMAN"<<endl;
        return 1;
    }
    return 0;
}
