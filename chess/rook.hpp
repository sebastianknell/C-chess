//
//  rook.hpp
//  chess
//
//  Created by Sebastian Knell on 7/16/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#ifndef rook_hpp
#define rook_hpp

#include <stdio.h>
#include "objects.hpp"

class Rook : public Object {
public:
	Rook(int x, int y);
	virtual ~Rook() {};
	bool canMove(int x, int y) override;
};

#endif /* rook_hpp */
