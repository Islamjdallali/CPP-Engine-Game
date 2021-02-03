#pragma once
#include "Entity.h"
#include "AI.h"
#include "World.h"
#include <HAPI_lib.h>
#include <time.h>

using namespace HAPISPACE;

class EnemyEntity: public Entity
{
private:
	AI* m_enemyAI{nullptr};
	bool m_isAtWaypoint = false;
	int m_waypointID = 0;
	int m_speed{ 3 };
	float m_shootDelay = 500;
	Vector2 m_bulletDir = { 0,-1 };
	Vector2 m_Dist = { 0,0 };
	Vector2 m_nDir = { 0,0 };
public:
	EnemyEntity(std::string name, float posX, float posY, int frameWidth, int frameHeight, int frameNum) : Entity(name, posX, posY, frameWidth, frameHeight, frameNum)
	{
		m_pos.x = posX;
		m_pos.y = posY;
		srand(time(NULL));
	}

	void Update(World& w) override final;

	void Death(World& w) override final;

	void GetAI(AI* ai, int b);

	ESide GetSide() const override { return ESide::eSideEnemy; }
};

