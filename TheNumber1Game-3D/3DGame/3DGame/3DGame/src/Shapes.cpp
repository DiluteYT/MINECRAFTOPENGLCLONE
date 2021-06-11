#include "Shapes.h"

std::vector<Vertex> Quad() {

	std::vector<Vertex> placeholder;

	placeholder.emplace_back(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 1.0f)); // 1

	placeholder.emplace_back(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f)); // 2

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f)); // 3

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f)); // 4

	placeholder.emplace_back(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 1.0f)); // 5

	placeholder.emplace_back(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 1.0f)); // 6

	return placeholder;

};

std::vector<Vertex> Cube() {

	std::vector<Vertex> placeholder;

	placeholder.emplace_back(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 1.0f)); // 1 FRONT

	placeholder.emplace_back(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f)); // 2

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f)); // 3

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f)); // 4

	placeholder.emplace_back(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 1.0f)); // 5

	placeholder.emplace_back(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 1.0f)); // 6

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f)); // 7 BACK

	placeholder.emplace_back(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)); // 8

	placeholder.emplace_back(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 1.0f)); // 9

	placeholder.emplace_back(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 1.0f)); // 10

	placeholder.emplace_back(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 1.0f)); // 11

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f)); // 12

	placeholder.emplace_back(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)); // 13 LEFT

	placeholder.emplace_back(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 1.0f)); // 14

	placeholder.emplace_back(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 1.0f)); // 15

	placeholder.emplace_back(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 1.0f)); // 16

	placeholder.emplace_back(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)); // 17

	placeholder.emplace_back(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f)); // 18

	placeholder.emplace_back(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 1.0f)); // 19 RIGHT

	placeholder.emplace_back(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 1.0f)); // 20

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)); // 21

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f)); // 22

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)); // 23

	placeholder.emplace_back(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 1.0f)); // 24

	placeholder.emplace_back(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 0.0f)); // 25 TOP

	placeholder.emplace_back(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 1.0f)); // 26

	placeholder.emplace_back(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 1.0f)); // 27

	placeholder.emplace_back(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 0.0f)); // 28

	placeholder.emplace_back(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 0.0f)); // 29

	placeholder.emplace_back(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 1.0f)); // 30

	placeholder.emplace_back(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f)); // 31 BOTTOM

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 1.0f)); // 32

	placeholder.emplace_back(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f)); // 33

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 1.0f)); // 34

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f)); // 35

	placeholder.emplace_back(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f)); // 36

	return placeholder;

}

std::vector<Vertex> Spike() {

	std::vector<Vertex> placeholder;

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f)); // 1

	placeholder.emplace_back(glm::vec3(0.0f, 0.5f, 0.5f), glm::vec2(0.5f, 1.0f)); // 2

	placeholder.emplace_back(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f)); // 3

	return placeholder;

};

std::vector<Vertex> Spike_3D() {

	std::vector<Vertex> placeholder;


	placeholder.emplace_back(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f)); // 1 BOTTOM

	placeholder.emplace_back(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f)); // 2

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f)); // 3

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 1.0f)); // 4

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f)); // 5

	placeholder.emplace_back(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f)); // 6

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f)); // 7 FRONT

	placeholder.emplace_back(glm::vec3(0, 0.5f, 0), glm::vec2(0.5f, 1.0f)); // 8

	placeholder.emplace_back(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f)); // 9

	placeholder.emplace_back(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f)); // 10 BACK

	placeholder.emplace_back(glm::vec3(0, 0.5f, 0), glm::vec2(0.5f, 1.0f)); // 11

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)); // 12

	placeholder.emplace_back(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f)); // 13 LEFT

	placeholder.emplace_back(glm::vec3(0, 0.5f, 0), glm::vec2(0.5f, 1.0f)); // 14

	placeholder.emplace_back(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f)); // 15

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)); // 16 RIGHT

	placeholder.emplace_back(glm::vec3(0, 0.5f, 0), glm::vec2(0.5f, 1.0f)); // 17

	placeholder.emplace_back(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f)); // 18

	return placeholder;

};