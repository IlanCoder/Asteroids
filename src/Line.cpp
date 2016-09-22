#include "Line.h"

void Line::init(){
	pixel.init();
	center = ofVec2f(0, 0);
	red = 0;
	green = 0;
	blue = 0;
}

void Line::draw(){
	update();
	clearScreen();
	pixel.draw();
}

void Line::update(){
	pixel.getPixel();
}

void Line::createLine(int x1, int y1, int x2, int y2, int red, int green, int blue){
	//invert pixel locations if dX will be negative
	if (x1>x2) {
		int tempX = x1;
		int tempY = y1;
		x1 = x2;
		y1 = y2;
		x2 = tempX;
		y2 = tempY;
	}
	//inverts "y"s if dY would be negative
	if (y2 < y1) {
		dY = y1 - y2;
		val = -1;
	}else {
		dY = y2 - y1;
		val = 1;
	}
	dX = x2 - x1;
	//Detect if incline is bigger or smaller than 45°
	if (dY >= dX) {
		a = dX;
		b = -(dY);
		changeLine = x1;
		filter = true;
	}else {
		a = dY;
		b = -(dX);
		changeLine = y1;
		filter = false;
	}
	//sets inicial cons of line's dots offset
	d = 2 * a + b;
	pixel.putPixel(x1, y1, red, green, blue);
	//creates line if incline is lower than 45°
	if (!filter) {
		for (int x = x1 + 1; x <= x2; x++) {
			if (d < 0) {
				d += 2 * a;
			}else {
				d += 2 * a + 2 * b;
				changeLine += val;
			}
			pixel.putPixel(x, changeLine, red, green, blue);
		}
	}else {
		//creates line if incline is same or higher than 45°
		int ya;
		int yo = y2*val;
		for (int y = y1 + val; (ya = y*val) <=yo; y += val) {
			if (d < 0) {
				d += 2 * a;
			}else {
				d += 2 * a + 2 * b;
				x1++;
			}
			pixel.putPixel(x1, y, red, green, blue);
		}
	}
}

void Line::setColor(int r, int g, int b){
	col.set(r, g, b);
}

void Line::setPoint(int x, int y){
	currPoint.set(x, y);
}

void Line::moveTo(int x, int y){
	createLine(currPoint.x, currPoint.y, x, y, col.r, col.g, col.b);
	setPoint(x, y);
}

void Line::clearScreen(){
	pixel.clearScrean();
}

void Line::setCenter(int x, int y){
	pixel.setCenter(x, y);
}

void Line::setBGColor(int r, int g, int b){
	pixel.setBGColor(r, g, b);
}

void Line::setCicle(bool cicle){
	pixel.setCicle(cicle);
}

ofColor Line::getColor(){
	return col;
}
