#pragma once
#include "Vec4.h"

class Mat4 {
public:
	float mat4[4][4];
	Mat4();
	Mat4(Vec4 &vec1, Vec4 &vec2, Vec4 &vec3,Vec4 &vec4=Vec4(0,0,0));
	Mat4 operator *(Mat4 &right);
	Vec4 operator *(Vec4 &right);
	Mat4 rotateX(const float angle);
	Mat4 rotateY(const float angle);
	Mat4 rotateZ(const float angle);
	Mat4 translate(const float x, const float y,const float z);
	Mat4 shear(const float x, const float y,const float z);
	Mat4 scale(const float x, const float y, const float z);
	Mat4 lookAt(Vec4 &eye, Vec4 &target, Vec4 &up);
	Mat4 perspective(float &angle, float &aspect, float &near, float &far);
	Mat4 ortho(float &near, float &far, float &left, float &right, float &top, float &bottom);
};
