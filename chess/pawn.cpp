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
	return true;
}
