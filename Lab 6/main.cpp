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
int main()
{
    Start();
}
void Start(){
    Design();
    play();
}
int Design(){
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
char UMove(){
    char M;
    cin>>M;
    switch(M){
        case 'w':
            if(p2==15){
                break;
            }
            p2=p2+1;
            break;
        case 's':
            if(p2==0){
                break;
            }
            p2=p2-1;
            break;
        case 'd':
            if(p1==15){
                break;
            }
            p1=p1+1;
            break;
        case 'a':
            if(p1==0){
                break;
            }
            p1=p1-1;
            break;
        default:
            break;
    }
}
int play(){
    while(p1!=a1&&p2!=a2){
        UMove();
        for(x=0;x<15;x++){
        for(y=0;y<15;y++){
            cout<<Game[x][y];
        }
    cout<<endl;
    }
    }
}




/*
for(x=0;x<15;x++){
        for(y=0;y<15;y++){
            cout<<Game[x][y];
        }
    cout<<endl;
    }
    */
