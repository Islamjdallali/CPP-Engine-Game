#include "Graphics.h"
#include "Sprite.h"
#include<unordered_map>


bool Graphics::Initialise(int sw, int sh)
{
	if (!HAPI.Initialise(sw, sh, "Islam's program"))
	{

		return false;
	}
}

Graphics::~Graphics()
{
	/*iterate through the sprite map and delete the sprites, then clear the sprite map*/
	for (std::unordered_map<std::string, Sprite*>::iterator itr = m_spriteMap.begin(); itr != m_spriteMap.end(); itr++)
	{
		delete (itr->second);
	}
	m_spriteMap.clear();
}

void Graphics::GetScreenPointer(BYTE* screen)
{
	m_screen = screen;
}

void Graphics::ClearToColor(BYTE* screen, HAPI_TColour color)
{
	m_screen = screen;

	for (int i = 0; i < m_screenHeight * m_sceenWidth; i++)
	{
		memcpy(screen, &color, 4);
		screen += 4;
	}
}

bool Graphics::LoadSprite(const std::string& filename, const std::string& name)
{
	//create new instance of a sprite
	Sprite* newSprite = new Sprite;
	if (!newSprite->Create(filename))
	{
		//if we cannot create a new sprite then just return false
		delete newSprite;
		return false;
	}
	//store the sprite in a map
	m_spriteMap[name] = newSprite;
	return true;
}

void Graphics::DrawSprite(const std::string& name, float sX, float sY, int frameWidth, int frameHeight, int frameNum)
{
	//call the alphablit function on the appropriate sprite
	m_spriteMap[name]->AlphaBlit(m_screen, m_sceenWidth,m_screenHeight, sX, sY, frameWidth, frameHeight, frameNum);
}
