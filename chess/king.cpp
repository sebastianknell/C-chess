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
	return true;
}
