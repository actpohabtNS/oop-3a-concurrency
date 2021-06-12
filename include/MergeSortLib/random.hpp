#pragma once

#include <random>
#include <ctime>
#include <concepts>

// using mersenne twister
std::random_device device;
std::seed_seq seq{device(),(unsigned)std::time(nullptr)};
std::mt19937 generator(seq);

///
/// \tparam T - integer type
/// \param min - random number lower bound
/// \param max - random number upper bound
/// \return T - random number in bounds [min, max]
template <typename T>
T randomNum(T min, T max)
{
    std::uniform_int_distribution<T> distribution(min,max);
    return distribution(generator);
}