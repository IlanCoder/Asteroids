#pragma once
#include "ofMain.h"
#include "ofMath.h"

class Pixel {
private:
	ofTexture tex;
	ofPixels pix;
	ofColor col;
	bool cicle;
	int centerX, centerY;
public:
	void putPixel(int x, int y, int r, int g, int b);
	void getPixel();
	void init();
	void draw();
	void clearScrean();
	void setCenter(int x, int y);
	void setBGColor(int r, int g, int b);
	void setCicle(bool cicle);
};