#include "ExplosionEntity.h"

void ExplosionEntity::Update(World& w)
{
	/* once the explosion entity reaches its final frame,
	kill it*/
	if (m_frameNum > 3)
	{
		m_alive = false;
	}
	if (m_frameNum < 4)
	{
		m_animationDelay--;
		if (m_animationDelay <= 0)
		{
			m_frameNum++;
			m_animationDelay = 20;
		}
	}
}

void ExplosionEntity::Death(World& w)
{
}
