//
//  Bishop.cpp
//  chess
//
//  Created by Sebastian Knell on 7/16/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#include "Bishop.hpp"

Bishop::Bishop(int x, int y, int p):Object() {
	name = 'B';
	player = p;
	setPosX(x);
	setPosY(y);
}

bool Bishop::canMove(int x, int y) {
	if (abs(posX - x) == abs(posY - y) && posX != x && posY != y)
		return true;
	return false;
}

bool Bishop::canEat(int x, int y) {
	return true;
}
