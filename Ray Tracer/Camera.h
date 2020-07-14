#pragma once
#include "Vector3n.h"

// Camera class
// Responsible for containing perpective information that will be used to determine:
// 1. Which direction we are viewing from
// 2. How far away the camera is
// 3. Near and far clipping planes

class Camera {
private:

public:
	MathEng::Vector3n direction;
	float distance;
	
};