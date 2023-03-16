#include "parser.h"

ParserInfo parse(std::string fname, long unsigned int firstVertex)
{
    //for each triangle
    ParserInfo out;
    std::ifstream inputfile(fname, std::ios::binary);
    //skip header bytes
    for (int i = 0; i < 80; i++)
        inputfile.get();
    //get number of triangles
    unsigned int numOfTriangles;
    inputfile.read((char*)&numOfTriangles, sizeof(numOfTriangles));
    //vertex vector
    std::vector<vec3> vertices;
    //triangle vector
    std::vector<triangle> triangles;
    //for eye calculation purposes
    //max x
    out.maxX = -FLT_MAX;
    //min x
    out.minX = FLT_MAX;
    //max y
    out.maxY = -FLT_MAX;
    //min y
    out.minY = FLT_MAX;
    //max z
    out.maxZ = -FLT_MAX;
    //min z
    out.minZ = FLT_MAX;
    //totals
    out.totalX = 0;
    out.totalY = 0;
    out.totalZ = 0;
    for (unsigned int i = 0; i < numOfTriangles; i++)
    {
        //current triangle
        triangle tri;
        //get normal vector
        vec3 norm;
        inputfile.read((char*)&norm.x, sizeof(norm.x));
        inputfile.read((char*)&norm.y, sizeof(norm.y));
        inputfile.read((char*)&norm.z, sizeof(norm.z));
        //normalize vector
        norm = normalize(norm);
        tri.normal = norm;
        //get first vertex
        vec3 v1;
        inputfile.read((char*)&v1.x, sizeof(v1.x));
        out.totalX += v1.x;
        inputfile.read((char*)&v1.y, sizeof(v1.y));
        out.totalY += v1.y;
        inputfile.read((char*)&v1.z, sizeof(v1.z));
        out.totalZ += v1.z;
        //set max and min z
        out.maxX = std::max(out.maxX, v1.x);
        out.minX = std::min(out.minX, v1.x);
        out.maxY = std::max(out.maxY, v1.y);
        out.minY = std::min(out.minY, v1.y);
        out.maxZ = std::max(out.maxZ, v1.z);
        out.minZ = std::min(out.minZ, v1.z);
        //set vertex 1 index in triangle
        tri.aPos = vertices.size() + firstVertex;
        //push vertex to vertex vector
        vertices.push_back(v1);
        //get second vertex
        vec3 v2;
        inputfile.read((char*)&v2.x, sizeof(v2.x));
        out.totalX += v2.x;
        inputfile.read((char*)&v2.y, sizeof(v2.y));
        out.totalY += v2.y;
        inputfile.read((char*)&v2.z, sizeof(v2.z));
        out.totalZ += v2.z;
        //set max and min z
        out.maxX = std::max(out.maxX, v2.x);
        out.minX = std::min(out.minX, v2.x);
        out.maxY = std::max(out.maxY, v2.y);
        out.minY = std::min(out.minY, v2.y);
        out.maxZ = std::max(out.maxZ, v2.z);
        out.minZ = std::min(out.minZ, v2.z);
        //set vertex 2 index in triangle
        tri.bPos = vertices.size() + firstVertex;
        //push vertex to vertex vector
        vertices.push_back(v2);
        //get third vertex
        vec3 v3;
        inputfile.read((char*)&v3.x, sizeof(v3.x));
        out.totalX += v3.x;
        inputfile.read((char*)&v3.y, sizeof(v3.y));
        out.totalY += v3.y;
        inputfile.read((char*)&v3.z, sizeof(v3.z));
        out.totalZ += v3.z;
        //set max and min z
        out.maxX = std::max(out.maxX, v3.x);
        out.minX = std::min(out.minX, v3.x);
        out.maxY = std::max(out.maxY, v3.y);
        out.minY = std::min(out.minY, v3.y);
        out.maxZ = std::max(out.maxZ, v3.z);
        out.minZ = std::min(out.minZ, v3.z);
        //set vertex 3 index in triangle
        tri.cPos = vertices.size() + firstVertex;
        //push vertex to vertex vector
        vertices.push_back(v3);
        //push triangle to triangle vector
        triangles.push_back(tri);
        //skip attribute byte count
        short skip;
        inputfile.read((char*)&skip, sizeof(skip));
    }
    out.verts = vertices;
    out.tris = triangles;
    //we have read all of the triangles
    //close the input file
    inputfile.close();
    return out;
}