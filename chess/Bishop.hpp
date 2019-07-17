//
//  Bishop.hpp
//  chess
//
//  Created by Sebastian Knell on 7/16/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#ifndef Bishop_hpp
#define Bishop_hpp

#include <stdio.h>
#include "objects.hpp"

class Bishop : public Object {
public:
	Bishop(int x, int y, int p);
	virtual ~Bishop() {};
	bool canMove(int x, int y) override;
};

#endif /* Bishop_hpp */
