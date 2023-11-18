#include "curve.h"

const double T_MIN = 0.0;
const double T_MAX = 2.0 * M_PI;

    std::optional<Point> Curve::GetPointAtT(double t)
    {
        if (!IsValidParameterT(t))
        {
            return std::nullopt;
        }
        Point point_at_t(CalculateX(t), CalculateY(t), CalculateZ(t));
        return point_at_t;
    }

    std::optional<Point> Curve::GetFirstDerivativeAtT(double t)
    {
        if (!IsValidParameterT(t))
        {
            return std::nullopt;
        }
        Point first_derivative_at_t(CalculateFirstDerivativeX(t), CalculateFirstDerivativeY(t), CalculateFirstDerivativeZ(t));
        return first_derivative_at_t;
    }

    bool Curve::IsValidParameterT(double t) const
    {
        if (t < T_MIN || t > T_MAX)
        {
            std::cerr << "\"t\" = " << t << " is outside the domain of definition" << std::endl;
            return false;
        }
        return true;
    }




    Circle::Circle(const Point& center, double radius)
    {
        center_ = center;
        try
        {
            SetRadius(radius);
        }
        catch (const std::domain_error& err)
        {
            std::cerr << "Error in Circle constructor: " << err.what() << std::endl;
            radius_ = 0.0;
        }
    }

    const double Circle::GetRadius() const
    {
        return radius_;
    }

    void Circle::SetRadius(double radius)
    {
        if (radius < 0.0)
        {
            throw std::domain_error("\"radius\" = " + std::to_string(radius) + " is outside the domain of definition");
        }
        radius_ = radius;
    }

    double Circle::CalculateX(double t)
    {
        return center_.x + radius_ * std::cos(t);
    }

    double Circle::CalculateY(double t)
    {
        return center_.y + radius_ * std::sin(t);
    }

    double Circle::CalculateZ(double t)
    {
        return 0.0;
    }

    double Circle::CalculateFirstDerivativeX(double t)
    {
        return -radius_ * std::sin(t);
    }

    double Circle::CalculateFirstDerivativeY(double t)
    {
        return radius_ * std::cos(t);
    }

    double Circle::CalculateFirstDerivativeZ(double t)
    {
        return 0.0;
    }




Ellips::Ellips(const Point& center, double radius_x, double radius_y)
    {
        center_ = center;
        try
        {
            SetRadii(radius_x, radius_y);
        }
        catch (const std::domain_error& err)
        {
            std::cerr << "Error in Ellips constructor: " << err.what() << std::endl;
            radius_x_ = 0.0;
            radius_y_ = 0.0;
        }
    }

    const std::pair<double, double> Ellips::GetRadii() const
    {
        return { radius_x_, radius_y_ };
    }

    void Ellips::SetRadii(double radius_x, double radius_y)
    {
        bool radius_x_valid = radius_x > 0.0;
        bool radius_y_valid = radius_y > 0.0;

        if (!radius_x_valid && radius_y_valid)
        {
            throw std::domain_error("\"radius_x\" = " + std::to_string(radius_x) + " is outside the domain of definition");
        }
        else if (radius_x_valid && !radius_y_valid)
        {
            throw std::domain_error("\"radius_y\" = " + std::to_string(radius_y) + " is outside the domain of definition");
        }
        else if (!radius_x_valid && !radius_y_valid)
        {
            throw std::domain_error("\"radius_x\" = " + std::to_string(radius_x) + " and \"radius_y\" = " + std::to_string(radius_y) + " is outside the domain of definition");
        }
        else
        {
            radius_x_ = radius_x;
            radius_y_ = radius_y;
        }
    }

    double Ellips::CalculateX(double t)
    {
        return center_.x + radius_x_ * std::cos(t);
    }

    double Ellips::CalculateY(double t)
    {
        return center_.y + radius_y_ * std::sin(t);
    }

    double Ellips::CalculateZ(double t)
    {
        return 0.0;
    }

    double Ellips::CalculateFirstDerivativeX(double t)
    {
        return -radius_x_ * std::sin(t);
    }

    double Ellips::CalculateFirstDerivativeY(double t)
    {
        return radius_y_ * std::cos(t);
    }

    double Ellips::CalculateFirstDerivativeZ(double t)
    {
        return 0.0;
    }




    Helix::Helix(const Point& center, double radius, double step)
    {
        center_ = center;
        try
        {
            SetRadius(radius);
        }
        catch (const std::domain_error& err)
        {
            std::cerr << "Error in Helix constructor: " << err.what() << std::endl;
            radius_ = 0.0;
        }
        step_ = step;
    }

    const double Helix::GetRadius() const
    {
        return radius_;
    }

    void Helix::SetRadius(double radius)
    {
        if (radius < 0.0)
        {
            throw std::domain_error("\"radius\" = " + std::to_string(radius) + " is outside the domain of definition");
        }
        radius_ = radius;
    }

    double Helix::CalculateX(double t)
    {
        return center_.x + radius_ * std::cos(t);
    }

    double Helix::CalculateY(double t)
    {
        return center_.y + radius_ * std::sin(t);
    }

    double Helix::CalculateZ(double t)
    {
        return center_.z + step_ * t;
    }

    double Helix::CalculateFirstDerivativeX(double t)
    {
        return -radius_ * std::sin(t);
    }

    double Helix::CalculateFirstDerivativeY(double t)
    {
        return radius_ * std::cos(t);
    }

    double Helix::CalculateFirstDerivativeZ(double t)
    {
        return step_;
    }