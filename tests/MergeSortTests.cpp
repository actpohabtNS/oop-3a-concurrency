#include <doctest/doctest.h>
#include <algorithm>
#include <vector>

#include "MergeSort.hpp"

TEST_CASE("Merge sort") {
    std::vector<int>    arr { 10, 6, 11, 14, 23 },
                        temp(arr.size());
    SUBCASE("Starting unsorted") {
        mergesort(arr.data(), temp.data(), arr.size());
        CHECK(std::is_sorted(arr.begin(), arr.end()));
    }

    SUBCASE("Starting sorted ascending") {
        mergesort(arr.data(), temp.data(), arr.size());
        CHECK(std::is_sorted(arr.begin(), arr.end()));
    }

    SUBCASE("Starting sorted descending") {
        std::sort(arr.data(), arr.data() + arr.size(), std::greater<int>());
        mergesort(arr.data(), temp.data(), arr.size());
        CHECK(std::is_sorted(arr.begin(), arr.end()));
    }

    SUBCASE("Starting with equal elements") {
        std::fill(arr.data(), arr.data() + arr.size(), 0);
        mergesort(arr.data(), temp.data(), arr.size());
        CHECK(std::is_sorted(arr.begin(), arr.end()));
    }
}
