#include <iostream>
#include<cstdlib>
#include <vector>
#include<ctime>
using namespace std;


int main() {
    //declare and initialize 2D vectors
    vector<int>vec(3,0);
    vector<vector<int>>game(3,vec);

    //declare loop variables and boolean to keep game running
    int i;
    int j;
    bool gameRun=true;
    int guesses=0;
    bool newGuess;


    //declares variables to accept input from random number and user
    int x;
    int y;
    int inx=0;
    int iny=0;

    //generates ship location and seed using time for randomness
    srand(time(0));
    x=rand()%3;
    y=rand()%3;
    //cout<< x<< " " <<y;

    //for loop to print original matrix
    for(i=0;i<game.size();i++){
        for(j=0;j<game.at(i).size(); j++){
            if(j!=2) {
                cout << " !";
            }
        }
        if(i!=2) {
            cout << endl << "~~~~~" << endl;
        }
    }
    cout << endl;

    while(gameRun) {
        newGuess=false;
        //gets user guess while checking for invalid guesses
        while(!newGuess) {
            cout << "Enter your guess" << endl;
            cin >> inx;
            cin >> iny;
            if (inx > 3 || iny > 3) {
                cout << "Guess is out of range." << endl;
            } else {
                newGuess = true;
                //converts guess to index scale
                inx=inx-1;
                iny=iny-1;
                guesses++;
            }
        }

        //updates matrix
        //0 means hasn't been guesses, 1 means guessed, 2 means hit
        if((inx==x)&&iny==y){
            game.at(inx).at(iny)=2;
        }else{
            game.at(inx).at(iny)=1;
        }

        //prints updated game board
        for(i=0;i<game.size();i++){
            for(j=0;j<game.at(i).size(); j++){
                if(game.at(i).at(j)==1){
                    cout<< " O !";
                }else if(game.at(i).at(j)==2){
                    cout << " X !";
                }else {
                    cout << "   !";
                }
            }
            if(i!=2) {
                cout << endl << "~~~~~~~~~~"<< endl;
            }
        }
        cout << endl << endl;

        //Checks if battleship was hit
        if((inx==x)&&(iny==y)){
            gameRun=false;
            cout << "You sunk my Battleship in " << guesses << " guesses. Congratulations." <<endl;
        }

    }
    return 0;
}