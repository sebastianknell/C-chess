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
			item = '0';
	}
	// Insert objects
	for (auto &item : v1)
		board[item->getPosX()][item->getPosY()] = item->getName();
}

void Board::printBoard() {
	// Whole board
	cout << "\n";
	for (auto &row : board) {
		for (auto &item : row)
			cout << item << "  ";
		cout << "\n";
	}
	cout << "\n\n";
}
