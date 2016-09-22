#pragma once
#include "Pixel.h"

class Line {
private:
	Pixel pixel;
	bool filter;
	int red, green, blue;
	int val, dX, dY, a, b, d, changeLine;
	ofColor col;
	ofVec2f currPoint, center;
public:
	void init();
	void draw();
	void update();
	void createLine(int x1, int y1, int x2, int y2, int red, int green, int blue);
	void setColor(int r, int g, int b);
	void setPoint(int x, int y);
	void moveTo(int x, int y);
	void clearScreen();
	void setCenter(int x, int y);
	void setBGColor(int r, int g, int b);
	void setCicle(bool cicle);
	ofColor getColor();
};