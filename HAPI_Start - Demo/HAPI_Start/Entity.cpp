#include "Entity.h"


void Entity::Update(World& w)
{

}

void Entity::Fire(Vector2 startPos, Vector2 dir)
{

}

void Entity::CheckCollision(Entity& other, World& w)
{
	//create two Rectangles (they would be the hitboxes), one for this entity and one for the other entity
	Rectangle rct(0, m_frameWidth, 0, m_frameHeight);

	rct.Translate(m_pos.x, m_pos.y);

	Rectangle otherrct(0, other.m_frameWidth, 0, other.m_frameHeight);

	otherrct.Translate(other.m_pos.x, other.m_pos.y);

	if (rct.right < otherrct.left || rct.right > otherrct.right
		|| rct.bottom < otherrct.top || rct.top > otherrct.bottom)
	{
		//if the 2 rectangles are not inside one another then dont do anything (collision did not happen)
		return;
	}
	else
	{
		if (GetSide() != other.GetSide())
		{
			//if thet have collided then make both entites die
			ToggleAlive();
			other.ToggleAlive();

			Death(w);
			other.Death(w);
		}
	}

	rct.Translate(-m_pos.x, -m_pos.y);

	otherrct.Translate(-other.m_pos.x, -other.m_pos.y);
}

void Entity::DrawEntity(Graphics* g)
{
	m_graphics = g;

	//simply draw in the sprite
	g->DrawSprite(m_spriteName, m_pos.x, m_pos.y,m_frameWidth, m_frameHeight, m_frameNum);
}
