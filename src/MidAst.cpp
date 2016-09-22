#include "MidAst.h"

void MidAst::createAst(Line & line){
	drawAst = false;
	asteroid.init(line);
	asteroid.addPoint(Vec3(-5, -20));
	asteroid.addPoint(Vec3(-20, 7));
	asteroid.addPoint(Vec3(-16, 9));
	asteroid.addPoint(Vec3(0, 12));
	asteroid.addPoint(Vec3(-8, 16));
	asteroid.addPoint(Vec3(3, 20));
	asteroid.addPoint(Vec3(7, 9));
	asteroid.addPoint(Vec3(20, 7));
	asteroid.addPoint(Vec3(20, -10));
}
