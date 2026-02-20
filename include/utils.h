#ifndef UTILS_H
#define UTILS_H

#include "glm/glm.hpp"
#include <vector>

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 tex;
};

namespace utils {
    // neighbour checking
        void addTopFace(std::vector<Vertex>& v, int x, int y, int z) {
            glm::vec3 normal = glm::vec3(0, 0, 1);

            // triangle 1
            v.push_back({glm::vec3(x, y, z + 1), normal, {0.0f, 0.0f}});
            v.push_back({glm::vec3(x + 1, y, z + 1), normal, {1.0f, 0.0f}});
            v.push_back({glm::vec3(x + 1, y + 1, z + 1), normal, {1.0f, 1.0f}});

            // triangle 2
            v.push_back({glm::vec3(x, y, z + 1), normal, {0.0f, 0.0f}});
            v.push_back({glm::vec3(x + 1, y + 1, z + 1), normal, {1.0f, 1.0f}});
            v.push_back({glm::vec3(x, y + 1, z + 1), normal, {0.0f, 1.0f}});
        }

        void addBottomFace(std::vector<Vertex>& v, int x, int y, int z) {
            glm::vec3 normal = glm::vec3(0, 0, -1);
            
            // triangle 1
            v.push_back({glm::vec3(x, y, z), normal, {0.0f, 0.0f}});
            v.push_back({glm::vec3(x, y + 1, z), normal, {1.0f, 0.0f}});
            v.push_back({glm::vec3(x + 1, y + 1, z), normal, {1.0f, 1.0f}});

            // triangle 2
            v.push_back({glm::vec3(x, y, z), normal, {0.0f, 0.0f}});
            v.push_back({glm::vec3(x + 1, y + 1, z), normal, {1.0f, 1.0f}});
            v.push_back({glm::vec3(x + 1, y, z), normal, {0.0f, 1.0f}});
        }

        void addRightFace(std::vector<Vertex>& v, int x, int y, int z) {
            glm::vec3 normal = glm::vec3(1, 0, 0);
            
            // triangle 1
            v.push_back({glm::vec3(x + 1, y, z), normal, {0.0f, 0.0f}});
            v.push_back({glm::vec3(x + 1, y + 1, z), normal, {1.0f, 0.0f}});
            v.push_back({glm::vec3(x + 1, y + 1, z + 1), normal, {1.0f, 1.0f}});

            // triangle 2
            v.push_back({glm::vec3(x + 1, y, z), normal, {0.0f, 0.0f}});
            v.push_back({glm::vec3(x + 1, y + 1, z), normal, {1.0f, 1.0f}});
            v.push_back({glm::vec3(x + 1, y, z + 1), normal, {0.0f, 1.0f}});
        }

        void addLeftFace(std::vector<Vertex>& v, int x, int y, int z) {
            glm::vec3 normal = glm::vec3(-1, 0, 0);
            
            // triangle 1
            v.push_back({glm::vec3(x, y, z), normal, {0.0f, 0.0f}});
            v.push_back({glm::vec3(x, y, z + 1), normal, {1.0f, 0.0f}});
            v.push_back({glm::vec3(x, y + 1, z + 1), normal, {1.0f, 1.0f}});

            // triangle 2
            v.push_back({glm::vec3(x, y, z), normal, {0.0f, 0.0f}});
            v.push_back({glm::vec3(x, y + 1, z + 1), normal, {1.0f, 1.0f}});
            v.push_back({glm::vec3(x, y + 1, z), normal, {0.0f, 1.0f}});
        }

        void addFrontFace(std::vector<Vertex>& v, int x, int y, int z) {
            glm::vec3 normal = glm::vec3(0, 1, 0);
            
            // triangle 1
            v.push_back({glm::vec3(x, y + 1, z), normal, {0.0f, 0.0f}});
            v.push_back({glm::vec3(x, y + 1, z + 1), normal, {1.0f, 0.0f}});
            v.push_back({glm::vec3(x + 1, y + 1, z + 1), normal, {1.0f, 1.0f}});

            // triangle 2
            v.push_back({glm::vec3(x, y + 1, z), normal, {0.0f, 0.0f}});
            v.push_back({glm::vec3(x + 1, y + 1, z + 1), normal, {1.0f, 1.0f}});
            v.push_back({glm::vec3(x + 1, y + 1, z), normal, {0.0f, 1.0f}});
        }

        void addBackFace(std::vector<Vertex>& v, int x, int y, int z) {
            glm::vec3 normal = glm::vec3(0, -1, 0);
            
            // triangle 1
            v.push_back({glm::vec3(x, y, z), normal, {0.0f, 0.0f}});
            v.push_back({glm::vec3(x + 1, y, z), normal, {1.0f, 0.0f}});
            v.push_back({glm::vec3(x + 1, y, z + 1), normal, {1.0f, 1.0f}});

            // triangle 2
            v.push_back({glm::vec3(x, y, z), normal, {0.0f, 0.0f}});
            v.push_back({glm::vec3(x + 1, y, z + 1), normal, {1.0f, 1.0f}});
            v.push_back({glm::vec3(x, y, z + 1), normal, {0.0f, 1.0f}});
        }
}

#endif