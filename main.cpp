#define _USE_MATH_DEFINES
#include <iostream>
#include <memory>
#include <algorithm>
#include <numeric>

#include "curve.h"
#include "generate_curves.h"


void PrintPoint(const Point& point, bool is_derivatives)
{
	std::cout << (is_derivatives ? "x\'(t) = " : "x(t) = ") << point.x
		<< (is_derivatives ? " y\'(t) = " : " y(t) = ") << point.y
		<< (is_derivatives ? " z\'(t) = " : " z(t) = ") << point.z
		<< std::endl;
}


int main()
{
	// 2. Populate a container (e.g. vector or list) of objects of these types created in random manner with
	size_t size_vector;
	std::cout << "Enter the number of objects -> ";
	std::cin >> size_vector;
	std::cout << std::endl;
	std::vector<std::shared_ptr<Curve>> generated_objects = GenerateRandomObjects(size_vector);


	// 3. Print coordinates of points and derivatives of all curves in the container at t=PI/4.
	for (const auto& object : generated_objects)
	{
		std::cout << "Point at t = PI/4 -> ";
		PrintPoint(object->GetPointAtT(M_PI / 4).value(), false);
		std::cout << "Derivatives at t=PI/4 -> ";
		PrintPoint(object->GetFirstDerivativeAtT(M_PI / 4).value(), true);
		std::cout << std::endl;
	}


	// 4. Populate a second container that would contain only circles from the first container.
	// Make sure the second container shares(i.e. not clones) circles of the first one, e.g.via pointers.
	std::vector<std::shared_ptr<Circle>> only_circles;
	only_circles.reserve(generated_objects.size() / 3);

	for (const auto& curve : generated_objects)
	{
		std::shared_ptr<Circle> circle = std::dynamic_pointer_cast<Circle>(curve);

		if (circle)
		{
			only_circles.push_back(circle);
		}
	}
	only_circles.shrink_to_fit();


	// 5. Sort the second container in the ascending order of circles’ radii.That is, the first element has the
	// smallest radius, the last - the greatest.
	std::sort(only_circles.begin(), only_circles.end(),
		[](const auto& first_circle, const auto& second_circle)
		{
			return first_circle->GetRadius() < second_circle->GetRadius();
		});
	

	// 6. Compute the total sum of radii of all curves in the second container.
	double sum_radii = std::accumulate(only_circles.begin(), only_circles.end(), 0.0,
		[](double current_sum, const auto& circle)
		{
			return current_sum + circle->GetRadius();
		});

	return 0;
}