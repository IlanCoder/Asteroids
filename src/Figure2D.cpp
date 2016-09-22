#include "Figure2D.h"

void Figure2D::init(Line &line){
	line.setColor(0, 0, 0);
	transform = Mat3();
	pos = Vec3(0, 0);
	angle = 0;
	scale = Vec3(1, 1);
}

void Figure2D::update(Line &line,int type,bool cicle){
	vector<Vec3>drawPoints = points;
	if (cicle) {
		if (pos.vec3[0] > ofGetWidth()) {
			pos.vec3[0] -= ofGetWidth();
		}
		else if (pos.vec3[0] < 0) {
			pos.vec3[0] += ofGetWidth();
		}
		if (pos.vec3[1] > ofGetHeight()) {
			pos.vec3[1] -= ofGetHeight();
		}
		else if (pos.vec3[1] < 0) {
			pos.vec3[1] += ofGetHeight();
		}
	}
	setTransform();
	for (int i = 0; i < points.size(); i++) {
		drawPoints[i] = transform*points[i];
	}
	drawFigure(type, line, drawPoints);
}

void Figure2D::draw(Line &line){
}

void Figure2D::setCenter(const int &x,const  int &y){
	pos = Vec3(x, y);
}

void Figure2D::createRegPolygon(const int &sides,const float &radius){
	Vec3 point = Vec3(0, 0);
	float angles;
	bool firstPoint = true;
	Vec3 initPoint;
	for (float angle = 0.0f; angle <= 2 * PI; angle += (2 * PI / sides)) {
		angles = radius*cos(angle);
		point.vec3[0] = angles;
		angles = radius*sin(angle);
		point.vec3[1] = angles;
		if (firstPoint) {
			points.push_back(Vec3(point.vec3[0], point.vec3[1]));
			initPoint=Vec3(point.vec3[0], point.vec3[1]);
			firstPoint = false;
		}
		else {
			points.push_back(Vec3(point.vec3[0], point.vec3[1]));
		}
	}
}

void Figure2D::addPoint(Vec3 newPoint){
	points.push_back(newPoint);
}

void Figure2D::drawFigure(int type, Line &line, vector<Vec3> drawPoints){
	switch (type) {
	case LINES:
		line.setPoint(drawPoints[0].vec3[0], drawPoints[0].vec3[1]);
		for (int i = 1; i < drawPoints.size(); i++) {
			line.moveTo(drawPoints[i].vec3[0], drawPoints[i].vec3[1]);
		}
		break;
	case LINE_LOOP:
		line.setPoint(drawPoints[0].vec3[0], drawPoints[0].vec3[1]);
		for (int i = 1; i < drawPoints.size(); i++) {
			line.moveTo(drawPoints[i].vec3[0], drawPoints[i].vec3[1]);
		}
		line.moveTo(drawPoints[0].vec3[0], drawPoints[0].vec3[1]);
		break;
	case TRIANGLE:
		for (int f = 0; f < drawPoints.size() - 2; f += 3) {
			line.setPoint(drawPoints[f].vec3[0], drawPoints[f].vec3[1]);
			for (int i = 0; i < 3; i++) {
				line.moveTo(drawPoints[f + i].vec3[0], drawPoints[f + i].vec3[1]);
			}
			line.moveTo(drawPoints[f].vec3[0], drawPoints[f].vec3[1]);
		}
		break;
	}
}

void Figure2D::sierpinsky(Vec3 a, Vec3 b, Vec3 c,const int &level, Line &line){
	if (level == 0) {
		points.push_back(a);
		points.push_back(b);
		points.push_back(c);
		return;
	}
	else {
		Vec3 ab = midPoint(a, b);
		Vec3 bc = midPoint(b, c);
		Vec3 ca = midPoint(c, a);
		sierpinsky(a, ab, ca, level - 1,line);
		sierpinsky(ab, b, bc, level - 1,line);
		sierpinsky(ca, bc, c, level - 1,line);
	}
	drawFigure(TRIANGLE,line,points);
}

Vec3 Figure2D::midPoint(Vec3 a, Vec3 b){
	Vec3 v;
	v=Vec3((a.vec3[0] + b.vec3[0]) / 2, (a.vec3[1] + b.vec3[1]) / 2);
	return v;
}

void Figure2D::setColor(float &r, float &g, float &b, Line &line){
	line.setColor(r,g,b);
}

void Figure2D::setTransform(){
	Mat3 scaleM = Mat3(Vec3(scale.vec3[0], 0, 0), 
		Vec3(0, scale.vec3[1], 0));
	Mat3 rotM = Mat3(Vec3(cos(angle/180),-sin(angle/180),0),
		Vec3(sin(angle / 180), cos(angle / 180),0));
	Mat3 transM = Mat3(Vec3(1,0,pos.vec3[0]),
		Vec3(0,1,pos.vec3[1]));
	transform = transM*rotM*scaleM;
}

Vec3 Figure2D::getPoint(int point){
	setTransform();
	Vec3 vec=transform*points.at(point);
	return vec;
}
