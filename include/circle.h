// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 private:
  double radius;
  double ference;
  double area;
  static constexpr double PI = 3.14159265358979323846;

 public:
  explicit Circle(double r = 0.0);
  void setRadius(double r);
  void setFerence(double f);
  void setArea(double a);
  double getRadius() const;
  double getFerence() const;
  double getArea() const;

 private:
  void updateFromRadius();
  void updateFromFerence();
  void updateFromArea();
};

#endif  // INCLUDE_CIRCLE_H_
