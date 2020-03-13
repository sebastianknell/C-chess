//
//  game.cpp
//  chess
//
//  Created by Sebastian Knell on 7/21/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#include "game.hpp"

void Game::execute() {
	do {
		board1.updateBoard();
		board1.printBoard();
		takeTurn();
	}while (!board1.checkmate(turn));
}

void Game::takeTurn() {
	int x0, y0, i, j;
	Object* obj = nullptr;
	Object* target = nullptr;

	if (turn == 1)
		cout << "It's player 1 turn\n";
	else
		cout << "It's player 2 turn\n";
	
	if (board1.check(turn)) {
		cout << "You're in check\n";
		askPosition(obj);
		askDestination(i, j);
		target = board1.Search(i, j);
		x0 = obj->getPosX();
		y0 = obj->getPosY();
//		MARK: FIX
		if (board1.validMove(obj, i, j)) { // Doesn't work yet
			board1.moveObject(obj, i, j);
			board1.removeFromBoard(target);
			board1.updateBoard();
			// Check whether it's still in check
			if (board1.check(turn)) {
				// Put things as they were
				board1.moveObject(obj, x0, y0);
				board1.addObject(target);
				cout << "Invalid move2\n";
				return;
			}
			delete target;
			turn *= -1;
		}
		else
			cout << "Invalid move1\n";
	}
	else {
		askPosition(obj);
		askDestination(i, j);
		target = board1.Search(i, j);
		if (board1.validMove(obj, i, j)) {
			board1.moveObject(obj, i, j);
			deleteObject(target);
			turn *= -1;
		}
		else
			cout << "Invalid move\n";
	}
}

bool Game::checkTurn(Object* obj) {
	if (obj->getPlayer() == turn)
		return true;
	cout << "It's the other player's turn\n";
	return false;
}

void Game::askPosition(Object* &obj) {
	int x, y;
	do {
		cout << "Object position (row, column): \n";
		cin >> x;
		cin >> y;
		obj = board1.Search(x, y);
		if (obj == nullptr)
			cout << "There's no object in that position\n";
	}while(obj == nullptr || checkTurn(obj) == false);
}

void Game::askDestination(int &i, int &j) {
	do {
		cout << "Destination position (row, column): \n";
		cin >> i;
		cin >> j;
	}while(i > 7 || i < 0 || j > 7 || j < 0);
}

void Game::deleteObject(Object* target) {
	if (target != nullptr) {
		board1.removeFromBoard(target);
		delete target;
	}
}
