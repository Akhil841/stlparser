#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <cfloat>

struct vec3 {
    float x;
    float y;
    float z;
};

struct triangle{
    vec3 normal;
    unsigned int aPos;
    unsigned int bPos;
    unsigned int cPos;
};

static vec3 normalize(vec3 in)
{
    //compute magnitude
    float magnitude = in.x * in.x + in.y * in.y + in.z * in.z;
    magnitude = std::sqrt(magnitude);
    //apply magnitude
    in.x /= magnitude;
    in.y /= magnitude;
    in.z /= magnitude;
    //return normalized vector
    return in;
}

struct ParserInfo {
    float maxX;
    float maxY;
    float maxZ;
    float minX;
    float minY;
    float minZ;
    double totalX;
    double totalY;
    double totalZ;
    std::vector<vec3> verts;
    std::vector<triangle> tris;
};

ParserInfo parse(std::string fname, long unsigned int firstIndex);