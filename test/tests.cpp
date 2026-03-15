// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"
#include <cmath>
#include <stdexcept>

TEST(CircleTest, DefaultConstructor) {
    Circle c;
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, ConstructorWithRadius) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 25.0);
}

TEST(CircleTest, SetRadius) {
    Circle c;
    c.setRadius(3.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 3.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 9.0);
}

TEST(CircleTest, SetFerence) {
    Circle c;
    double ference = 10.0;
    c.setFerence(ference);
    double expectedRadius = ference / (2 * M_PI);
    EXPECT_DOUBLE_EQ(c.getFerence(), ference);
    EXPECT_DOUBLE_EQ(c.getRadius(), expectedRadius);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * expectedRadius * expectedRadius);
}

TEST(CircleTest, SetArea) {
    Circle c;
    double area = 50.0;
    c.setArea(area);
    double expectedRadius = std::sqrt(area / M_PI);
    EXPECT_DOUBLE_EQ(c.getArea(), area);
    EXPECT_DOUBLE_EQ(c.getRadius(), expectedRadius);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * expectedRadius);
}

TEST(CircleTest, NegativeRadius) {
    Circle c;
    EXPECT_THROW(c.setRadius(-1.0), std::invalid_argument);
}

TEST(CircleTest, NegativeFerence) {
    Circle c;
    EXPECT_THROW(c.setFerence(-5.0), std::invalid_argument);
}

TEST(CircleTest, NegativeArea) {
    Circle c;
    EXPECT_THROW(c.setArea(-10.0), std::invalid_argument);
}

TEST(CircleTest, ZeroValues) {
    Circle c;
    c.setRadius(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, LargeValues) {
    Circle c(1e6);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1e6);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 1e6);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 1e12);
}

TEST(CircleTest, SmallValues) {
    Circle c(1e-6);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1e-6);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e-6, 1e-12);
    EXPECT_NEAR(c.getArea(), M_PI * 1e-12, 1e-24);
}

TEST(CircleTest, SequentialUpdates) {
    Circle c;
    c.setRadius(2.0);
    double area1 = c.getArea();
    c.setFerence(c.getFerence() * 2);
    EXPECT_GT(c.getArea(), area1);
    c.setArea(c.getArea() / 4);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
}

TEST(CircleTest, MathematicalConsistency) {
    Circle c(4.0);
    double r = c.getRadius();
    double f = c.getFerence();
    double a = c.getArea();
    EXPECT_DOUBLE_EQ(f, 2 * M_PI * r);
    EXPECT_DOUBLE_EQ(a, M_PI * r * r);
}

TEST(EarthGapTest, PositiveGap) {
    double gap = calculateEarthGap();
    EXPECT_GT(gap, 0.0);
}

TEST(EarthGapTest, GapValue) {
    double gap = calculateEarthGap();
    EXPECT_NEAR(gap, 1.0 / (2 * M_PI), 1e-4);
}

TEST(EarthGapTest, GapInCentimeters) {
    double gap = calculateEarthGap();
    double gapCm = gap * 100;
    EXPECT_NEAR(gapCm, 100.0 / (2 * M_PI), 0.1);
}

TEST(EarthGapTest, GapPrecision) {
    double gap1 = calculateEarthGap();
    double gap2 = calculateEarthGap();
    EXPECT_DOUBLE_EQ(gap1, gap2);
}

TEST(EarthGapTest, GapIndependence) {
    double gap = calculateEarthGap();
    EXPECT_GT(gap, 0.15);
    EXPECT_LT(gap, 0.16);
}

TEST(PoolCostsTest, PositiveCosts) {
    PoolCosts costs = calculatePoolCosts();
    EXPECT_GT(costs.pavementCost, 0.0);
    EXPECT_GT(costs.fenceCost, 0.0);
    EXPECT_GT(costs.totalCost, 0.0);
}

TEST(PoolCostsTest, PavementCost) {
    PoolCosts costs = calculatePoolCosts();
    double expectedPavementCost = (M_PI * 16 - M_PI * 9) * 1000;
    EXPECT_NEAR(costs.pavementCost, expectedPavementCost, 1.0);
}

TEST(PoolCostsTest, FenceCost) {
    PoolCosts costs = calculatePoolCosts();
    double expectedFenceCost = (2 * M_PI * 4) * 2000;
    EXPECT_NEAR(costs.fenceCost, expectedFenceCost, 1.0);
}

TEST(PoolCostsTest, TotalCost) {
    PoolCosts costs = calculatePoolCosts();
    EXPECT_NEAR(costs.totalCost, costs.pavementCost + costs.fenceCost, 1e-6);
}

TEST(PoolCostsTest, CostRatio) {
    PoolCosts costs = calculatePoolCosts();
    EXPECT_GT(costs.fenceCost, costs.pavementCost);
    EXPECT_LT(costs.fenceCost / costs.pavementCost, 3.0);
}

TEST(CircleTest, CopyOperations) {
    Circle c1(5.0);
    Circle c2 = c1;
    EXPECT_DOUBLE_EQ(c2.getRadius(), 5.0);
}

TEST(CircleTest, Assignment) {
    Circle c1(7.0);
    Circle c2;
    c2 = c1;
    EXPECT_DOUBLE_EQ(c2.getRadius(), 7.0);
}

TEST(CircleTest, MultipleUpdates) {
    Circle c;
    for (int i = 1; i <= 5; i++) {
        c.setRadius(i);
        EXPECT_DOUBLE_EQ(c.getRadius(), i);
        EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * i);
    }
}

TEST(CircleTest, PrecisionTest) {
    Circle c;
    c.setRadius(1.0 / 3.0);
    double r = c.getRadius();
    c.setFerence(c.getFerence());
    EXPECT_NEAR(c.getRadius(), r, 1e-12);
}

TEST(PoolCostsTest, ConsistencyWithCircle) {
    Circle pool(3.0);
    Circle poolWithPath(4.0);
    PoolCosts costs = calculatePoolCosts();
    double expectedPathArea = poolWithPath.getArea() - pool.getArea();
    EXPECT_NEAR(costs.pavementCost / 1000.0, expectedPathArea, 1e-6);
}

TEST(EarthGapTest, CalculationMethod) {
    double gap = calculateEarthGap();
    double expectedGap = 1.0 / (2 * M_PI);
    EXPECT_NEAR(gap, expectedGap, 1e-6);
}
