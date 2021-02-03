#include "PlayerEntity.h"
#include "Graphics.h"
#include <HAPI_lib.h>

using namespace HAPISPACE;

void PlayerEntity::Update(World& w)
{
	//change player position depending on the key pressed
	if (m_keyData.scanCode['W'])
	{
		m_pos.y -= 5;
	}
	if (m_keyData.scanCode['S'])
	{
		m_pos.y += 5;
	}
	if (m_keyData.scanCode['D'])
	{
		m_pos.x += 5;
	}	
	if (m_keyData.scanCode['A'])
	{
		m_pos.x -= 5;
	}

	/*whenever the player presses the J button then call the
	firebullet function in the world class, the player can actually do
	this once the delay is less or equal to 0*/
	if (m_keyData.scanCode['J'] && m_isFireDelayed <= 0)
	{
		//make the startposition of the bullet in the middle of the sprite and slightly above it
		Vector2 startPos = Vector2(m_pos.x + 64,m_pos.y - 64);
		w.FireBullet(startPos, m_bulletDir, GetSide());
		m_isFireDelayed = 30;
	}

	/*the whenever the player fires a bullet then there is a delay
	to determine when the player can shoot again*/
	if (m_isFireDelayed > 0)
	{
		m_isFireDelayed--;
	}

	/*check for when the player animation frame
	exceeds the maximum frame count, when it does then 
	loop back to the first frame. Add a delay similar to the shoot delay for the animation as well*/
	if (m_frameNum > 4)
	{
		m_frameNum = 1;
	}
	if (m_frameNum < 5)
	{
		m_animationDelay--;
		if (m_animationDelay <= 0)
		{
			m_frameNum++;
			m_animationDelay = 50;
		}
	}

}

void PlayerEntity::Death(World& w)
{
	m_pos = m_spawnPos;
}
