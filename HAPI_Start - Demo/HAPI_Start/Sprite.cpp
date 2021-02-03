#include "Sprite.h"

bool Sprite::Create(const std::string& filename)
{
    return HAPI.LoadTexture(filename, &m_data, m_width, m_height);
}

void Sprite::Blit(BYTE* screen, int screenWidth, float sX, float sY)
{
    for (size_t newY = 0; newY < m_height; newY++)
    {
        int offset = (screenWidth * (sY + newY) + sX) * 4;
        int textureOffset = m_height * newY * 4;

        memcpy(screen + offset, m_data + textureOffset, m_width * 4);
    }
}

void Sprite::AlphaBlit(BYTE* screen, int screenWidth, int screenHeight, float sX, float sY, int frameWidth, int frameHeight, int frameNum)
{
	//create 2 new instances of ractangle, one for the player and one for the screen
	Rectangle screenRect(0, screenWidth, 0, screenHeight);
	Rectangle textureRect(0, frameWidth, 0, m_height);

	textureRect.Translate(sX, sY);

	if (textureRect.IsOutSideOf(screenRect))
	{
		return;
	}

	textureRect.ClipTo(screenRect);
	textureRect.Translate(-sX, -sY);

	if (sX < 0)
	{
		sX = 0;
	}

	if (sY < 0)
	{
		sY = 0;
	}

	textureRect.Translate(frameNum * frameWidth, 0);


	BYTE* screenStart = screen + (int)(sX + sY * screenWidth) * 4;
	//we need to make sure that texture start takes the rectangles area
	BYTE* textureStart =  m_data + (textureRect.left + textureRect.top * m_width) * 4;


	int endOfLineDestIncrement = (screenWidth - textureRect.Width()) * 4;
	int endOfLineTexIncrement = (m_width - textureRect.Width()) * 4;

	for (size_t y = 0; y < textureRect.Height(); y = y++)
	{
		for (size_t x = 0; x < textureRect.Width(); x++)
		{

			BYTE a = textureStart[3];

			//if the alpha is greater than 0 then draw
			if (a > 0)
			{
				if (a == 255)
				{
					memcpy(screenStart, textureStart, 4);
				}
				else
				{
					//we draw the sprite with transparency
					float alpha = a / 255.0f;

					screenStart[0] = alpha * textureStart[0] + screenStart[0] * (1.0f - alpha);
					screenStart[1] = alpha * textureStart[1] + screenStart[1] * (1.0f - alpha);
					screenStart[2] = alpha * textureStart[2] + screenStart[2] * (1.0f - alpha);
				}
			}

			screenStart += 4;
			textureStart += 4;
		}

		screenStart += endOfLineDestIncrement;
		textureStart += endOfLineTexIncrement;
	}
}

Sprite::~Sprite()
{
    delete[]m_data;
}
