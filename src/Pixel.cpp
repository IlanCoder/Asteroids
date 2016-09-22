#include "Pixel.h"

void Pixel::putPixel(int x, int y, int r, int g, int b) {
	int posX = x + centerX;
	int posY = y + centerY;
	if (cicle) {
		if (posX > ofGetWidth()) {
			posX -= ofGetWidth();
		}
		else if (posX < 0) {
			posX += ofGetWidth();
		}
		if (posY > ofGetHeight()) {
			posY -= ofGetHeight();
		}
		else if (posY < 0) {
			posY += ofGetHeight();
		}
	}
	if (posX <= ofGetWidth() && posX >= 0) { //prevents from beign draws outside bitmap
		if (posY <= ofGetHeight() && posY >= 0) {
			pix.setColor(posX, posY, ofColor::white);
		}
	}
}

void Pixel::getPixel() {
	tex.loadData(pix);
}

void Pixel::init() {
	pix.allocate(ofGetWidth(), ofGetHeight(), OF_PIXELS_RGB);
	tex.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
}

void Pixel::draw() {
	tex.draw(0, 0);
}

void Pixel::clearScrean() {

	for (int i = 0; i < ofGetWidth(); i++){
		for (int j = 0; j < ofGetHeight(); j++) {
			pix.setColor(i, j, ofColor::black);
		}
	}
}

void Pixel::setCenter(int x, int y){
	centerX = x;
	centerY = y;
}

void Pixel::setBGColor(int r, int g, int b){
	col.set(r, g, b);
}

void Pixel::setCicle(bool cicle){
	this->cicle = cicle;
}
