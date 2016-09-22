#pragma once
#include "Figure2D.h"
class Bullet {
public:
	Vec3 direction;
	bool drawBullet;
	Figure2D bullet;

	void init(Line &line);
	void createBullet(Line &line);
	void shoot(Figure2D shooter);
	void draw(Line &line,bool cicle);
};