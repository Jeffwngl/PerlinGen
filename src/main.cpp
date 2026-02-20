#include <iostream>
#include <stdlib.h>
#include <fstream>

#define STB_PERLIN_IMPLEMENTATION
#include <stb_perlin.h>
#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>

#include <utils.h>

const unsigned int CHUNK_WIDTH = 32;
const unsigned int CHUNK_LENGTH = 32;
const unsigned int CHUNK_HEIGHT = 64;

// change these values to configure the generation
float scale = 0.05f;
float airThreshold = -0.5f;

// implement block IDs for different types of blocks
const int airID = 0;
const int stoneID = 1;

void exportOBJ(const std::vector<Vertex>& vertices, const std::string& filename);

std::vector<Vertex>vertices;

int main() {

    // initialize chunk (change to flat array?)
    std::vector<std::vector<std::vector<int>>>chunk(
        CHUNK_WIDTH, std::vector<std::vector<int>>(
            CHUNK_LENGTH, std::vector<int> (
                CHUNK_HEIGHT, 0
            )
        )
    );

    for (int i = 0; i < CHUNK_WIDTH; i++) {
        for (int j = 0; j < CHUNK_LENGTH; j++) {
            for (int k = 0; k < CHUNK_HEIGHT; k++) {
                float nX = static_cast<float>(i) * scale;
                float nY = static_cast<float>(j) * scale;
                float nZ = static_cast<float>(k) * scale;
                
                float noiseValue = stb_perlin_noise3(nX, nY, nZ, 0, 0, 0);

                if (noiseValue < airThreshold) {
                    chunk[i][j][k] = stoneID;
                }
                else {
                    chunk[i][j][k] = airID;
                }
            }
        }
    }

    for (int i = 0; i < CHUNK_WIDTH; i++) {
        for (int j = 0; j < CHUNK_LENGTH; j++) {
            for (int k = 0; k < CHUNK_HEIGHT; k++) {
                uint8_t blockType = chunk[i][j][k];

                if (blockType == 0) continue;

                if (blockType == 1) {
                    if (k == 63 || chunk[i][j][k + 1] == 0) {
                        utils::addTopFace(vertices, i, j, k);
                    }
                    if (k == 0 || chunk[i][j][k - 1] == 0) {
                        utils::addBottomFace(vertices, i, j, k);
                    }
                    if (j == 31 || chunk[i][j + 1][k] == 0) {
                        utils::addFrontFace(vertices, i, j, k);
                    }
                    if (j == 0 || chunk[i][j - 1][k] == 0) {
                        utils::addBackFace(vertices, i, j, k);
                    }
                    if (i == 31 || chunk[i + 1][j][k] == 0) {
                        utils::addRightFace(vertices, i, j, k);
                    }
                    if (i == 0 || chunk[i - 1][j][k] == 0) {
                        utils::addLeftFace(vertices, i, j, k);
                    }
                }
            }
        }
    }
    
    exportOBJ(vertices, "model_out.obj");

    return 0;   
}

void exportOBJ(const std::vector<Vertex>& vertices, const std::string& filename) {
    std::ofstream file(filename);
    
    for (const auto& v : vertices) {
        file << "v " << v.position.x << " " << v.position.y << " " << v.position.z << "\n";
    }

    for (const auto& v : vertices) {
        file << "vn " << v.normal.x << " " << v.normal.y << " " << v.normal.z << "\n";
    }

    for (size_t i = 1; i <= vertices.size(); i += 3) {
        file << "f " << i << "//" << i << " " 
             << i+1 << "//" << i+1 << " " 
             << i+2 << "//" << i+2 << "\n";
    }
    file.close();
}