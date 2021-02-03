#pragma once
#include <string>
#include "Graphics.h"
#include "Rectangle.h"
#include "Vector2.h"

enum class ESide
{
	eSideNeutral,
	eSideEnemy,
	eSidePlayer,
	eSideBullet
};

class World;

class Entity
{
protected:
	Vector2 m_pos;
	Vector2 m_spawnPos;
	Vector2 m_dir;
	int m_frameWidth;
	int m_frameHeight;
	int m_frameNum;
	Graphics* m_graphics{ nullptr };
	std::string m_spriteName;
	bool m_alive{ true };

public:

	Entity(std::string name, float posX, float posY, int frameWidth, int frameHeight, int frameNum) : m_spriteName(name), m_frameWidth(frameWidth), m_frameHeight(frameHeight), m_frameNum(frameNum)
	{m_pos.x = posX; m_pos.y = posY; m_alive = true; m_spawnPos = m_pos;}

	virtual void Update(World& w) = 0;

	virtual void Death(World& w) = 0;

	virtual ESide GetSide() const = 0;

	virtual void Fire(Vector2 startPos, Vector2 dir);

	std::string GetName() { return m_spriteName; }

	void SetPos(Vector2 p) { m_pos = p; }

	void CheckCollision(Entity& other, World& w);

	void DrawEntity(Graphics* g);

	bool IsAlive() { return m_alive; }

	void ToggleAlive() { m_alive = !m_alive; }

};