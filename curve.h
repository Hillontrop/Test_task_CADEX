#pragma once
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <exception>
#include <string>
#include <optional>


// 1. Support a few types of 3D geometric curves – circles, ellipses and 3D helixes. (Simplified
// definitions are below).Each curve should be able to return a 3D point and a first derivative(3D
// vector) per parameter t along the curve.

struct Point
{
    Point() = default;
    Point(double x, double y, double z) : x(x), y(y), z(z)
    {
    }
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};



class Curve
{
public:
    std::optional<Point> GetPointAtT(double t);

    std::optional<Point> GetFirstDerivativeAtT(double t);

    virtual ~Curve() { }

private:
    bool IsValidParameterT(double t) const;

    virtual double CalculateX(double t) = 0;
    virtual double CalculateY(double t) = 0;
    virtual double CalculateZ(double t) = 0;
    virtual double CalculateFirstDerivativeX(double t) = 0;
    virtual double CalculateFirstDerivativeY(double t) = 0;
    virtual double CalculateFirstDerivativeZ(double t) = 0;

protected:
    Point center_{ 0.0, 0.0, 0.0 };
};



class Circle : public Curve
{
public:
    Circle() = default;

    Circle(const Point& center, double radius);

    const double GetRadius() const;

    ~Circle() { }

private:
    void SetRadius(double radius);

    double CalculateX(double t) override;
    double CalculateY(double t) override;
    double CalculateZ(double t) override;

    double CalculateFirstDerivativeX(double t) override;
    double CalculateFirstDerivativeY(double t) override;
    double CalculateFirstDerivativeZ(double t) override;

    double radius_ = 0.0;
};


class Ellips : public Curve
{
public:
    Ellips() = default;

    Ellips(const Point& center, double radius_x, double radius_y);

    const std::pair<double, double> GetRadii() const;

    ~Ellips() { }

private:
    void SetRadii(double radius_x, double radius_y);

    double CalculateX(double t) override;
    double CalculateY(double t) override;
    double CalculateZ(double t) override;

    double CalculateFirstDerivativeX(double t) override;
    double CalculateFirstDerivativeY(double t) override;
    double CalculateFirstDerivativeZ(double t) override;

    double radius_x_ = 0.0;
    double radius_y_ = 0.0;
};


class Helix : public Curve
{
public:
    Helix() = default;

    Helix(const Point& center, double radius, double step);

    const double GetRadius() const;

    ~Helix() { }

private:
    void SetRadius(double radius);

    double CalculateX(double t) override;
    double CalculateY(double t) override;
    double CalculateZ(double t) override;

    double CalculateFirstDerivativeX(double t) override;
    double CalculateFirstDerivativeY(double t) override;
    double CalculateFirstDerivativeZ(double t) override;

    double radius_ = 0.0;
    double step_ = 0.0;
};