#pragma once
#include "Entity.h"

using namespace HAPISPACE;

class ExplosionEntity : public Entity
{
private:
	float m_animationDelay = 20;
public:
	ExplosionEntity(std::string name, float posX, float posY, int frameWidth, int frameHeight, int frameNum) : Entity(name, posX, posY, frameWidth, frameHeight, frameNum)
	{
		m_pos.x = posX;
		m_pos.y = posY;
		m_alive = false;
	}

	void Update(World& w) override final;

	void Death(World& w) override final;

	ESide GetSide() const override { return ESide::eSideNeutral; }
};

