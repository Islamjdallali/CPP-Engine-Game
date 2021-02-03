#pragma once
#include <iostream>
#include <HAPI_lib.h>
#include<unordered_map>

using namespace HAPISPACE;

class Sprite;

class Graphics
{
private:
	BYTE* m_screen{ nullptr };
	int m_screenHeight{600};
	int m_sceenWidth{800};

	std::unordered_map<std::string, Sprite*> m_spriteMap;

public:
	bool Initialise(int sw, int sh);

	~Graphics();

	void GetScreenPointer(BYTE* screen);

	void ClearToColor(BYTE* screen, HAPI_TColour color);

	bool LoadSprite(const std::string& filename, const std::string& name);
	void DrawSprite(const std::string& name , float sX, float sY, int frameWidth, int frameHeight, int frameNum);
};

