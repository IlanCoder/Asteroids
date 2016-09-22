#include "Vec4.h"

Vec4::Vec4() {
	vec4[0] = 0;
	vec4[1] = 0;
	vec4[2] = 0;
	vec4[3] = 1;
}

Vec4::Vec4(const float &x,const float &y,const float &z, const float &w) {
	vec4[0] = x;
	vec4[1] = y;
	vec4[2] = z;
	vec4[3] = w;
}

Vec4 Vec4::operator+(Vec4 &right){
	return Vec4(vec4[0] + right.vec4[0], vec4[1] + right.vec4[1], vec4[2] + right.vec4[2]);
}

Vec4 Vec4::operator-(Vec4 &right){
	return Vec4(vec4[0] - right.vec4[0], vec4[1] - right.vec4[1], vec4[2] - right.vec4[2]);
}

Vec4 Vec4::operator*(Vec4 &right){
	return Vec4(vec4[0] * right.vec4[0], vec4[1] * right.vec4[1], vec4[2] * right.vec4[2]);
}
Vec4 Vec4::operator*(const float &num){
	return Vec4(vec4[0] * num, vec4[1] * num, vec4[2] * num);
}

Vec4 Vec4::operator/(const float & num){
	return Vec4(vec4[0] / num, vec4[1] / num, vec4[2] / num);
}

void Vec4::normalize(){
	Vec4 vec = Vec4(vec4[0], vec4[1], vec4[2],vec4[3]);
	float length = sqrt(pow(vec.vec4[0], 2) + pow(vec.vec4[1], 2) + pow(vec.vec4[2], 2) + pow(vec.vec4[3], 2));
	for (int i = 0; i < 4; i++) {
		vec4[i] = vec4[i]/length;
	}
}

Vec4 Vec4::normalize(Vec4 &vec){
	float length = sqrt(pow(vec.vec4[0], 2) + pow(vec.vec4[1], 2) + pow(vec.vec4[2], 2) + pow(vec.vec4[3], 2));
	for (int i = 0; i < 4; i++) {
		vec.vec4[i] /= length;
	}
	return vec;
}

float Vec4::point(Vec4 &vec){
	float point = 0;
	for (int i = 0; i < 4; i++) {
		point += vec4[i] * vec.vec4[i];
	}
	return point;
}

Vec4 Vec4::cross(Vec4 &vec){
	Vec4 temp;
	temp.vec4[0] = vec4[1] * vec.vec4[2] - (vec4[2] * vec.vec4[1]);
	temp.vec4[1] = vec4[0] * vec.vec4[2] - (vec4[2] * vec.vec4[0]);
	temp.vec4[2] = vec4[0] * vec.vec4[1] - (vec4[1] * vec.vec4[0]);
	return temp;
}

float Vec4::getMagnitude(){
	return  sqrt(pow(vec4[0], 2) + pow(vec4[1], 2) + pow(vec4[2], 2) + pow(vec4[3], 2));
}
