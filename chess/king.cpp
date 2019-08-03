//
//  king.cpp
//  chess
//
//  Created by Sebastian Knell on 7/17/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#include "king.hpp"

King::King(int x, int y, int p):Object() {
	name = 'K';
	player = p;
	setPosX(x);
	setPosY(y);
}

bool King::canMove(int x, int y) {
	if ((abs(posX - x) <= 1 && abs(posY - y) <= 1))
		return true;
	if (posX == x && posY == y)
		return false;
	return false;
}

bool King::canEat(int x, int y) {
	return true;
}
