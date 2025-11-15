#include "cylinder.h"

/*
	remember to add normal matrix
*/
void Cylinder::createCircleWireVertices(int sector, float z , std::vector<float>& target) {

    double offset = 2.0 * my_pi / sector;

    // 每个线段 2 个顶点 × 3 floats = 12 floats per segment
    target.resize(sector * 2 * 3);

//    double angle1 = 0;
//    double angle2 = 0;
    for (int i = 0; i < sector; ++i) {
        double angle1 = offset * i;
        double angle2 = offset * (i + 1);
        //angle2 = offset + angle1;

        float x1 = static_cast<float>(cos(angle1));
        float y1 = static_cast<float>(sin(angle1));
        float x2 = static_cast<float>(cos(angle2));
        float y2 = static_cast<float>(sin(angle2));

        int j = i * 6; // 2 vertices × 6

        // First point
        target[j + 0] = x1; target[j + 1] = y1; target[j + 2] = z;
        // Second point
        target[j + 3] = x2; target[j + 4] = y2; target[j + 5] = z;

//        angle1 += offset;
    }
}

void Cylinder::createCylinderSide(int sector, std::vector<float>& up , 
    std::vector<float>& down ,  std::vector<float>& side) {
    if (up.size() != sector * 6 || down.size() != sector * 6) return;
    target.resize(i * 2 * 2 * 3) // two triangle with two points

    for (int i = 0; i < sector; i++) {
        int j = i * 12;
        if (i & 0x1) {

        }
        else {

        }
    }

}