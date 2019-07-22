//
//  game.cpp
//  chess
//
//  Created by Sebastian Knell on 7/21/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#include "game.hpp"

void Game::execute() {
	board1.updateBoard();
	board1.printBoard();
	board1.moveObject();
}
