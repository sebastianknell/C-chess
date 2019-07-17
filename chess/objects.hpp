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
	char name;
	int posX, posY, player;
public:
	Object() {};
	virtual ~Object() {};
	void setPosX(int x) {posX = x;};
	void setPosY(int y) {posY = y;};
	int getPosX() {return posX;};
	int getPosY() {return posY;};
	char getName() {return name;};
	int getPlayer() {return player;};
	virtual bool canMove(int x, int y) = 0;
	void eat();
};

#endif /* objects_hpp */
