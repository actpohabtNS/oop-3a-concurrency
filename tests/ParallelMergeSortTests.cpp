#include <doctest/doctest.h>
#include <algorithm>
#include <vector>

#include "ParallelMergeSort.hpp"

TEST_CASE("Parallel merge sort") {
    std::vector<int>    arr { 10, 6, 11, 14, 23 },
                        temp(arr.size());
    SUBCASE("Starting unsorted") {
        parallel_mergesort(arr.data(), temp.data(), arr.size());
        CHECK(std::is_sorted(arr.begin(), arr.end()));
    }

    SUBCASE("Starting sorted ascending") {
        parallel_mergesort(arr.data(), temp.data(), arr.size());
        CHECK(std::is_sorted(arr.begin(), arr.end()));
    }

    SUBCASE("Starting sorted descending") {
        std::sort(arr.data(), arr.data() + arr.size(), std::greater<int>());
        parallel_mergesort(arr.data(), temp.data(), arr.size());
        CHECK(std::is_sorted(arr.begin(), arr.end()));
    }

    SUBCASE("Starting with equal elements") {
        std::fill(arr.data(), arr.data() + arr.size(), 0);
        parallel_mergesort(arr.data(), temp.data(), arr.size());
        CHECK(std::is_sorted(arr.begin(), arr.end()));
    }
}


