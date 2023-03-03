#include <iostream>
#include <math.h>
#include"Vector3.hpp"
using namespace std;


//Default initializer with no given x,y,z. Set all equal to zero.
Vector3::Vector3() {
	x = 0;
	y = 0;
	z = 0;
}

//Initializer with given x, y, and z values
Vector3::Vector3(float x_, float y_, float z_) {
	x = x_;
	y = y_;
	z = z_;
}

//Add two vectors together (add components)
void Vector3::Add(Vector3& b) {
	x += b.x;
	y += b.y;
	z += b.z;
}

//Subtract two vectors together (subtract components)
void Vector3::Subtract(Vector3& b) {
	x -= b.x;
	y -= b.y;
	z -= b.z;
}

//Multiply each component by a scalar
void Vector3::ScalarMultiplication(float s) {
	x *= s;
	y *= s;
	z *= s;
}

//Returns the magnitude of the vector
float Vector3::Mag() {
	return (sqrt(x) + sqrt(y) + sqrt(z));
}

//Scale each component such that the magnitude equals one
void Vector3::Normalize() {
	float m = this->Mag();
	x = (x / pow(m, 2));
	y = (y / pow(m, 2));
	z = (z / pow(m, 2));
}

//Dot product of two vectors = (x1*x2) + (y1*y2) + (z1*z2)
float Vector3::Dot(Vector3& b) {
	return ((x * b.x) + (y * b.y) + (z * b.z));
}


//TODO: Lerp, Slerp functions
Vector3 Vector3::Lerp(Vector3& b, float t) {

}

//TODO: CHECK THIS FUNCTION!!!
Vector3 Vector3::Slerp(Vector3& b, float t) {
	float t_ = 1 - t;
	// Dot product - the cosine of the angle between 2 vectors.
	float dot = this->Dot(b);
	// Clamp it to be in the range of Acos()
	dot = clamp(dot, -1.0f, 1.0f);
	float theta = acos(dot) * t_;
	Vector3 RelativeVec = (*this - b) * dot;
	RelativeVec.Normalize();
	// Orthonormal basis
	// The final result.
	return ((*this * cos(theta)) + (RelativeVec * sin(theta)));
}

//TODO: Extend to Rotate(float angle_x, float angle_y, float angle_z)
void Rotate(float angle_x, float angle_y, float angle_z) {

}

//Overloading the operators
Vector3 Vector3::operator*(const float f) {
	Vector3 v;
	v.x = (this->x * f);
	v.y = (this->y * f);
	v.z = (this->z * f);
	return v;
}

//This is the CROSS PRODUCT of the two vectors.
Vector3 Vector3::operator*(const Vector3& b) {
	Vector3 v;
	v.x = (this->y * b.z) - (this->z * b.y);
	v.y = (this->x * b.z) - (this->z * b.x);
	v.z = (this->x * b.y) - (this->y * b.x);
	return v;
}

//Vector sum: add components
Vector3 Vector3::operator+(const Vector3& b) {
	Vector3 v;
	v.x = this->x + b.x;
	v.y = this->y + b.y;
	v.z = this->z + b.z;
	return v;
}

//Vector difference: subtract components
Vector3 Vector3::operator-(const Vector3& b) {
	Vector3 v;
	v.x = this->x - b.x;
	v.y = this->y - b.y;
	v.z = this->z - b.z;
	return v;
}

//Clamp a float f between a minimum and maximum value
float clamp(float f, float min, float max) {
	if (f < min) {
		f = min;
	}
	if (f > max) {
		f = max;
	}
	return f;
}