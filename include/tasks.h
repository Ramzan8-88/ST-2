// Copyright 2022 UNN-CS
#ifndef TASKS_H
#define TASKS_H

double calculateEarthGap();

struct PoolCosts {
    double pavementCost;
    double fenceCost;
    double totalCost;
};

PoolCosts calculatePoolCosts();

#endif // TASKS_H