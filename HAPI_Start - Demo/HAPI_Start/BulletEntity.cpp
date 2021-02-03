#include "BulletEntity.h"

void BulletEntity::Update(World& w)
{
	//move the bullet based on the direction that the other entity has given it
	m_pos.y = m_pos.y - 5 * m_dir.y;
	m_pos.x = m_pos.x - 5 * m_dir.x;

	//if the bullet has gone off screen then kill it
	if (m_pos.y < -100)
	{
		m_alive = false;
	}
}

void BulletEntity::Death(World& w)
{
	w.SpawnExplosion(m_pos);
}

void BulletEntity::Fire(Vector2 startPos, Vector2 dir)
{
	m_pos = startPos;
	m_dir = dir;
}
