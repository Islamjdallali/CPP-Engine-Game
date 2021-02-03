#pragma once
#include "Vector2.h"
#include <string>
#include <unordered_map>

class Wave;

class AI
{
private:
	std::unordered_map<std::string, Wave*> m_waveMap;
public:
	void GenerateWave(const std::string& name, int behaviour);
	Vector2 ShowWaypoint(const std::string& name, int waypoint);
	int GetWaypointSize(const std::string& name);
	~AI();
};

