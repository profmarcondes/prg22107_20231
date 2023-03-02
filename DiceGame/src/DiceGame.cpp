//============================================================================
// Name        : DiceGame.cpp
// Author      : Hugo Marcondes
// Version     :
// Copyright   : 
// Description : DiceGame
//============================================================================

#include <iostream>
#include <ctime>
using namespace std;

class Die {

  private:
    int _faceValue;

  public:
    Die(){
    	cout << "Die (" << this << ") constructed!" << endl;
        srand (time(NULL));
        roll();
    }
    void roll(){
    	_faceValue = (rand() % 6) + 1;
    	cout << "Die (" << this << ") rolled: " << _faceValue << endl;
    }
    int faceValue(){
        return this->_faceValue;
    }
    void faceValue(int faceValue){
        if(faceValue > 0 && faceValue < 7){
            _faceValue = faceValue;
        }
    }
};

class DiceGame {
  private:
	Die _die1;
	Die _die2;

  public:
	DiceGame(){ cout << "DiceGame (" << this << ") constructed!" << endl; }
	bool play();
};

bool DiceGame::play(){
	int face1;
	int face2;
	_die1.roll();
	_die2.roll();
	face1 = _die1.faceValue();
	face2 = _die2.faceValue();
	if( (face1 + face2) == 7 ) {
		return true;
	}
	return false;
}


int main() {
    cout << "DiceGame!" << endl;

    int wins = 0;
    int times = 10;
    DiceGame game;

    for(int i = 0; i < times; i++){
    	cout << "play[" << i << "] = ";
		if(game.play()){
			wins++;
			cout << "won!" << endl;
		} else {
			cout << "lose!" << endl;
		}
    }
    cout << "Wins = " << wins << endl;
    cout << "Wins percentage " << wins/(double)times << endl;

	return 0;
}
