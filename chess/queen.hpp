//
//  queen.hpp
//  chess
//
//  Created by Sebastian Knell on 7/17/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#ifndef queen_hpp
#define queen_hpp

#include <stdio.h>
#include "objects.hpp"

class Queen : public Object {
public:
	Queen(int x, int y, int p);
	virtual ~Queen() {};
	bool canMove(int x, int y) override;
};

#endif /* queen_hpp */
