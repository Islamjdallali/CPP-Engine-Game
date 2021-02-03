#include "World.h"
#include <HAPI_lib.h>

using namespace HAPISPACE;

World::~World()
{
	for (auto p : m_entites)
	{
		delete p;
	}
	delete m_graphics;
	delete m_ai;
}

constexpr int knumBullets{ 100 };
constexpr int knumExplosions{ 10 };

bool World::LoadLevel()
{
	m_graphics = new Graphics();
	m_ai = new AI();

	m_graphics->Initialise(m_width, m_height);

	BYTE* screen = HAPI.GetScreenPointer();

	m_graphics->GetScreenPointer(screen);

	//loading sprites, if the game cannot find the required sprite then return an error message
	if (!m_graphics->LoadSprite("Data\\Player.png", "Player"))
	{
		HAPI.UserMessage("Could not load Player.png", "Error");
		return false;
	}
	if (!m_graphics->LoadSprite("Data\\Background.png", "Background"))
	{
		HAPI.UserMessage("Could not load Background.png", "Error");
		return false;
	}
	if (!m_graphics->LoadSprite("Data\\Bullet.png", "Bullet"))
	{
		HAPI.UserMessage("Could not load Bullet.png", "Error");
		return false;
	}
	if (!m_graphics->LoadSprite("Data\\EnemyShooter.png", "EnemyShooter"))
	{
		HAPI.UserMessage("Could not load EnemyShooter.png", "Error");
		return false;
	}
	if (!m_graphics->LoadSprite("Data\\EnemyCharger.png", "EnemyCharger"))
	{
		HAPI.UserMessage("Could not load EnemyCharger.png", "Error");
		return false;
	}
	if (!m_graphics->LoadSprite("Data\\Explosion.png", "Explosion"))
	{
		HAPI.UserMessage("Could not load Explosion.png", "Error");
		return false;
	}

	//load Font
	if (!HAPI.ChangeFontFromFile("Data\\mini_pixel-7.ttf"))
	{
		HAPI.UserMessage("Could not load mini_pixel-7.ttf", "Error");
		return false;
	}

	//load sound effects
	if (!HAPI.LoadSound("Data\\ExplosionSFX.wav"))
	{
		HAPI.UserMessage("Could not load ExplosionSFX.wav", "Error");
		return false;
	}

	if (!HAPI.LoadSound("Data\\ShootSFX.wav"))
	{
		HAPI.UserMessage("Could not load ShootSFX.wav", "Error");
		return false;
	}

	BackgroundEntity* background = new BackgroundEntity("Background", 0, 0, 800, 600, 0);
	m_entites.push_back(background);

	BackgroundEntity* background2 = new BackgroundEntity("Background", 0, -600, 800, 600, 0);
	m_entites.push_back(background2);

	EnemyEntity* enemyShooter1 = new EnemyEntity("EnemyShooter", 700, 50, 64, 64, 0);
	enemyShooter1->GetAI(m_ai, 0);
	m_entites.push_back(enemyShooter1);

	EnemyEntity* enemyShooter2 = new EnemyEntity("EnemyShooter", 600, 200, 64, 64, 0);
	enemyShooter2->GetAI(m_ai, 0);
	m_entites.push_back(enemyShooter2);

	EnemyEntity* enemyShooter3 = new EnemyEntity("EnemyShooter", 500, 500, 64, 64, 0);
	enemyShooter3->GetAI(m_ai, 0);
	m_entites.push_back(enemyShooter3);

	EnemyEntity* enemyCharger1 = new EnemyEntity("EnemyCharger", 200, 50, 64, 64, 0);
	enemyCharger1->GetAI(m_ai, 1);
	m_entites.push_back(enemyCharger1);

	EnemyEntity* enemyCharger2 = new EnemyEntity("EnemyCharger", 300, 100, 64, 64, 0);
	enemyCharger2->GetAI(m_ai, 1);
	m_entites.push_back(enemyCharger2);

	m_bulletStartIndex = m_entites.size();

	//create a set number of bullet instances
	for (size_t i = 0; i < knumBullets; i++)
	{
		BulletEntity* newBullet = new BulletEntity("Bullet", 400, 500, 16, 16, 1);
		m_entites.push_back(newBullet);
	}

	PlayerEntity* player = new PlayerEntity("Player", 400, 400, 128, 128, 5);
	m_entites.push_back(player);

	m_explosionStartIndex = m_entites.size();

	//create a set umber of explosion instances
	for (size_t i = 0; i < knumExplosions; i++)
	{
		ExplosionEntity* explosion = new ExplosionEntity("Explosion", 400, 500, 16, 16, 0);
		m_entites.push_back(explosion);
	}

	return true;
}

void World::FireBullet(Vector2 startPos, Vector2 direction, ESide side)
{
	/*loop through all bullet entities and check whether they are alive or not
	if there is a bullet entity that is not alive, then make it alive and 
	call the Fire function within it. Also play the shootSFX*/
	for (size_t i = m_bulletStartIndex; i < m_bulletStartIndex + knumBullets; i++)
	{
		if (!m_entites[i]->IsAlive())
		{
			m_entites[i]->ToggleAlive();
			m_entites[i]->Fire(startPos, direction);

			int bulletInstance;

			HAPI_TSoundOptions options(1, false, 0, 1);

			HAPI.PlaySound("Data\\ShootSFX.wav", options, bulletInstance);
			break;
		}
	}
}

void World::SpawnExplosion(Vector2 pos)
{
	/*loop through all explosion entities and check whether they are alive or not
	if there is a explosion entity that is not alive, then make it alive and
	set its position using the entity setter. Also play the explosionSFX*/
	for (int i = m_explosionStartIndex; i < m_explosionStartIndex + knumExplosions; i++)
	{
		if (!m_entites[i]->IsAlive())
		{
			m_entites[i]->ToggleAlive();
			m_entites[i]->SetPos(pos);

			int explosionInstance;

			HAPI_TSoundOptions options(1, false, 0, 1);

			HAPI.PlaySound("Data\\ExplosionSFX.wav", options, explosionInstance);
			break;
		}
	}
}

void World::Update()
{
	//game loop
	while (HAPI.Update())
	{
		DWORD timeSinceLastUpdated = HAPI.GetTime() - lastTimeUpdated;
		if (timeSinceLastUpdated >= kTickTime)
		{
			for (auto* e : m_entites)
			{
				if (e->IsAlive())
				{
					//if the entity is alive then draw the entity and update their behaviour
					e->DrawEntity(m_graphics);
					e->Update(*this);
				}

				if (e->GetName() == "Player" && !e->IsAlive())
				{
					HAPI.RenderText(200, 0, HAPI_TColour::BLACK, "Game Over", 100, 0);
					HAPI.RenderText(200, 100, HAPI_TColour::BLACK, "Press 'R' to retry", 50, 0);

					if (m_keyData.scanCode['R'])
					{
						e->ToggleAlive();
					}
				}
			}

			if (m_killedEnemies == 5)
			{
				HAPI.RenderText(200, 0, HAPI_TColour::BLACK, "YOU WIN", 100, 0);
			}

			/*loop through all entities that are not neutral and call the
			check collision function between the entity and the other entity that is in the other for loop*/
			for (size_t entity1 = 0; entity1 < m_entites.size(); entity1++)
			{
				if (m_entites[entity1]->GetSide() != ESide::eSideNeutral)
				{
					for (size_t entity2 = entity1 + 1; entity2 < m_entites.size(); entity2++)
					{
						if (m_entites[entity1]->IsAlive() && m_entites[entity2]->IsAlive())
						{
							m_entites[entity1]->CheckCollision(*m_entites[entity2], *this);
						}
					}
				}
			}
			lastTimeUpdated = HAPI.GetTime();
		}

	}
}
