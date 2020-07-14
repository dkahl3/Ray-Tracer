#pragma once
#include "Vector3n.h"

// Ray class 
// Used to calculate intersections with objects in the scene
// Public variables define the starting point and direction of ray

class Ray {
private:

public:
	MathEng::Vector3n origin;
	MathEng::Vector3n direction;

	// Constructor
	Ray(MathEng::Vector3n orig, MathEng::Vector3n dir);

	// Get the point of intersection with this ray and object
	// This can be used to calculate the distance of the object from the camera
	MathEng::Vector3n getPoint(float t);
};

// Color struct
// Data type used for storing RGB values
struct Color {
	float R;
	float G;
	float B;

	Color() {
		R = 1.0;
		G = 1.0;
		B = 1.0;
	}

	Color(float red, float green, float blue) {
		R = red;
		G = green;
		B = blue;
	}
};

// Object class
// This represents all defined geometry, which will be inheriting from this class for base functionality
// Other Geometries will also implement their own functionalities
class Object {
private:

public:
	Color color;

	// Constructor
	Object();
	Object(MathEng::Vector3n col);

	// Returns true if incoming Ray intersects with object and provides a t value to determine distance of object
	virtual bool intersect(Ray r, float& t);

	virtual MathEng::Vector3n normal(Ray r);
};

// Sphere class
// This class extends object functionality while implementing sphere geometry variables and functions
class Sphere : public Object {
private:

public:
	MathEng::Vector3n center;
	float radius;

	// Constructors
	Sphere();
	Sphere(MathEng::Vector3n cent, MathEng::Vector3n col, float rad);

	// Sphere intersect 
	bool intersect(Ray r, float& t);

	// Get sphere normal
	MathEng::Vector3n normal(Ray r);
};