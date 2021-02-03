#include "Wave.h"
#include <iostream>
#include <random>

void Wave::ShooterWaves()
{
	//create waypoints for the shooter enemies
	waypoints.push_back({ 0, 50 });
	waypoints.push_back({ 800,10 });
}

void Wave::ChargerWaves()
{
	//create waypoints for the charger enemies
	waypoints.push_back({ 0,-50 });
	waypoints.push_back({ 20,650 });
	waypoints.push_back({ 25,-50 });
	waypoints.push_back({ 500,650 });
	waypoints.push_back({ 510,-50 });
}

Vector2 Wave::WaypointManager(int point)
{
	return waypoints[point];
}
