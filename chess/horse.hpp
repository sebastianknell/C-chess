//
//  horse.hpp
//  chess
//
//  Created by Sebastian Knell on 7/17/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#ifndef horse_hpp
#define horse_hpp

#include <stdio.h>
#include "objects.hpp"

class Horse : public Object {
public:
	Horse(int x, int y, int p);
	virtual ~Horse() {};
	bool canMove(int x, int y) override;
};

#endif /* horse_hpp */
