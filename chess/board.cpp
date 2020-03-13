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
	// Fill with dots
	for (auto &row : board) {
		for (auto &item : row)
			item = '.';
	}
	// Insert objects
	for (auto &item : v1)
		board[item->getPosX()][item->getPosY()] = item->getName();
}

void Board::printBoard() {
	cout << "\n        Player  2        \n";
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
	cout << "\n        Player  1        \n";
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
	return nullptr;
}
// MARK: FIX
bool Board::validMove(Object *obj, int i, int j) {
	int x0 = obj->getPosX();
	int y0 = obj->getPosY();
	Object* target = Search(i, j);
	// You can't eat objects from your team
	if (target != nullptr && target->getPlayer() == obj->getPlayer())
		return false;
	
	if ((obj->canMove(i, j) && checkSpaces(x0, y0, i, j)) ||
		// Pawns eat in a different way than they move
		(obj->getName() == 'P' && obj->canEat(i, j) && target != nullptr)) {
			// Will the player be in check if the object moves?
		bool v = true;
		moveObject(obj, i, j);
		removeFromBoard(target);
		updateBoard();
		if (check(obj->getPlayer()))
			v = false;
		// Put the things as they were
		moveObject(obj, x0, y0);
		addObject(target);
		updateBoard();
		return v;
	}
	return false;
}

bool Board::check(int player) {
	Object* king = searchByName('K', player);
	int i = king->getPosX();
	int j = king->getPosY();
	for (auto &item : v1) {
		if (item->getPlayer() == player*-1 && item->canMove(i, j) &&
			checkSpaces(item->getPosX(), item->getPosY(), i, j))
			return true;
	}
	return false;
}

Object* Board::searchByName(char name, int player) {
	// Only works for king and queen
	for (auto &item : v1) {
		if (item->getName() == name && item->getPlayer() == player)
			return item;
	}
	return nullptr;
}

// To not skip objects
bool Board::checkSpaces(int x0, int y0, int i, int j) {
	// Bottom right
	if (i > x0 && j > y0) {
		for (int x = x0 + 1, y = y0 + 1; x < i && y < j; x++, y++) {
			if (board[x][y] != '.')
				return false;
		}
	}
	// Top left
	if (i < x0 && j < y0) {
		for (int x = x0 - 1, y = y0 - 1; x > i && y > j; x--, y--) {
			if (board[x][y] != '.')
				return false;
		}
	}
	// Bottom left
	if (i > x0 && j < y0) {
		for (int x = x0 + 1, y = y0 - 1; x < i && y > j; x++, y--) {
			if (board[x][y] != '.')
				return false;
		}
	}
	// Top right
	if (i < x0 && j > y0) {
		for (int x = x0 - 1, y = y0 + 1; x > i && y < j; x--, y++) {
			if (board[x][y] != '.')
				return false;
		}
	}
	// Up or down
	if (j == y0) {
		// Up
		if (i < x0) {
			for (int x = x0 - 1; x > i; x--) {
				if (board[x][y0] != '.')
					return false;
			}
		}
		// Down
		else {
			for (int x = x0 + 1; x < i; x++) {
				if (board[x][y0] != '.')
					return false;
			}
		}
	}
	// Left or right
	if (i == x0) {
		// Left
		if (j < y0) {
			for (int y = y0 - 1; y > j; y--) {
				if (board[x0][y] != '.')
					return false;
			}
		}
		// Right
		else {
			for (int y = y0 + 1; y < j; y++) {
				if (board[x0][y] != '.')
					return false;
			}
		}
	}
	return true;
}
// Could be shorter
void Board::removeFromBoard(Object* obj) {
	if (obj != nullptr) {
		for (int i = 0; i < v1.size(); i++) {
			if (v1[i]->getPosX() == obj->getPosX() && v1[i]->getPosY() == obj->getPosY()
				&& v1[i]->getPlayer() == obj->getPlayer())
				v1.erase(v1.begin() + i);
		}
	}
}

void Board::addObject(Object *obj) {
	if (obj != nullptr)
		v1.emplace_back(obj);
}

bool Board::checkmate(int player) {
	return false;
}
