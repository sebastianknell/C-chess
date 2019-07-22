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
	void moveObject();
	void execute();
};

#endif /* game_hpp */
