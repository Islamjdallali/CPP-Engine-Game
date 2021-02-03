#include "EnemyEntity.h"

void EnemyEntity::Update(World& w)
{
	//find the distance between the enemy and the waypoint
	m_Dist = m_enemyAI->ShowWaypoint(m_spriteName, m_waypointID) - m_pos;
	//work out the direction of the waypoint by normalising the distnce
	m_nDir = m_Dist;
	m_nDir.NormaliseInPlace();

	//move the enemy's position towards the waypoint
	m_pos.x = m_pos.x + (int)(m_nDir.x * m_speed);
	m_pos.y = m_pos.y + (int)(m_nDir.y * m_speed);

	/*check for when the enemy get close to the waypoint, if they do,
	then add one to the waypointID which allows the enemy to move to the other waypoint
	in the vector, if the enemy reached the last waypoint, then loop it back to the start waypoint*/
	if (m_Dist.x <= 1
		&& m_Dist.y <= 1)
	{
		if (m_waypointID >= m_enemyAI->GetWaypointSize(m_spriteName) - 1)
		{
			m_waypointID = 0;
		}
		else
		{
		m_waypointID++;
		}
	}

	/*if the enemy is a shooter, then every few seconds shoot a bullet downwards*/
	if (m_spriteName == "EnemyShooter")
	{
		m_shootDelay--;

		if (m_shootDelay <= 0)
		{
			//make the start pos in the centre and slightly below the enemy sprite
			Vector2 startPos = Vector2({ m_pos.x + 32, m_pos.y + 70 });
			w.FireBullet(startPos, m_bulletDir, GetSide());
			m_shootDelay = (rand() % 300) + 600;
		}
	}
}

void EnemyEntity::Death(World& w)
{
	w.AddToKilledEnemies();
}

void EnemyEntity::GetAI(AI* ai, int b)
{
	m_enemyAI = ai;
	m_enemyAI->GenerateWave(m_spriteName,b);
}
