#include "BigAst.h"

void BigAst::createAst(Line & line){
	drawAst = true;
	asteroid.init(line);
	asteroid.createRegPolygon(10, 40);
}
