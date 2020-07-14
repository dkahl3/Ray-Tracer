#include "Geometry.h"
#include "Vector3n.h" 
#include <math.h>

// Ray class implementation
Ray::Ray(MathEng::Vector3n orig, MathEng::Vector3n dir) {
	origin = origin;
	direction = dir;
}

MathEng::Vector3n Ray::getPoint(float t) {
	return origin + direction * t;
}

// Object class implementation
Object::Object() {
	color.R = 1.0;
	color.G = 1.0;
	color.B = 1.0;
}

Object::Object(MathEng::Vector3n col) {
	color.R = col.x;
	color.G = col.y;
	color.B = col.z;
}

// Returns true if incoming Ray intersects with object and provides a t value to determine distance of object
bool Object::intersect(Ray r, float& t) {
	return false;
}

MathEng::Vector3n Object::normal(Ray r) {
	return MathEng::Vector3n();
}

// Sphere class implementation
Sphere::Sphere() {
	
}

Sphere::Sphere(MathEng::Vector3n cent, MathEng::Vector3n col, float rad) {
	center = cent;
	radius = rad;

	color.R = col.x;
	color.G = col.y;
	color.B = col.z;
}

bool Sphere::intersect(Ray r, float& t) {
	// Ray: P + td | P is position | d is direction
	MathEng::Vector3n p = r.origin;
	MathEng::Vector3n d = r.direction;

	MathEng::Vector3n v = p - center;	// Position is the center of the sphere

	const float a = d.dot(d);
	const float b = 2 * v.dot(d);
	const float c = v.dot(v) - radius * radius;
	float delta = b * b - 4 * c;

	float dist1, dist2;

	if (delta < 0) {
		return false;
	}

	if (delta == 0) {
		t = -b / 2.0 / a;
	}
	else {
		const float dist1 = (-b - sqrt(delta)) / 2 / a;
		const float dist2 = (-b + sqrt(delta)) / 2 / a;
		if (dist1 < 0.0 || dist2 < 0.0)
			return false;
		t = (dist1 < dist2) ? dist1 : dist2;
	}

	return true;
}

MathEng::Vector3n Sphere::normal(Ray r) {
	return MathEng::Vector3n();
}