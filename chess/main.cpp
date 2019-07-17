//
//  main.cpp
//  chess
//
//  Created by Sebastian Knell on 7/16/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#include <iostream>
#include "board.hpp"

int main() {
	Board board1;
	int turn = 1;
	board1.updateBoard();
	board1.printBoard();
	while (true) {
		board1.moveObject(turn);
		board1.updateBoard();
		board1.printBoard();
		turn *= -1;
	}
	return 0;
}
