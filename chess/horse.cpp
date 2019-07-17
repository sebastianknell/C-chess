//
//  horse.cpp
//  chess
//
//  Created by Sebastian Knell on 7/17/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#include "horse.hpp"

Horse::Horse(int x, int y, int p):Object() {
	name = 'H';
	player = p;
	setPosX(x);
	setPosY(y);
}

bool Horse::canMove(int x, int y) {
	return true;
}
