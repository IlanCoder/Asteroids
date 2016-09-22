#pragma once
#include "Ship.h"
#define BIGAST 4
#define MIDAST 16
#define SMALLAST 64
class Asteroid {
public:
	Figure2D asteroid;
	bool drawAst;
	float angle;
	int divisions;
	Vec3 dir;
	void init(Line &line,int divisions);
	virtual void createAst(Line &line) = 0;
	void makeAst(Asteroid &fatherAst, Mat3 rot);
	void distroyAst();
	void modifyMove();
	void draw(Line &line,bool cicle);
	bool collisions(Ship &ship);
};