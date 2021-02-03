#include "AI.h"
#include "Wave.h"
#include <iostream>

void AI::GenerateWave(const std::string& name,int behaviour)
{
	Wave* newWave = new Wave();

	if (behaviour == 0)
	{
		newWave->ShooterWaves();
	}
	else if (behaviour == 1)
	{
		newWave->ChargerWaves();
	}

	m_waveMap[name] = newWave;
}


AI::~AI()
{
	//iterate through the unordered map and delete the elements within it, the clear the map
	for (std::unordered_map<std::string, Wave*>::iterator itr = m_waveMap.begin(); itr != m_waveMap.end(); itr++)
	{
		delete (itr->second);
	}
	m_waveMap.clear();
}

Vector2 AI::ShowWaypoint(const std::string& name, int waypoint)
{
	return m_waveMap[name]->WaypointManager(waypoint);
}

int AI::GetWaypointSize(const std::string& name)
{
	return m_waveMap[name]->WaypointSize();
}

