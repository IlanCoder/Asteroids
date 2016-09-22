#pragma once
#include <iostream>

using namespace std;
class Vec4 {
public:
	float vec4[4];
	Vec4();
	Vec4(const float &x, const float &y, const float &z, const float &w=1);
	Vec4 operator +(Vec4 &right);
	Vec4 operator -(Vec4 &right);
	Vec4 operator *(Vec4 &right);
	Vec4 operator *(const float &num);
	Vec4 operator /(const float &num);
	void normalize();
	Vec4 normalize(Vec4 &vec);
	float point(Vec4 &vec);
	Vec4 cross(Vec4 &vec);
	float getMagnitude();
};