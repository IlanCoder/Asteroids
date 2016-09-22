#include "Asteroid.h"

void Asteroid::init(Line & line,int divisions){
	angle = ofRandom(-20, 20);
	dir = Vec3(ofRandom(-10, 10), (ofRandom(-10, 10)));
	dir.normalize();
	dir = dir * 5;
	this->divisions = divisions;
	createAst(line);
	asteroid.setCenter(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
}

void Asteroid::makeAst(Asteroid &fatherAst,Mat3 rot){
	drawAst = true;
	dir = rot*fatherAst.dir * 1.5;
	angle = fatherAst.angle * 1.5;
	asteroid.setCenter(fatherAst.asteroid.pos.vec3[0], fatherAst.asteroid.pos.vec3[1]);
}

void Asteroid::distroyAst(){
	drawAst = false;
}

void Asteroid::modifyMove(){
	asteroid.angle += angle;
	asteroid.pos = asteroid.pos + dir;
}

void Asteroid::draw(Line & line, bool cicle){
	if (drawAst) {
		modifyMove();
		asteroid.update(line, LINE_LOOP, cicle);
	}
}

bool Asteroid::collisions(Ship &ship){
	if (drawAst) {
		Vec3 vec = asteroid.getPoint(0);
		vec = vec - asteroid.pos;
		float rangeAst = vec.getMagnitude();
		for (int j = 0; j < AMMO; j++) {
			if (ship.bullets[j].drawBullet) {
			vec = ship.bullets[j].bullet.getPoint(0);
			vec = vec - ship.bullets[j].bullet.pos;
			float rangeBul = vec.getMagnitude();
			float totalRange=ofDist(ship.bullets[j].bullet.pos.vec3[0], ship.bullets[j].bullet.pos.vec3[1], asteroid.pos.vec3[0], asteroid.pos.vec3[1]);
			if (totalRange <= rangeBul + rangeAst) {
				distroyAst();
				ship.bullets[j].drawBullet = false;
				return true;
				}
			}
		}
		if (ship.drawShip) {
			vec = ship.ship.getPoint(1);
			vec = vec - ship.ship.pos;
			float rangeShip = vec.getMagnitude();
			float totalRange = ofDist(ship.ship.pos.vec3[0], ship.ship.pos.vec3[1], asteroid.pos.vec3[0], asteroid.pos.vec3[1]);
			if (totalRange <= rangeShip + rangeAst) {
				ship.drawShip = false;
				return false;
			}
		}
	}
	return false;
}
