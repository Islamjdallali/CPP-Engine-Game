#pragma once
#include "Entity.h"
#include "World.h"
#include <HAPI_lib.h>

using namespace HAPISPACE;

class BulletEntity;

class PlayerEntity : public Entity
{
private:
	const HAPI_TKeyboardData& m_keyData{ HAPI.GetKeyboardData() };
	Vector2 m_bulletDir{ 0,1 };
	float m_animationDelay = 50;
	float m_isFireDelayed = 0;
public:

	PlayerEntity(std::string name, float posX, float posY, int frameWidth,int frameHeight, int frameNum) : Entity(name, posX, posY, frameWidth, frameHeight, frameNum)
	{
		m_pos.x = posX;
		m_pos.y = posY;
	}

	Vector2 GetBulletDir() { return m_bulletDir; }

	void Update(World& w) override final;

	void Death(World& w) override final;

	ESide GetSide() const override { return ESide::eSidePlayer; }

};

