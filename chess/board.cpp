//
//  board.cpp
//  chess
//
//  Created by Sebastian Knell on 7/16/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#include "board.hpp"

Board::Board() {
	board.resize(size);
	for (auto &row : board)
		row.resize(size);
}


void Board::updateBoard() {
	// Fill with 0's
	for (auto &row : board) {
		for (auto &item : row)
			item = '.';
	}
	// Insert objects
	for (auto &item : v1)
		board[item->getPosX()][item->getPosY()] = item->getName();
}

void Board::printBoard() {
	cout << "\n";
	for (auto &row : board) {
		for (auto &item : row)
			cout << item << "  ";
		cout << "\n";
	}
	cout << "\n\n";
}

void Board::moveObject(int turn) {
	int x, y, i, j;
	Object* obj = nullptr;
	do {
		cout << "Object position (x, y): \n";
		cin >> x;
		cin >> y;
		obj = Search(x, y);
	}while(obj == nullptr || obj->getPlayer() != turn); // Change
	
	cout << "Destination position (x, y): \n";
	cin >> i;
	cin >> j;
	
	if (obj->canMove(i, j)) {
		obj->setPosX(i);
		obj->setPosY(j);
	}
}

Object* Board::Search(int x, int y) {
	for (auto &item : v1) {
		if (item->getPosX() == x && item->getPosY() == y)
			return item;
	}
	cout << "There's no object in that position\n";
	return nullptr;
}
