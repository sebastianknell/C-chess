//
//  game.cpp
//  chess
//
//  Created by Sebastian Knell on 7/21/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#include "game.hpp"

void Game::execute() {
	while (true) {
		board1.updateBoard();
		board1.printBoard();
		takeTurn();
	}
}

void Game::takeTurn() {
	if (turn == 1)
		cout << "It's player 1 turn\n";
	else
		cout << "It's player 2 turn\n";
	
	int x, y, i, j;
	Object* obj = nullptr;
	
	do {
		cout << "Object position (row, column): \n";
		cin >> x;
		cin >> y;
		obj = board1.Search(x, y);
	}while(obj == nullptr || checkTurn(obj) == false); // Change
	
	do {
		cout << "Destination position (row, column): \n";
		cin >> i;
		cin >> j;
	}while(i > 7 || i < 0 || j > 7 || j < 0);
	
	if (board1.validMove(obj, i, j)) {
		board1.moveObject(obj, i, j);
		turn *= -1;
	}
	else
		cout << "Inavlid move\n";
}

bool Game::checkTurn(Object* obj) {
	if (obj->getPlayer() == turn)
		return true;
	cout << "It's the other player's turn\n";
	return false;
}
