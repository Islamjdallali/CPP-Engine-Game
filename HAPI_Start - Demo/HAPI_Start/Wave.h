#pragma once
#include "Vector2.h"
#include <vector>

class Wave
{
private:
	std::vector<Vector2> waypoints;
public:

	void ShooterWaves();
	void ChargerWaves();
	Vector2 WaypointManager(int point);
	int WaypointSize() { return waypoints.size(); }
};

