//
//  objects.hpp
//  chess
//
//  Created by Sebastian Knell on 7/16/19.
//  Copyright © 2019 Sebastian Knell. All rights reserved.
//

#ifndef objects_hpp
#define objects_hpp

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class Object {
protected:
	string name;
public:
	Object(string name);
	virtual ~Object();
	void canMove();
	void eat();
};

#endif /* objects_hpp */
