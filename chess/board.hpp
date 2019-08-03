//
//  board.hpp
//  chess
//
//  Created by Sebastian Knell on 7/16/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "objects.hpp"
#include "rook.hpp"
#include "Bishop.hpp"
#include "king.hpp"
#include "queen.hpp"
#include "pawn.hpp"
#include "horse.hpp"

class Board {
	int size = 8;
	vector<vector<char>> board;
	vector<Object*> v1 = {
		// Player 1
		new Rook(7, 0, 1), new Rook(7, 7, 1),
		new Bishop(7, 2, 1), new Bishop(7, 5, 1),
		new Horse(7, 1, 1), new Horse(7, 6, 1),
		new Queen(7, 3, 1), new King(7, 4, 1),
		new Pawn(6, 0, 1), new Pawn(6, 1, 1), new Pawn(6, 2, 1), new Pawn(6, 3, 1),
		new Pawn(6, 4, 1), new Pawn(6, 5, 1), new Pawn(6, 6, 1), new Pawn(6, 7, 1),
		// Player 2
		new Rook(0, 0, -1), new Rook(0, 7, -1),
		new Bishop(0, 2, -1), new Bishop(0, 5, -1),
		new Horse(0, 1, -1), new Horse(0, 6, -1),
		new Queen(0, 3, -1), new King(0, 4, -1),
		new Pawn(1, 0, -1), new Pawn(1, 1, -1), new Pawn(1, 2, -1), new Pawn(1, 3, -1),
		new Pawn(1, 4, -1), new Pawn(1, 5, -1), new Pawn(1, 6, -1), new Pawn(1, 7, -1)
	};
public:
	Board();
	virtual ~Board() {};
	void moveObject(Object* obj, int i, int j);
	bool validMove(Object* obj, int i, int j);
	void removeObject(Object* obj);
	void addObject(Object* obj);
	bool checkmate(int player);
	bool drown();
	bool check(int player);
	void printBoard();
	void updateBoard();
	Object* Search(int x, int y);
	Object* searchByName(char name, int player); // Only works for king and queen
	bool checkSpaces(int x, int y, int i, int j);
};

#endif /* board_hpp */

