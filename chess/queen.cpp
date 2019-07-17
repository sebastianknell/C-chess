//
//  queen.cpp
//  chess
//
//  Created by Sebastian Knell on 7/17/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#include "queen.hpp"

Queen::Queen(int x, int y, int p):Object() {
	name = 'Q';
	player = p;
	setPosX(x);
	setPosY(y);
}

bool Queen::canMove(int x, int y) {
	return true;
}
