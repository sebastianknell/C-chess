//
//  pawn.hpp
//  chess
//
//  Created by Sebastian Knell on 7/17/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#ifndef pawn_hpp
#define pawn_hpp

#include <stdio.h>
#include "objects.hpp"

class Pawn : public Object {
public:
	Pawn(int x, int y, int p);
	virtual ~Pawn() {};
	bool canMove(int x, int y) override;
};

#endif /* pawn_hpp */
