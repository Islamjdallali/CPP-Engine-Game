#pragma once
#include "PlayerEntity.h"
#include "EnemyEntity.h"
#include "AI.h"
#include "BackgroundEntity.h"
#include "BulletEntity.h"
#include "ExplosionEntity.h"
#include "Vector2.h"
#include <HAPI_lib.h>

using namespace HAPISPACE;

class Entity;

class Graphics;

class World
{
private:
	std::vector<Entity*> m_entites;
	int m_height{ 600 };
	int m_width{ 800 };
	int m_killedEnemies{ 0 };
	Graphics* m_graphics{nullptr};
	AI* m_ai{ nullptr };
	const HAPI_TKeyboardData& m_keyData{ HAPI.GetKeyboardData() };
	BYTE* screen{nullptr};
	HAPI_TColour color;
	size_t m_bulletStartIndex{ 0 };
	size_t m_explosionStartIndex{ 0 };
	DWORD lastTimeUpdated = HAPI.GetTime();
	const DWORD kTickTime = 5;

public:
	~World();
	void FireBullet(Vector2 startPos, Vector2 velocity, ESide side);
	void SpawnExplosion(Vector2 pos);
	void AddToKilledEnemies() { m_killedEnemies++; };
	bool LoadLevel();
	void Update();
};

