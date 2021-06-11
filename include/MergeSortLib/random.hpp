#pragma once

#include <random>
#include <ctime>
#include <concepts>

std::random_device device;
std::seed_seq seq{device(),(unsigned)std::time(nullptr)};
std::mt19937 generator(seq);

template <typename T>
T randomNum(T min, T max)
{
    std::uniform_int_distribution<T> distribution(min,max);
    return distribution(generator);
}