#include "Bullet.h"

void Bullet::init(Line & line){
	drawBullet = false;
	createBullet(line);
}

void Bullet::createBullet(Line &line){
	bullet.init(line);
	bullet.createRegPolygon(8, 3);
}

void Bullet::shoot(Figure2D shooter){
	Vec3 pointer2 = shooter.getPoint(0);
	pointer2 = pointer2 - shooter.pos;
	pointer2.normalize();
	pointer2 = pointer2 * 10;
	direction = pointer2;
	bullet.setCenter(shooter.pos.vec3[0], shooter.pos.vec3[1]);
	drawBullet = true;
}

void Bullet::draw(Line & line,bool cicle){
	if (drawBullet) {
		bullet.pos = bullet.pos + direction;
		bullet.update(line, LINE_LOOP, cicle);
	}
}
