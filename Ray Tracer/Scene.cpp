#include "Scene.h"
#include "Geometry.h"
#include "Vector3n.h"
#include <math.h>

// Methods to help with intersection math
float getDistance(MathEng::Vector3n v1, MathEng::Vector3n v2) {
	return sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2) + pow(v2.z - v1.z, 2));
}

// Scene class implementation
Scene::Scene() {

}

Scene::Scene(std::vector <Object*> obj) {
	objects = obj;
}

// Check all objects for intersections and return the appropriate color to be drawn on the pixel
Color Scene::getIntersection(Ray r) {
	Object* ob = NULL;
	float minDist = FLT_MAX;
	float curDist;

	// Check for intersection with each object in the list
	for (int i = 0; i < objects.size(); i++) { 

		float t;
		bool intersect = objects.at(i)->intersect(r, t);

		if (intersect) {
			// Find distance and check to see if this object is the closest one
			MathEng::Vector3n intPoint = r.getPoint(t);

			curDist = getDistance(MathEng::Vector3n(0.0, 0.0, 0.0), intPoint);

			if (curDist < minDist) { 
				minDist = curDist;
				ob = objects.at(i);
			}

		}
	}

	// If no intersections return background color
	if (ob == NULL) {
		return Color(0.6, 0.6, 0.6);
	}

	return ob->color;
}