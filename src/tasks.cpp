// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"

#include <cmath>

double calculateEarthGap() {
	const double EARTH_RADIUS_KM = 6378.1;
	const double ADDED_LENGTH_M = 1.0;
	double earthRadiusM = EARTH_RADIUS_KM * 1000;
	Circle earth(earthRadiusM);
	double earthCircumference = earth.getFerence();
	double newCircumference = earthCircumference + ADDED_LENGTH_M;
	Circle newCircle;
	newCircle.setFerence(newCircumference);
	double gap = newCircle.getRadius() - earthRadiusM;
	return gap;
}

PoolCosts calculatePoolCosts() {
	const double POOL_RADIUS = 3.0;
	const double PATH_WIDTH = 1.0;
	const double PAVEMENT_COST_PER_M2 = 1000.0;
	const double FENCE_COST_PER_M = 2000.0;
	Circle pool(POOL_RADIUS);
	Circle poolWithPath(POOL_RADIUS + PATH_WIDTH);
	double pathArea = poolWithPath.getArea() - pool.getArea();
	double pavementCost = pathArea * PAVEMENT_COST_PER_M2;
	double fenceLength = poolWithPath.getFerence();
	double fenceCost = fenceLength * FENCE_COST_PER_M;
	PoolCosts costs;
	costs.pavementCost = pavementCost;
	costs.fenceCost = fenceCost;
	costs.totalCost = pavementCost + fenceCost;
	return costs;
}
