//
//  board.hpp
//  chess
//
//  Created by Sebastian Knell on 7/16/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include "objects.hpp"
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class Board {
	int size = 8;
	vector<int> board = {0};
	vector<Object*> objects;
public:
	Board();
	virtual ~Board();
};

#endif /* board_hpp */
