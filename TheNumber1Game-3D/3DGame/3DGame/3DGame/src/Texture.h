#pragma once

#include <iostream>

class Texture
{
private:
	const char* Filename;

public:
	unsigned int ID = 0;
	Texture(const char* filename, bool nn);
};