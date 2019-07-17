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

class Board {
	int size = 8;
	vector<vector<char>> board;
	vector<Object*> v1 = {new Rook(7, 0), new Rook(7, 7),
		new Bishop(7, 2), new Bishop(7, 5)
	};
public:
	Board();
	virtual ~Board() {};
	void moveObject();
	void removeObject();
	void checkmate();
	void drown();
	void printBoard();
	void updateBoard();
};

#endif /* board_hpp */

