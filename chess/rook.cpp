//
//  rook.cpp
//  chess
//
//  Created by Sebastian Knell on 7/16/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#include "rook.hpp"

Rook::Rook(int x, int y, int p):Object() {
	name = 'R';
	player = p;
	setPosX(x);
	setPosY(y);
}

bool Rook::canMove(int x, int y) {
	if (!(x != posX) != !(y != posY))
		return true;
	return false;
}
