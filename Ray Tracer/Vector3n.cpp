#include "Vector3n.h"
#include "Math.h"
#include <iostream>

// Vector Class Implementation
// These are used for representing the magnitude and direction of something

namespace MathEng {

	// Constructors & Destructor
	Vector3n::Vector3n() :x(0.0), y(0.0), z(0.0) {};

	Vector3n::Vector3n(float nX, float nY, float nZ) :x(nX), y(nY), z(nZ) {};

	Vector3n::~Vector3n() {};

	// Copy Constructor implementation
	Vector3n::Vector3n(const Vector3n& v) :x(v.x), y(v.y), z(v.z) {}

	Vector3n& Vector3n::operator=(const Vector3n& v) {
		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}

	// Print implementation
	void Vector3n::print() {
		std::cout << "[ " << x << ", " << y << ", " << z << " ]" << std::endl;
	}

	// Addition implementation
	void Vector3n::operator+=(const Vector3n& v) {
		x += v.x;
		y += v.y;
		z += v.z;
	}

	Vector3n Vector3n::operator+(const Vector3n& v) {
		return Vector3n(x + v.x, y + v.y, z + v.z);
	}

	// Subtraction implementation
	void Vector3n::operator-=(const Vector3n& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	Vector3n Vector3n::operator-(const Vector3n& v) {
		return Vector3n(x - v.x, y - v.y, z - v.z);
	}

	// Scalar Multiplication implementation
	void Vector3n::operator*=(const float n) {
		x *= n;
		y *= n;
		z *= n;
	}

	Vector3n Vector3n::operator*(const float n) {
		return Vector3n(x * n, y * n, z * n);
	}

	// Scalar Division implementation
	void Vector3n::operator/=(const float n) {
		x /= n;
		y /= n;
		z /= n;
	}

	Vector3n Vector3n::operator/(const float n) {
		return Vector3n(x / n, y / n, z / n);
	}

	// Dot Product implementation
	float Vector3n::dot(Vector3n v) {
		return x * v.x + y * v.y + z * v.z;
	}

	// Cross Product implementation
	Vector3n Vector3n::cross(Vector3n v) {
		float x1 = y * v.z - v.y * z;
		float y1 = x * v.z - v.x * z;
		float z1 = x * v.y - v.x * y;

		return Vector3n(x1, -y1, z1);
	}

	// Magnitude implementation
	float Vector3n::magnitude() {
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

	// Normalize implementation
	void Vector3n::normalize() {
		float mag = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

		if (mag > 0.0f) {
			x = x / mag;
			y = y / mag;
			z = z / mag;
		}

	}
}