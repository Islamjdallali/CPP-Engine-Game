#pragma once
#include "Entity.h"
#include "World.h"

class BulletEntity : public Entity
{
private:

public:
	BulletEntity(std::string name, float posX, float posY, int frameWidth, int frameHeight, int frameNum) : Entity(name, posX, posY, frameWidth, frameHeight, frameNum) { m_alive = false;}

	void Update(World& w) override final;

	void Death(World& w) override final;

	void Fire(Vector2 startPos, Vector2 dir) override final;

	ESide GetSide() const override { return ESide::eSideBullet; }
};

