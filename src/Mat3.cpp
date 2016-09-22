#include "Mat3.h"

Mat3::Mat3(){
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) {
				mat3[i][j] = 1;
			}
			else {
				mat3[i][j] = 0;
			}
		}
	}
}

Mat3::Mat3(Vec3 &vec1, Vec3 &vec2, Vec3 &vec3){
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {	
			if (i == 0) {
				mat3[i][j] = vec1.vec3[j];
			}
			else if (i == 1) {	
				mat3[i][j] = vec2.vec3[j];
			}
			else {
				mat3[i][j] = vec3.vec3[j];
			}
		}
	}
}

Mat3 Mat3::operator+(Mat3 & right){
	Mat3 matR;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matR.mat3[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				matR.mat3[i][j] = mat3[i][j] + right.mat3[i][j];
			}
		}
	}
	return matR;
}

Mat3 Mat3::operator*(Mat3 &right){
	Mat3 matR;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matR.mat3[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				matR.mat3[i][j] += mat3[i][k] * right.mat3[k][j];
			}
		}
	}
	return matR;
}

Vec3 Mat3::operator*(Vec3 &right){
	Vec3 vecR = Vec3(0, 0, 0);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			vecR.vec3[i] += mat3[i][j] * right.vec3[j];
		}
	}
	return vecR;
}

Mat3 Mat3::rotate(const float angle){
	float rad = angle / 180;
	Mat3 rm = Mat3(Vec3(cos(rad), -sin(rad), 0), Vec3(sin(rad), cos(rad), 0));
	Mat3 ma = Mat3(Vec3(mat3[0][0], mat3[0][1], mat3[0][2]), 
		Vec3(mat3[1][0], mat3[1][1], mat3[1][2]), 
		Vec3(mat3[2][0], mat3[2][1], mat3[2][2]));
	return rm*ma;
}

Mat3 Mat3::translate(const float x,const float y){
	Mat3 tm = Mat3(Vec3(1, 0, x), Vec3(0, 1, y));
	Mat3 ma = Mat3(Vec3(mat3[0][0], mat3[0][1], mat3[0][2]), 
		Vec3(mat3[1][0], mat3[1][1], mat3[1][2]), 
		Vec3(mat3[2][0], mat3[2][1], mat3[2][2]));
	return tm*ma;
}

Mat3 Mat3::shear(const float x, const float y){
	Mat3 sm = Mat3(Vec3(1, x, 0), Vec3(y, 1, 0));
	Mat3 ma = Mat3(Vec3(mat3[0][0], mat3[0][1], mat3[0][2]), 
		Vec3(mat3[1][0], mat3[1][1], mat3[1][2]), 
		Vec3(mat3[2][0], mat3[2][1], mat3[2][2]));
	return sm*ma;
}

Mat3 Mat3::scale(const float x, const float y){
	Mat3 sm = Mat3(Vec3(x, 0, 0), Vec3(0, y, 0));
	Mat3 ma = Mat3(Vec3(mat3[0][0], mat3[0][1], mat3[0][2]), 
		Vec3(mat3[1][0], mat3[1][1], mat3[1][2]), 
		Vec3(mat3[2][0], mat3[2][1], mat3[2][2]));
	return sm*ma;
}
