#pragma once
#include <type_traits>
#include <random>
#include <memory>
#include <string>
#include <exception>

#include "curve.h"


inline std::mt19937 rng(std::random_device{}());

template <typename T>
T RandomInRange(T min, T max)
{
	using DistributionType = std::conditional_t<std::is_floating_point_v<T>, std::uniform_real_distribution<T>, std::uniform_int_distribution<T>>;
	DistributionType dist(min, max);
	return dist(rng);
}

std::shared_ptr<Curve> GenerateRandomObject();

std::vector<std::shared_ptr<Curve>> GenerateRandomObjects(std::size_t size);