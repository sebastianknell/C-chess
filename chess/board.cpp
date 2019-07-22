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
	cout << "\n   ";
	for (int i = 0; i < size; i++)
		cout << i << "  ";
	cout << "\n\n";
	int i = 0;
	for (auto &row : board) {
		cout << i << "  ";
		for (auto &item : row) {
			cout << item << "  ";
		}
		i++;
		cout << "\n";
	}
	cout << "\n\n";
}

void Board::moveObject() {
	int x, y, i, j;
	Object* obj = nullptr;
	do {
		cout << "Object position (row, column): \n";
		cin >> x;
		cin >> y;
		obj = Search(x, y);
	}while(obj == nullptr || obj->getPlayer() != turn); // Change
	
	cout << "Destination position (row, column): \n";
	do {
		cin >> i;
		cin >> j;
	}while(i > 7 || i < 0 || j > 7 || j < 0);
	
	if (obj->canMove(i, j)) {
		obj->setPosX(i);
		obj->setPosY(j);
		//turn *= -1;
	}
	else
		cout << "Invalid move\n";
}

Object* Board::Search(int x, int y) {
	for (auto &item : v1) {
		if (item->getPosX() == x && item->getPosY() == y)
			return item;
	}
	cout << "There's no object in that position\n";
	return nullptr;
}
