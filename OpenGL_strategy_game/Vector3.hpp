#ifndef Vector3_H
#define Vector3_H

#include <iostream>
#include <math.h>

using namespace std;

class Vector3
{
public:
	Vector3();
	Vector3(float x_, float y_, float z_);

	void Add(Vector3& b);

	void Subtract(Vector3& b);

	void ScalarMultiplication(float s);

	float Mag();

	void Normalize();

	float Dot(Vector3& b);

	Vector3 Lerp(Vector3& b, float t);

	Vector3 Slerp(Vector3& b, float t);

	void Rotate(float angle_x, float angle_y, float angle_z);

	//Overloading the operators
	Vector3 operator*(const float f);
	Vector3 operator*(const Vector3& b);

	Vector3 operator+(const Vector3& b);
	Vector3 operator-(const Vector3& b);

	float x;
	float y;
	float z;
};

#endif 