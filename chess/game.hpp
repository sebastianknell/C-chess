//
//  game.hpp
//  chess
//
//  Created by Sebastian Knell on 7/21/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <iostream>
#include "board.hpp"

class Game {
	int turn = 1;
	int windowSize;
	Board board1;
public:
	int getTurn() {return turn;};
	void takeTurn();
	bool checkTurn(Object* obj);
	void execute();
	void askPosition(Object* &obj);
	void askDestination(int &i, int &j);
	void deleteObject(Object* target);
};

#endif /* game_hpp */
