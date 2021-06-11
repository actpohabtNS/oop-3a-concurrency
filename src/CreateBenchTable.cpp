#include <exception>
#include <iostream>
#include <fort.hpp>
#include <chrono>
#include <cmath>
#include <vector>
#include <clocale>
#include <random>

#include "MergeSort.hpp"
#include "ParallelMergeSort.hpp"
#include "random.hpp"

int main() try {
    const size_t MinPowByBaseTwo = 23;
    const size_t MaxPowByBaseTwo = 26;
    const size_t RepeatsPrecision = 10;

    fort::char_table table;
    table << fort::header;
    table << "Elements";

    table[0][1] = "Sequential";
    table[0][2] = "Concurrent";

    for (size_t i = MinPowByBaseTwo,j = 1; i <= MaxPowByBaseTwo; ++i, ++j) {
        table[j][0] = std::to_string((int)std::pow(2, i));
    }

    for (size_t i = MinPowByBaseTwo, N = std::pow(2, i), j = 1; i <= MaxPowByBaseTwo; ++i, N *= 2, ++j) {
        std::vector<uint_fast32_t> arr1(N), temp(N);
        std::generate(arr1.data(), arr1.data() + N, [N](){return randomNum<uint_fast32_t>(0, N);});
        std::vector<uint_fast32_t> arr2(arr1);

        std::random_device rd;
        std::mt19937 g(rd());

        std::chrono::milliseconds gen_dur_s(0);
        for (int k = 0; k < RepeatsPrecision; ++k) {
            auto t1_s = std::chrono::high_resolution_clock::now();
            mergesort(arr1.data(), temp.data(), N);
            auto t2_s = std::chrono::high_resolution_clock::now();
            auto dur_s = std::chrono::duration_cast<std::chrono::milliseconds>(t2_s - t1_s);
            gen_dur_s += dur_s;

            std::shuffle(arr1.data(), arr1.data() + N, g);
        }
        table[j][1] = std::to_string(gen_dur_s.count() / RepeatsPrecision);

        std::chrono::milliseconds gen_dur_c(0);
        for (int k = 0; k < RepeatsPrecision; ++k) {
            auto t1 = std::chrono::high_resolution_clock::now();
            parallel_mergesort(arr1.data(), temp.data(), N);
            auto t2 = std::chrono::high_resolution_clock::now();
            auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
            gen_dur_c += dur;

            std::shuffle(arr1.data(), arr1.data() + N, g);
        }
        table[j][2] = std::to_string(gen_dur_c.count() / RepeatsPrecision);
    }

    std::cout << "Repeats Precision: " << RepeatsPrecision << " times." << std::endl;
    std::cout << table.to_string() << std::endl;

    return 0;
} catch (const std::exception & ex) {
    std::cout << ex.what();
}
