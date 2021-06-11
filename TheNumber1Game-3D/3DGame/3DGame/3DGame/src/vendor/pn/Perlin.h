#pragma once

#include <cstdlib>
#include <cmath>
#include <iostream>

class Perlin {
public:
	Perlin();
	~Perlin();

	// Generates a Perlin (smoothed) noise value between -1 and 1, at the given 3D position.
	float noise(float sample_x, float sample_y, float sample_z);


private:
	int *p; // Permutation table
	// Gradient vectors
	float *Gx;
	float *Gy;
	float *Gz;
};

class PerlinMath
{
	Perlin perlin;

	unsigned seed1;
	unsigned int seed2;

	float layer1 = 0.0f;
	float layer2 = 0.0f;

public:

	PerlinMath()
		: seed1(std::rand()),
		seed2(std::rand())
	{

	}

	int noise(float x, float z)
	{
		layer1 = perlin.noise((x + seed1) / 100, 0.0f, (z + seed1) / 100) * 40;
		layer2 = perlin.noise((x + seed2) / 100, 0.0f, (z + seed2) / 100) * 80;
		return std::round(layer1 + layer2);
	}

};

