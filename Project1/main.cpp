#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <string>
using namespace std;

int diff = 0;
char gameboard[17][31];
int bomb[99][99];
unsigned long long sizeX=0, sizeY=0;
int x=0,y=0;

//Just displays the rules
void rules() {
    cout << "You will be asked to input an x and y coordinate on the board that you would like to go" << endl;
    cout << "The board is labeled based on the size of the gameboard you choose, a 0 is a value of ten times the number of zeroes exist before it." << endl;
    cout << "For example, if you have 0 ... 0 ... 0, that means that the last 0 is a value of twenty since there are two zeroes before it." << endl;
    cout << "Value before that zero is added on to that 0 value" << endl<<endl;
}

//Asks the user for the difficulty size.
int difficulty() {
    int diff = 0;

    cout << "Choose difficulty: Easy(1), Medium(2), or Hard(3) " << endl;
    cout << "Easy is 9x9, Medium is 16x16, Hard is 16x30" << endl;
    cin >> diff;
    while(diff!=1&&diff!=2&&diff!=3){
        cout<<"please choose an actual number listed!!"<<endl;
        cin>>diff;
    }
    return diff;
}
//Allow player to choose X and Y coordinate and will display an error if the point is out of range (Should be finished)
int playerPoint() {
    if (diff == 1) {
        sizeX = 10;
        sizeY = sizeX;
    }
    else if (diff == 2) {
        sizeX = 17;
        sizeY = sizeX;
    }
    else {
        sizeX = 17;
        sizeY = 31;
    }
    cout<<"X: ";
    cin>>x;
    cout<<endl;
    cout<<"Y: ";
    cin>>y;
    cout<<endl;
    while(x>sizeX||x<1){
        cout<<"X cordinate out of bounds, pick another integer."<<endl<<"X: ";
        cin>>x;
    }
    while(y>sizeY||y<1){
        cout<<"Y cordinate out of bounds, pick another integer."<<endl<<"Y: ";
        cin>>y;
    }
}
//needed for the sweep and check sweep functions
void perimeter(int x1, int y1){
    if(bomb[x1][y1]==1){
        gameboard[x1][y1]='1';
    }
    if(bomb[x1][y1]==2){
        gameboard[x1][y1]='2';
    }
    if(bomb[x1][y1]==3){
        gameboard[x1][y1]='3';
    }
    if(bomb[x1][y1]==4){
        gameboard[x1][y1]='4';
    }
}
//checks the perimeter of the original sweep function for zero's
void checksweep(int a, int b){
    int g=a;
    int f=b;
    if(bomb[a][b]==0){
        gameboard[a][b]='0';
        while(b<sizeY&&(bomb[a][b]==0)){
            gameboard[a][b]='0';
            while(a<sizeX&&(bomb[a][b]==0)){
                gameboard[a][b]='0';
                a+=1;
                if(bomb[a][a+1]!=0){
                    perimeter(a,(b-1));
                    perimeter(a,(b+1));
                    perimeter((a-1),b);
                    perimeter((a+1),b);
                }
            }
            b+=1;
            a=g;
        }
    }
    b=f;
    a=g;
    if(bomb[a][b]==0){
        gameboard[a][b]='0';
        while(a<sizeX&&(bomb[a][b]==0)){
            gameboard[a][b]='0';
            while(b<sizeY&&(bomb[a][b]==0)){
                gameboard[a][b]='0';
                b+=1;
                if(bomb[a+1][b]!=0){
                    perimeter(a,(b-1));
                    perimeter(a,(b+1));
                    perimeter((a-1),b);
                    perimeter((a+1),b);
                }
            }
            a+=1;
            b=f;
        }
    }
    if(bomb[a][b]==0){
        gameboard[a][b]='0';
        while(b>1&&(bomb[a][b]==0)){
            gameboard[a][b]='0';
            while(a>1&&(bomb[a][b]==0)){
                gameboard[a][b]='0';

                a=a-1;
                if(bomb[a][b-1]!=0){
                    perimeter(a,(b-1));
                    perimeter(a,(b+1));
                    perimeter((a-1),b);
                    perimeter((a+1),b);
                }
            }
            b=b-1;
            a=g;
        }
    }
    b=f;
    a=g;
    if(bomb[a][b]==0){
        gameboard[a][b]='0';
        while(a>1&&(bomb[a][b]==0)){
            gameboard[a][b]='0';
            while(b>1&&(bomb[a][b]==0)){
                gameboard[a][b]='0';
                b=b-1;
                if(bomb[a-1][b]!=0){
                    perimeter(a,(b-1));
                    perimeter(a,(b+1));
                    perimeter((a-1),b);
                    perimeter((a+1),b);
                }
            }
            a=a-1;
            b=f;
        }
    }
}
//Function for showing the numbers in the actual game baord, easy if the number isnt zero
//but if the number is zero becomes much harder.
int sweep(){
    int c=x;
    int d=y;
    perimeter(x,y);
    if(bomb[x][y]==5){
        gameboard[x][y]='5';
            return 1;
    }
    for(int g=0;g<2;g++){
    if(bomb[x][y]==0){
        gameboard[x][y]='0';
        while(y<sizeY&&(bomb[x][y]==0)){
            gameboard[x][y]='0';
            while(x<sizeX&&(bomb[x][y]==0)){
                gameboard[x][y]='0';
                x+=1;
                checksweep((x),y+1);
                checksweep((x),y-1);
                if(bomb[x+1][y]!=0){
                    perimeter((x+1),y);
                    perimeter((x-1),y);
                    perimeter((x),(y-1));
                    perimeter((x),(y+1));
                }
            }
            y+=1;
            x=c;
        }
    }
    y=d;
    x=c;
    if(bomb[x][y]==0){
        gameboard[x][y]='0';
        while(x<sizeX&&(bomb[x][y]==0)){
            gameboard[x][y]='0';
            while(y<sizeY&&(bomb[x][y]==0)){
                gameboard[x][y]='0';
                y+=1;
                checksweep(x+1,(y));
                checksweep(x-1,(y));
                if(bomb[x+1][y]!=0){
                    perimeter((x+1),(y));
                    perimeter((x-1),(y));
                    perimeter((x),(y-1));
                    perimeter((x),(y+1));
                }
            }
            x+=1;
            y=d;
        }
    }
    if(bomb[x][y]==0){
        gameboard[x][y]='0';
        while(y>0&&(bomb[x][y]==0)){
            gameboard[x][y]='0';
            while(x>0&&(bomb[x][y]==0)){
                gameboard[x][y]='0';
                x=x-1;
                checksweep((x),y+1);
                checksweep((x),y-1);
            if(bomb[x][y-1]!=0){
                    perimeter((x),(y-1));
                    perimeter((x),(y+1));
                    perimeter((x+1),(y));
                    perimeter((x-1),(y));
            }
            }
            y=y-1;
            x=c;
        }
    }
    y=d;
    x=c;
    if(bomb[x][y]==0){
        gameboard[x][y]='0';
        while(x>0&&(bomb[x][y]==0)){
            gameboard[x][y]='0';
            while(y>0&&(bomb[x][y]==0)){
                gameboard[x][y]='0';
                y=y-1;
                checksweep(x-1,(y));
                checksweep(x+1,(y));
                if(bomb[x-1][y]!=0){
                    perimeter((x),(y-1));
                    perimeter((x),(y+1));
                    perimeter((x+1),(y));
                    perimeter((x-1),(y));
                }
            }
            x=x-1;
            y=d;
        }
    }
    }
    for(unsigned long long i = 0; i < sizeX; ++i) {
        for (unsigned long long j = 0; j < sizeY; ++j) {
            cout << gameboard[i][j];

        }
        cout << endl;
    }
    return 0;
}
//to here



/* I removed the functions for the main menu, and the Bomb's X and Y cordinates
 * It seemed easier to me if we moved the game board and the bomb board as two X:Y arrays to the top
 * and globalized them. The code bellow will generate a game board of equal size to the actual one and populate it with
 * 5's based on how many bombs are neede. Then, after it has been populated once, the board populates itself again with
 * figures that show how many bomb's are around a possition on the board.
 * The "cout" functions included here are for testing purposes and can be removed whenever.
 */
void bombGenerator(int diff){
    srand(time(NULL));
    int x,y;
    int bombSize;
    if (diff == 1) {
        bombSize= 10;
    }
    else if (diff == 2) {
        bombSize= 40;
    }
    else {
        bombSize = 99;

    }
    while(bombSize>0){
        x=rand()%(sizeX-1)+1;
        y=rand()%(sizeY-1)+1;
        while(bomb[x][y]==5){
            x=rand()%(sizeX-1)+1;
            y=rand()%(sizeY-1)+1;
        }
        bomb[x][y]=5;
        bombSize=bombSize-1;
    }
    int c=0;
    for(int i=0; i<sizeX;i++){
        for(int d=0; d<sizeY;d++){
            c=0;
            if(i==0||d==0){
                bomb[i][d]='9';
            }
            if(bomb[i+1][d]==5){
                c+=1;
            } if(bomb[i-1][d]==5){
                c+=1;
            } if(bomb[i][d+1]==5){
                c+=1;
            } if(bomb[i][d-1]==5){
                c+=1;
            }
            if(i==0||d==0){
                c=9;
            }
            if(bomb[i][d]==5){
               cout<< bomb[i][d];
            }else{
               bomb[i][d]=c;
               cout<<bomb[i][d];
            }
        }
        cout<<endl;
    }

}
//Generates board depending on difficulty
void gameBoardGen(int diff, char gameboard[17][31]) {
    if (diff == 1) {
        sizeX = 10;
        sizeY = sizeX;
    }
    else if (diff == 2) {
        sizeX = 17;
        sizeY = sizeX;
    }
    else {
        sizeX = 17;
        sizeY = 31;
    }

    for (unsigned long long i =0; i < sizeX; ++i) {
           for (unsigned long long j = 0; j < sizeY; ++j){
               if (i == 0 && j == 0) {
                   gameboard[i][j] = '0';
               }
               else if (i == 0) {
                   for (unsigned long long c = 1; c < sizeX; ++c) {
                       if (j <= 9) {
                        gameboard[i][j] = char(48+j);
                       }
                       else if(j >= 10 && j <= 19) {
                        unsigned long long second = j - 10;
                        gameboard[i][j] = char(48 + second);
                       }
                       else if(j >= 20 && j <=29){
                        unsigned long long second = j - 20;
                        gameboard[i][j] = char(48 + second);
                       }
                       else if(j > 29){
                        unsigned long long second = j - 30;
                        gameboard[i][j] = char(48 + second);
                       }
                   }
               }
               else if (j == 0) {
                   for (unsigned long long c = 1; c < sizeY; ++c) {
                       if (i <= 9) {
                        gameboard[i][j] = char(48+i);
                       }
                       else if(i >= 10 && i <= 19) {
                        unsigned long long second = i - 10;
                        gameboard[i][j] = char(48 + second);
                       }
                       else if(i >= 20 && i <=29){
                        unsigned long long second = i - 20;
                        gameboard[i][j] = char(48 + second);
                       }


                   }
               }
               else {
                   gameboard[i][j] = '.';
               }
           }
           cout << endl;
       }
    for (unsigned long long i = 0; i < sizeX; ++i) {
        for (unsigned long long j = 0; j < sizeY; ++j) {
            cout << gameboard[i][j];

        }
        cout << endl;
    }
}
//prints all bombs on the gameboard if a bomb has been selected to lose the game
void lose(){
    for (unsigned long long i = 0; i < sizeX; ++i) {
        for (unsigned long long j = 0; j < sizeY; ++j) {
            if(bomb[i][j]==5){
                gameboard[i][j]='5';
            }
            cout << gameboard[i][j];
        }
        cout << endl;
    }
}
//simply keeps the main function to a one call list, good practice acording to the TA's
int game(){
    srand(time(NULL));
    rules();
    diff = difficulty();
    gameBoardGen(diff, gameboard);
    bombGenerator(diff);
    int w=0;
    while(w!=1){
        playerPoint();
        w=sweep();
        if(w==1){
            lose();
            cout<<"YOU LOSE"<<endl;
        }
    }
    return 0;
}
int main() {
    game();
    return 0;

}

