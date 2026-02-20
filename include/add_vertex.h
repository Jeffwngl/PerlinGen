#ifndef ADD_VERTEX_H
#define ADD_VERTEX_H

#include <iostream>
#include <stdlib.h>
#include "glm/glm.hpp"

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec3 tex;
};

namespace utils {
    // neighbour checking
    void addTopFace(std::vector<Vertex>& vertices, int x, int y, int z) {
        glm::vec3 normal = glm::vec3(0, 0, 1);

        // triangle 1
        vertices.push_back({glm::vec3(x, y, z + 1), normal});
        vertices.push_back({glm::vec3(x + 1, y, z + 1), normal});
        vertices.push_back({glm::vec3(x + 1, y + 1, z + 1), normal});

        // triangle 2
        vertices.push_back({glm::vec3(x, y + 1, z + 1), normal});
        vertices.push_back({glm::vec3(x + 1, y, z + 1), normal});
        vertices.push_back({glm::vec3(x + 1, y + 1, z + 1), normal});
    }

    void addBottomFace(std::vector<Vertex>& vertices, int x, int y, int z) {
        glm::vec3 normal = glm::vec3(0, 0, -1);
        
        // triangle 1
        vertices.push_back({glm::vec3(x, y, z), normal});
        vertices.push_back({glm::vec3(x + 1, y, z), normal});
        vertices.push_back({glm::vec3(x + 1, y + 1, z), normal});

        // triangle 2
        vertices.push_back({glm::vec3(x, y + 1, z), normal});
        vertices.push_back({glm::vec3(x + 1, y, z), normal});
        vertices.push_back({glm::vec3(x + 1, y + 1, z), normal});
    }

    void addRightFace(std::vector<Vertex>& vertices, int x, int y, int z) {
        glm::vec3 normal = glm::vec3(1, 0, 0);
        
        // triangle 1
        vertices.push_back({glm::vec3(x + 1, y, z), normal});
        vertices.push_back({glm::vec3(x + 1, y, z + 1), normal});
        vertices.push_back({glm::vec3(x + 1, y + 1, z), normal});

        // triangle 1
        vertices.push_back({glm::vec3(x + 1, y, z + 1), normal});
        vertices.push_back({glm::vec3(x + 1, y + 1, z), normal});
        vertices.push_back({glm::vec3(x + 1, y + 1, z + 1), normal});
    }

    void addLeftFace(std::vector<Vertex>& vertices, int x, int y, int z) {
        glm::vec3 normal = glm::vec3(-1, 0, 0);
        
        // triangle 1
        vertices.push_back({glm::vec3(x, y, z), normal});
        vertices.push_back({glm::vec3(x, y, z + 1), normal});
        vertices.push_back({glm::vec3(x, y + 1, z), normal});

        // triangle 1
        vertices.push_back({glm::vec3(x, y, z + 1), normal});
        vertices.push_back({glm::vec3(x, y + 1, z), normal});
        vertices.push_back({glm::vec3(x, y + 1, z + 1), normal});
    }

    void addFrontFace(std::vector<Vertex>& vertices, int x, int y, int z) {
        glm::vec3 normal = glm::vec3(0, 1, 0);
        
        // triangle 1
        vertices.push_back({glm::vec3(x, y + 1, z), normal});
        vertices.push_back({glm::vec3(x, y + 1, z + 1), normal});
        vertices.push_back({glm::vec3(x + 1, y + 1, z + 1), normal});

        // triangle 1
        vertices.push_back({glm::vec3(x, y + 1, z), normal});
        vertices.push_back({glm::vec3(x + 1, y + 1, z), normal});
        vertices.push_back({glm::vec3(x + 1, y + 1, z + 1), normal});
    }

    void addBackFace(std::vector<Vertex>& vertices, int x, int y, int z) {
        glm::vec3 normal = glm::vec3(0, -1, 0);
        
        // triangle 1
        vertices.push_back({glm::vec3(x, y, z), normal});
        vertices.push_back({glm::vec3(x, y, z + 1), normal});
        vertices.push_back({glm::vec3(x + 1, y, z + 1), normal});

        // triangle 1
        vertices.push_back({glm::vec3(x, y, z), normal});
        vertices.push_back({glm::vec3(x + 1, y, z), normal});
        vertices.push_back({glm::vec3(x + 1, y, z + 1), normal});
    }
}

#endif