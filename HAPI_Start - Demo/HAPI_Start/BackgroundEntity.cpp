#include "BackgroundEntity.h"

void BackgroundEntity::Update(World& w)
{
	//move the background downwards
	m_pos.y++;

	//once the background is out of the screen, move it back to the top
	if (m_pos.y >= m_frameHeight)
	{
		m_pos.y = -600;
	}
}

void BackgroundEntity::Death(World& w)
{
}
