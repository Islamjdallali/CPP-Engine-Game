#pragma once
#include <HAPI_lib.h>
#include "Rectangle.h"

using namespace HAPISPACE;

class Sprite
{
private:
	int m_width = 0;
	int m_height = 0;
	BYTE* m_data{ nullptr };
public:

	~Sprite();
	bool Create(const std::string& filename);

	void Blit(BYTE* screen, int screenWidth, float sX, float sY);

	void AlphaBlit(BYTE* screen, int screenWidth, int screenHeight, float sX, float sY, int frameWidth, int frameHeight, int frameNum);

};

