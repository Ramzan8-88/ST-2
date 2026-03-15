// Copyright 2022 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

double calculateEarthGap();

struct PoolCosts {
	double pavementCost;
	double fenceCost; 
	double totalCost; 
};

PoolCosts calculatePoolCosts();

#endif  // INCLUDE_TASKS_H_
