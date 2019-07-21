//
//  pawn.cpp
//  chess
//
//  Created by Sebastian Knell on 7/17/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#include "pawn.hpp"

Pawn::Pawn(int x, int y, int p):Object() {
	name = 'P';
	player = p;
	setPosX(x);
	setPosY(y);
}

bool Pawn::canMove(int x, int y) {
	if (getPlayer() == 1) {
		if (posX == 6 && (posX - x == 1 || posX - x == 2) && abs(posY - y) == 0)
			return true;
		else {
			if (posX - x == 1 && abs(posY - y) == 0)
				return true;
			return false;
		}
	}
	else {
		if (posX == 1 && (x - posX == 1 || x - posX == 2) && abs(posY - y) == 0)
			return true;
		else {
			if (x - posX == 1 && abs(posY - y) == 0)
				return true;
			return false;
		}
	}
}
