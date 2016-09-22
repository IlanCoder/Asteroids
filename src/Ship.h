#pragma once
#include "Bullet.h"
#define AMMO 20
using namespace std;
class Ship {
public:
	Bullet bullets[AMMO];
	bool drawShip, rotShip, thrusters;
	Figure2D ship, thrust, death;
	Vec3 force;
	float shipAngle;

	void init(Line &line,float x, float y);
	void createShip(Line &line);
	void createThrust(Line &line);
	void createDeath(Line &line);
	void moveShip();
	void rotateShip();
	void zeroGrav();
	void shoot();
	void draw(Line &line, bool cicle);
};