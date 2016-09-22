#include "SmallAst.h"

void SmallAst::createAst(Line & line){
	drawAst = false;
	asteroid.init(line);
	asteroid.addPoint(Vec3(0, -5));
	asteroid.addPoint(Vec3(-10, -10));
	asteroid.addPoint(Vec3(-10, -3));
	asteroid.addPoint(Vec3(-3, 0));
	asteroid.addPoint(Vec3(-10, 3));
	asteroid.addPoint(Vec3(0, 10));
	asteroid.addPoint(Vec3(5, 6));
	asteroid.addPoint(Vec3(10, 7));
	asteroid.addPoint(Vec3(10, -10));
}
