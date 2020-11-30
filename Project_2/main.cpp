/*
 * Project Title: Project 2: Game of Life
 * Description:
 * This program mimics Conway's Game of Life thought not entirely. It allows the user to
 * edit the rules of the game itself or allow a file to seed the game. It allows the user
 * to add points in the beginning but not during the game. After the rules are edited and
 * the points are entered it is a sort of simulation that will go through a certain amount
 * of steps provided by the user.
 *
 * Developers:
 * - John Nuestro - nuestrjc@mail.uc.edu
 * - Matt Armstrong - studentk@mail.uc.edu
 *
 * Help Received:
 * - N/A
 *
 * Special Instructions: // optional
 * - For the file seeding to work, you have to input the full branch into Line 355.
 *
 * Developer comments: // Not optional
 * Developer 1:
 * Please describe what tasks you performed and what your learned from your experience
 * Developer 2:
 * Please describe what tasks you performed and what your learned from your experience
 */


#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Point {
public:
    int x;
    int y;
};

class GameOfLife {
    friend istream & operator>>( istream &input, GameOfLife &P ){
        cout << "Enter Reproduction Rule: " << endl;
        input >> P.reproductionRule;
        cout << "Enter deadOverpop Rule: " << endl;
        input >> P.deadOverpop;
        cout << "Enter deadUnderPop Rule: " << endl;
        input >> P.deadUnderpop;
        cout << "Enter nextGen1 Rule: " << endl;
        input >> P.nextGen1;
        cout << "Enter nextGen2 Rule: " << endl;
        input >> P.nextGen2;
        cout << "Enter stepSize: " << endl;
        input >> P.stepSize;
        return input;
    }
    friend ostream & operator<<( ostream &output, GameOfLife &P ){
        output << P.reproductionRule << P.deadOverpop << P.deadUnderpop << P.nextGen1 << P.nextGen2 << P.stepSize;
        return output;
    }
public:

//Constructors
//===============================================================================================================//
    GameOfLife() {
        reproductionRule = 3;
        deadOverpop = 4;
        deadUnderpop = 1;
        nextGen1 = 2;
        nextGen2 = 3;
        stepSize = 10;
    }
    GameOfLife(int rR, int dO, int dU, int nG1, int nG2, int sS) {
        reproductionRule = rR;
        deadOverpop = dO;
        deadUnderpop = dU;
        nextGen1 = nG1;
        nextGen2 = nG2;
        stepSize = sS;
    }


 // Get Functions
 //===============================================================================================================//
    int getrR() {
        return reproductionRule;
    }

    int getdO() {
        return deadOverpop;
    }

    int getdU() {
        return deadUnderpop;
    }

    int getnG1() {
        return nextGen1;
    }

    int getnG2() {
        return nextGen2;
    }

    int getSS() {
        return stepSize;
    }

    void getVectorX() {
        for (int i = 0; i < x.size(); ++i) {
            cout << "Element " << i + 1 << ": " << x.at(i) << endl;
        }
    }

    void getVectorY() {
        for (int i = 0; i < y.size(); ++i) {
            cout << "Element 1: " << y.at(i) << endl;
        }
    }
//Set Function
//===============================================================================================================//
    void setRules(int rR, int dO, int dU, int nG1, int nG2, int sS) {
        reproductionRule = rR;
        deadOverpop = dO;
        deadUnderpop = dU;
        nextGen1 = nG1;
        nextGen2 = nG2;
        stepSize = sS;
    }

    void setPX() {
        cout << "Enter new X-value." << endl;
        cin >> P.x;
    }

    void setPY() {
        cout << "Enter new Y-value." << endl;
        cin >> P.y;
    }

//Initializes the x and y vector with values
//===============================================================================================================//
    void initVectors() {
        x.push_back(15);
        x.push_back(16);
        x.push_back(16);
        x.push_back(15);
        x.push_back(14);
        y.push_back(15);
        y.push_back(14);
        y.push_back(13);
        y.push_back(13);
        y.push_back(13);

    }

    void inputVector() {
        x.push_back(P.x);
        y.push_back(P.y);
    }

//Game Functions
//===============================================================================================================//

    //Runs the actual game
    int gameFunctions() {
        char cont;
        for (int k = 0; k <= stepSize; ++k) {
            if (k == 0 ) {
                for (int i = 0; i < 31; ++i) {
                    for (int j = 0; j < 31; ++j) {
                        if (cellBoard[i][j] == '1') {
                            gameboard[i][j] = '1';
                        }

                    }
                }
                for (int i = 0; i < 31; ++i) {
                    for (int j = 0; j < 31; ++j) {
                        if (j == 30) {
                            cout << gameboard[i][j] << endl;
                        }
                        else {
                            cout << gameboard[i][j];
                        }
                    }
                }
            }
        //Game steps

            else {
            //Board Edit
                for (int i = 1; i < 31; ++i) {
                    for (int j = 1; j < 31; ++j) {
                        if (cellBoard[i][j] == '0') {
                            if (liveCellCntr(i, j) == reproductionRule) {
                                gameboard[i][j] = '1';
                            }
                            else {
                                gameboard[i][j] = '.';
                            }
                        }
                        if (cellBoard[i][j] == '1') {
                            if (liveCellCntr(i, j) >= deadOverpop) {
                                gameboard[i][j] = '.';
                            }
                            else if (liveCellCntr(i, j) == nextGen1 || liveCellCntr(i, j) == nextGen2) {
                                gameboard[i][j] = '1';
                            }
                            else if (liveCellCntr(i, j) <= deadUnderpop) {
                                gameboard[i][j] = '.';
                            }

                        }
                    }
                }
            }
            for (int i = 0; i < 31; ++i) {
                for (int j = 0; j < 31; ++j) {
                    if (j == 30) {
                        cout << gameboard[i][j] << endl;
                    }
                    else {
                        cout << gameboard[i][j];
                    }
                }
            }
            cout << "Step: " << k << endl;
            cout << "Enter a space to continue or Q to quit the game." << endl;
            cin >> cont;

            if (cont == 'Q') {
                    break;
            }

            for (int i = 0; i < 31; ++i) {
                for (int j = 0; j < 31; ++j) {
                    if (gameboard[i][j] == '1') {
                        cellBoard[i][j] = '1';
                    }
                    else if (gameboard[i][j] == '.') {
                        cellBoard[i][j] = '0';
                    }
                }
            }

        }

        return stepSize;
    }

    //Counts how many live cells around a certain point
    int liveCellCntr(int i, int j) {
        int liveCntr = 0;
        if (cellBoard[i][j+1] == '1') {
            liveCntr += 1;
        }
        if (cellBoard[i][j-1] == '1') {
            liveCntr += 1;
        }
        if (cellBoard[i+1][j] == '1') {
            liveCntr += 1;
        }
        if (cellBoard[i-1][j] == '1') {
            liveCntr += 1;
        }
        if (cellBoard[i+1][j+1] == '1') {
            liveCntr += 1;
        }
        if (cellBoard[i+1][j-1] == '1') {
            liveCntr += 1;
        }
        if (cellBoard[i-1][j+1] == '1') {
            liveCntr += 1;
        }
        if (cellBoard[i-1][j-1] == '1') {
            liveCntr += 1;
        }
        return liveCntr;
    }

//Board Displays
//________________________________________________________________________________//
    void gameboardDisp() {


        for (int i = 0; i < 31; ++i) {
            for (int j = 0; j < 31; ++j) {
                if (i == 0) {
                    gameboard[i][j] = '_';
                }
                if (j == 0) {
                    gameboard[i][j] = '|';
                }
                if (i == 0 && j == 0) {
                    gameboard[i][j] = ' ';
                }
                if (i != 0 && j != 0) {
                    gameboard[i][j] = '.';
                }

            }
        }
        /**for (int i = 0; i < 31; ++i) {
            for (int j = 0; j < 31; ++j) {
                if (j == 30) {
                    cout << gameboard[i][j] << endl;
                }
                else {
                    cout << gameboard[i][j];
                }
            }
        }**/
    }

    void cellDisp() {
        initVectors();
        for (int i = 0; i < 31; ++i) {
            for (int j = 0; j < 31; ++j) {
                cellBoard[i][j] = '0';
            }
        }

        for (int i = 0; i < 31; ++i) {
            for (int j = 0; j < 31; ++j) {
                for (int k = 0; k < x.size(); ++k) {
                    cellBoard[x[k] + 1][y[k] + 1] = '1';
                }
                if (cellBoard[i][j] != '1') {
                    cellBoard[i][j] = '0';
                }
            }
        }
        /**for (int i = 0; i < 31; ++i) {
            for (int j = 0; j < 31; ++j) {
                if (j == 30) {
                    cout << cellBoard[i][j] << endl;
                }
                else {
                    cout << cellBoard[i][j];
                }
            }
        }**/
    }


//File Seeding
//________________________________________________________________________________//
    void fileGameSeed() {

        ifstream inFile;

        inFile.open("C:\\Users\\johnc\\OneDrive\\Desktop\\Freshman Spring\\Program\\QT Before\\ConwaySeed.txt");


            inFile >> reproductionRule;
            //cout << reproductionRule << endl;
            inFile >> deadOverpop;
            //cout << deadOverpop << endl;
            inFile >> deadUnderpop;
            //cout << deadUnderpop << endl;
            inFile >> nextGen1;
            //cout << nextGen1 << endl;
            inFile >> nextGen2;
            //cout << nextGen2 << endl;
            inFile >> stepSize;
            //cout << stepSize << endl;
    }

    void outVar() {
        cout << reproductionRule << endl << deadOverpop << endl << deadUnderpop << endl << nextGen1 << endl << nextGen2 << endl << stepSize << endl;
    }

    void runFunctions() {

        gameboardDisp();
        cellDisp();
        initVectors();
    }


private:
    int reproductionRule, deadOverpop, deadUnderpop, nextGen1, nextGen2, stepSize;
    char gameboard[31][31], cellBoard[31][31];
    vector<int> x;
    vector<int> y;
    Point P;
};

//Game Rules
//________________________________________________________________________________//
    void gameRulesEdit(GameOfLife &G) {
        char edit;
        char file;
        bool accept = 1;
        cout << "Would you like to edit the game rules? (y / n)" << endl;
        do {
        cin >> edit;

            if (edit == 'y') {
                do {
                    cout << "Would you like to use a file to seed the game or edit it yourself? (f / u)" << endl;
                    cin >> file;

                        if (file == 'f') {
                            G.fileGameSeed();
                            file ='d';
                        }
                        else if (file == 'u') {
                           do {
                            cout << "Enter values: " << endl;
                            cin >> G;
                            if (G.getdU() == G.getdO() || G.getdO() < G.getdU()) {
                                cout << "deadOverpop and deadUnderpop is not acceptable" << endl;
                                accept = 0;

                            }
                            if (G.getnG1() == G.getdO() || G.getnG1() == G.getdU() || G.getnG2() == G.getdO() || G.getnG2() == G.getdU()) {
                                cout << "nextGen1 or nextGen2 are unacceptable values" << endl;
                                accept = 0;
                            }
                            }while(accept == 0);
                            file = 'd';
                        }
                        else {
                            cout << "You did not enter a proper input. Please enter a proper input." << endl;
                            cin >> file;
                        }

                    }while (file != 'd');
                edit = 'n';
            }
            \
        } while (edit != 'n');
    }

    void gameRules() {
        cout << "Rules Explaination:\nReproduction Rule is the number of cells are required to be around a dead cell to become a live cell." << endl;
        cout << "Overpopulation Rule is the minimum number of cells that have to be arounda a live cell  for it to become a dead cell." << endl;
        cout << "Underpopulation Rule is the maximum number of cells that have to be around it for it to become a dead cell" << endl;
        cout << "Next Generation 1 and 2 Rules are the numbers that need to be around a live cell for it to stay alive." << endl << endl;
    }

    void inputPoint(GameOfLife &G) {
        char input = 'a';
        do {
            cout << "Would you like to input a point? (y / n)" << endl;
                cin >> input;
                if (input == 'y') {
                    G.setPX();
                    G.setPY();
                    G.inputVector();

                }

        } while (input != 'n');
    }

    //Runs the game
    void runGame(GameOfLife &G) {
        char keepPlay;
        do {

            gameRules();
            inputPoint(G);
            gameRulesEdit(G);

            G.runFunctions();
            G.gameFunctions();
            cout << "Would you like to play again?";
            cin >> keepPlay;
        } while (keepPlay == 'y');


    }

int main() {
    GameOfLife G;



    runGame(G);

    return 0;

}
