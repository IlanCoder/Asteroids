#pragma once
#include "Line.h"
#include "Vec3.h"
#include "Mat3.h"
enum type { LINES, LINE_LOOP, TRIANGLE };
class Figure2D {
private:
	vector<Vec3> points;
	Mat3 transform;
public:
	Vec3 pos, scale;
	float angle;
	void init(Line &line);
	void update(Line &line,int type,bool cicle);
	void draw(Line &line);
	void setCenter(const int &x, const  int &y);
	void createRegPolygon(const int &sides,const float &radius);
	void addPoint(Vec3 newPoint);
	void drawFigure(int type, Line &line,vector<Vec3> drawPoints);
	void sierpinsky(Vec3 a, Vec3 b, Vec3 c,const int &level, Line &line);
	Vec3 midPoint(Vec3 a, Vec3 b);
	void setColor(float &r, float &g, float &b, Line &line);
	void setTransform();
	Vec3 getPoint(int point);
};