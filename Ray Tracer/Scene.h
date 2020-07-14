#pragma once
#include "Geometry.h"
#include <vector>

// Scene class
// This contains all the objects on the scene including geometry and light sources
// Provides some methods to abstract away some of the ray tracing math

class Scene {
private:
	std::vector <Object*> objects;
	// TODO: Light sources

public:
	Scene();
	Scene(std::vector <Object*> obj);

	// Returns nearest objects of that intersects with ray
	Color getIntersection(Ray r);
};