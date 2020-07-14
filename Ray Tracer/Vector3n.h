#pragma once

namespace MathEng {
	class Vector3n {

	private:

	public:
		float x;
		float y;
		float z;

		// Constructors
		Vector3n();
		Vector3n(float nX, float nY, float nZ);

		// Destructor
		~Vector3n();

		// Copy Constructor
		Vector3n(const Vector3n& v);
		Vector3n& operator=(const Vector3n& v);

		// Print
		void print();

		// Addition
		void operator+=(const Vector3n& v);
		Vector3n operator+(const Vector3n& v);

		// Subtraction
		void operator-=(const Vector3n& v);
		Vector3n operator-(const Vector3n& v);

		// Scalar Multiplication
		void operator*=(const float n);
		Vector3n operator*(const float n);

		// Scalar Division
		void operator/=(const float n);
		Vector3n operator/(const float n);

		// Dot Product
		float dot(Vector3n v);

		// Cross Product
		Vector3n cross(Vector3n v);

		// Magnitude
		float magnitude();

		// Normalize
		void normalize();
		
	};
}