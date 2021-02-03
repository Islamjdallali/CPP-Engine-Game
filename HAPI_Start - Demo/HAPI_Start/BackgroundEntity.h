#pragma once
#include "Entity.h"
#include "Rectangle.h"
#include "World.h"

class BackgroundEntity : public Entity
{
private:
	int m_offset = 0;
	int m_screenHeight{ 600 };
	bool m_isTop{ false };
public:

	BackgroundEntity(std::string name, float posX, float posY, int frameWidth, int frameHeight, int frameNum) : Entity(name, posX, posY, frameWidth, frameHeight, frameNum) 
	{
		m_offset = frameHeight;
	}

	void BGIsTop() { m_isTop = true; }

	void Update(World& w) override final;

	void Death(World& w) override final;

	ESide GetSide() const override { return ESide::eSideNeutral; }
};

