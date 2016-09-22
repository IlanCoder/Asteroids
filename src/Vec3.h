#pragma once
#include <iostream>

using namespace std;
class Vec3 {
public:
	float vec3[3];
	Vec3();
	Vec3(const float &x, const float &y, const float &z = 1);
	Vec3 operator +(Vec3 &right);
	Vec3 operator -(Vec3 &right);
	Vec3 operator *(Vec3 &right);
	Vec3 operator *(const float &num);
	Vec3 operator /(const float &num);
	void normalize();
	Vec3 normalize(Vec3 &vec);
	float point(Vec3 &vec);
	Vec3 cross(Vec3 &vec);
	float getMagnitude();
};