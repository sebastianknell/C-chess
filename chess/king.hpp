//
//  king.hpp
//  chess
//
//  Created by Sebastian Knell on 7/17/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#ifndef king_hpp
#define king_hpp

#include <stdio.h>
#include "objects.hpp"

class King : public Object {
public:
	King(int x, int y, int p);
	virtual ~King() {};
	bool canMove(int x, int y) override;
};

#endif /* king_hpp */
