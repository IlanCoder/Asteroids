#pragma once
#include "Vec3.h"

using namespace std;
class Mat3 {
public:
	float mat3[3][3];
	Mat3();
	Mat3(Vec3 &vec1, Vec3 &vec2, Vec3 &vec3=Vec3(0,0));
	Mat3 operator +(Mat3 &right);
	Mat3 operator *(Mat3 &right);
	Vec3 operator *(Vec3 &right);
	Mat3 rotate(const float angle);
	Mat3 translate(const float x,const float y);
	Mat3 shear(const float x, const float y);
	Mat3 scale(const float x,const float y);
};