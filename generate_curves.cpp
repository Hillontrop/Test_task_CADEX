#include "generate_curves.h"

std::shared_ptr<Curve> GenerateRandomObject()
{
	int choice = RandomInRange(0, 2);  // Выбираем случайный тип объекта

	double min_center = -10000.0;
	double max_center = 10000.0;

	double min_radius = 1.0;
	double max_radius = 10000.0;

	double min_step = -10000.0;
	double max_step = 10000.0;

	switch (choice)
	{
	case 0:
	{
		Point center(RandomInRange(min_center, max_center), RandomInRange(min_center, max_center), 0.0);
		double radius = RandomInRange(min_radius, max_radius);
		return std::make_shared<Circle>(center, radius);
	}
	case 1:
	{
		Point center(RandomInRange(min_center, max_center), RandomInRange(min_center, max_center), 0.0);
		double radius_x = RandomInRange(min_radius, max_radius);
		double radius_y = RandomInRange(min_radius, max_radius);
		return std::make_shared<Ellips>(center, radius_x, radius_y);
	}
	case 2:
	{
		Point center(RandomInRange(min_center, max_center), RandomInRange(min_center, max_center), RandomInRange(min_center, max_center));
		double radius = RandomInRange(min_radius, max_radius);
		double step = RandomInRange(min_step, max_step);
		return std::make_shared<Helix>(center, radius, step);
	}
	default:
		return nullptr;
	}
}

std::vector<std::shared_ptr<Curve>> GenerateRandomObjects(std::size_t size)
{
	if (size == 0)
	{
		return {};
	}
	std::vector<std::shared_ptr<Curve>> curves;
	curves.reserve(size);

	for (size_t i = 0; i < size; ++i)
	{
		std::shared_ptr<Curve> obj = GenerateRandomObject();
		if (obj)
		{
			curves.push_back(obj);
		}
	}
	return curves;
}