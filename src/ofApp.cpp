#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(200);
	cicle = true;
	line.init();
	line.setCenter(ofGetWidth() / 2, ofGetHeight() / 2);
	line.setCicle(cicle);
	ship1.init(line,-100,0);
	ship2.init(line,100,0);
	for (int i = 0; i < BIGAST; i++) {
		bigAst[i].init(line,4);
	}
	for (int i = 0; i < MIDAST; i++) {
		midAst[i].init(line, 4);
	}
	for (int i = 0; i < SMALLAST; i++) {
		smallAst[i].init(line, 4);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	ship1.draw(line, cicle);
	ship2.draw(line, cicle);
	for (int i = 0; i < BIGAST; i++) {
		bigAst[i].draw(line, cicle);
	}
	for (int i = 0; i < MIDAST; i++) {
		midAst[i].draw(line, cicle);
	}
	for (int i = 0; i < SMALLAST; i++) {
		smallAst[i].draw(line, cicle);
	}
	collisions();
	line.draw();
	cout << ofGetFrameRate() << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'w') {
		ship1.thrusters = true;
	}
	if (key == 'd') {
		ship1.rotShip = true;
		ship1.shipAngle = 18;
	}else if (key == 'a') {
		ship1.rotShip = true;
		ship1.shipAngle = -18;
	}
	if (key == ' ') {
		ship1.shoot();
	}
	if (key == OF_KEY_UP) {
		ship2.thrusters = true;
	}
	if (key == OF_KEY_RIGHT) {
		ship2.rotShip = true;
		ship2.shipAngle = 18;
	}
	else if (key == OF_KEY_LEFT) {
		ship2.rotShip = true;
		ship2.shipAngle = -18;
	}
	if (key == OF_KEY_CONTROL) {
		ship2.shoot();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 'w') {
		ship1.thrusters = false;
	}
	if (key == 'd') {
		ship1.rotShip = false;
	}
	if (key == 'a') {
		ship1.rotShip = false;
	}
	if (key == OF_KEY_UP) {
		ship2.thrusters = false;
	}
	if (key == OF_KEY_RIGHT) {
		ship2.rotShip = false;
	}
	else if (key == OF_KEY_LEFT) {
		ship2.rotShip = false;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
}

void ofApp::collisions(){
	for (int i = 0; i < BIGAST; i++) {
		if (bigAst[i].collisions(ship1)) {
			for (int j = 0; j < bigAst[i].divisions; j++) {
				Mat3 rot = Mat3(Vec3(cos(2 * PI / (bigAst[i].divisions*(j + 1))), -sin(2 * PI / (bigAst[i].divisions*(j + 1))), 0), Vec3(sin(2 * PI / (bigAst[i].divisions*(j + 1))), cos(2 * PI / (bigAst[i].divisions*(j + 1))), 0));
				midAst[bigAst[i].divisions * i + j].makeAst(bigAst[i],rot);
			}
		}if (bigAst[i].collisions(ship2)) {
			for (int j = 0; j < bigAst[i].divisions; j++) {
				Mat3 rot = Mat3(Vec3(cos(2 * PI / (bigAst[i].divisions*(j + 1))), -sin(2 * PI / (bigAst[i].divisions*(j + 1))), 0), Vec3(sin(2 * PI / (bigAst[i].divisions*(j + 1))), cos(2 * PI / (bigAst[i].divisions*(j + 1))), 0));
				midAst[bigAst[i].divisions * i + j].makeAst(bigAst[i], rot);
			}
		}
	}
	for (int i = 0; i < MIDAST; i++) {
		if (midAst[i].collisions(ship1)) {
			for (int j = 0; j < midAst[i].divisions; j++) {
				Mat3 rot = Mat3(Vec3(cos(2 * PI / (midAst[i].divisions*(j + 1))), -sin(2 * PI / (midAst[i].divisions*(j + 1))), 0), Vec3(sin(2 * PI / (midAst[i].divisions*(j + 1))), cos(2 * PI / (midAst[i].divisions*(j + 1))), 0));
				smallAst[midAst[i].divisions * i + j].makeAst(midAst[i], rot);
			}
		}if (midAst[i].collisions(ship2)) {
			for (int j = 0; j < midAst[i].divisions; j++) {
				Mat3 rot = Mat3(Vec3(cos(2 * PI / (midAst[i].divisions*(j + 1))), -sin(2 * PI / (midAst[i].divisions*(j + 1))), 0), Vec3(sin(2 * PI / (midAst[i].divisions*(j + 1))), cos(2 * PI / (midAst[i].divisions*(j + 1))), 0));
				smallAst[midAst[i].divisions * i + j].makeAst(midAst[i], rot);
			}
		}
	} 
	for (int i = 0; i < SMALLAST; i++) {
		smallAst[i].collisions(ship1);
		smallAst[i].collisions(ship2);
	}
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
