#include "Ship.h"

void Ship::init(Line & line, float x, float y){
	createShip(line);
	createThrust(line);
	createDeath(line);
	for (int i = 0; i < AMMO; i++) {
		bullets[i].init(line);
	}
	ship.pos = Vec3(x, y);
	thrust.pos = Vec3(x, y);
	death.pos = Vec3(x, y);
	drawShip = true;
}

void Ship::createShip(Line & line){
	ship.init(line);
	ship.addPoint(Vec3(0, -20));
	ship.addPoint(Vec3(-10, 20));
	ship.addPoint(Vec3(0, 10));
	ship.addPoint(Vec3(10, 20));
}

void Ship::createThrust(Line & line){
	thrust.init(line);
	thrust.addPoint(Vec3(-10, 20));
	thrust.addPoint(Vec3(-5, 30));
	thrust.addPoint(Vec3(0, 20));
	thrust.addPoint(Vec3(5, 30));
	thrust.addPoint(Vec3(10, 20));
}

void Ship::createDeath(Line & line){
	death.init(line);
	death.addPoint(Vec3(0,-20));
	death.addPoint(Vec3(-4, -10));
	death.addPoint(Vec3(-16, -16));
	death.addPoint(Vec3(-10, -4));
	death.addPoint(Vec3(-20, 0));
	death.addPoint(Vec3(-10, 4));
	death.addPoint(Vec3(-16, 16));
	death.addPoint(Vec3(-4, 10));
	death.addPoint(Vec3(0, 20));
	death.addPoint(Vec3(4, 10));
	death.addPoint(Vec3(16, 16));
	death.addPoint(Vec3(10, 4));
	death.addPoint(Vec3(20, 0));
	death.addPoint(Vec3(10, -2));
	death.addPoint(Vec3(16, -16));
	death.addPoint(Vec3(4, -10));
}

void Ship::moveShip(){
	Vec3 pointer = ship.getPoint(0);
	pointer = pointer - ship.pos;
	pointer.normalize();
	pointer = pointer * 2;
	force = force + pointer;
	if (force.getMagnitude() >= 5) {
		float fMag = force.getMagnitude();
		force.normalize();
		force = force*fMag;
	}
	ship.pos = ship.pos + pointer;
	thrust.pos = thrust.pos + pointer;
	death.pos = death.pos + pointer;
}

void Ship::rotateShip(){
	ship.angle += shipAngle;
	thrust.angle += shipAngle;
	death.angle += shipAngle;
}

void Ship::zeroGrav(){
	ship.pos = ship.pos + force;
	thrust.pos = thrust.pos + force;
	death.pos = death.pos + force;
}

void Ship::shoot(){
	if (drawShip) {
		for (int i = 0; i < AMMO; i++) {
			if (!bullets[i].drawBullet) {
				bullets[i].shoot(ship);
				return;
			}
		}
	}
}

void Ship::draw(Line & line, bool cicle){
	for (int i = 0; i < AMMO; i++) {
		bullets[i].draw(line, cicle);
	}
	if (drawShip) {
		zeroGrav();
		if (rotShip) {
			rotateShip();
		}
		if (thrusters) {
			moveShip();
			thrust.update(line, LINES, cicle);
		}
		ship.update(line, LINE_LOOP, cicle);
	}
	else {
		death.update(line, LINE_LOOP, cicle);
	}
}
