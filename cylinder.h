#pragma once

#include <vector>
#include <cmath>
#include <iostream>
#include <glm/glm.hpp>

namespace Cylinder {
	constexpr double my_pi = 3.14159265358979323846;
	void createCircleWireVertices(int sector, float z, std::vector<float>& target, bool vectical);
	void createCylinderSideFewSector(int sector, std::vector<float>& up, std::vector<float>& down, std::vector<float>& side);
	void createCylinderSideLargeSector(int sector, std::vector<float>& up, std::vector<float>& down, std::vector<float>& side);
}
