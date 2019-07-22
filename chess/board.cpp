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

void Board::moveObject(Object* obj, int i, int j) {
	obj->setPosX(i);
	obj->setPosY(j);
}

Object* Board::Search(int x, int y) {
	for (auto &item : v1) {
		if (item->getPosX() == x && item->getPosY() == y)
			return item;
	}
	cout << "There's no object in that position\n";
	return nullptr;
}

bool Board::validMove(Object *obj, int i, int j) {
	if (obj->canMove(i, j))
		return true;
	return false;
}
