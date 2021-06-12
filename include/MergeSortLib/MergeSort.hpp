#pragma once
#include <algorithm>

/// Helper function that merges 2 adjacent sub-arrays on place.
/// \tparam T
/// \param arr - pointer to array being sorted in the main function
/// \param temp - pointer to an axillary array
/// \param from - an index of main array on which first sub-array starts
/// \param mid - an index of main array on which first sub-array ends and second starts
/// \param to - an index of main array on which second sub-array ends
template <typename T>
void merge(T* arr, T* temp, size_t from, size_t mid, size_t to)
{
    size_t temp_idx = 0, first_idx = from, second_idx = mid+1;

    while(first_idx <= mid && second_idx <= to) {

        if (arr[first_idx] <= arr[second_idx]) {
            temp[temp_idx++] = arr[first_idx++];
        } else {
            temp[temp_idx++] = arr[second_idx++];
        }

    }

    while(first_idx <= mid) {
        temp[temp_idx++] = arr[first_idx++];
    }

    while(second_idx <= to) {
        temp[temp_idx++] = arr[second_idx++];
    }

    for (size_t arr_idx = from, temp_idx = 0; arr_idx <= to; arr_idx++, temp_idx++) {
        arr[arr_idx] = temp[temp_idx];
    }
}

/// Main sorting function.
/// \tparam T
/// \param arr - pointer to array being sorted
/// \param temp - pointer to an axillary array
/// \param n - size of arr and temp
template <typename T>
void mergesort(T* arr, T* temp, size_t n)
{
    for (size_t curr_size = 1; curr_size <= n-1; curr_size *= 2)
    {
        for (size_t left_start = 0; left_start < n-1; left_start += 2*curr_size)
        {
            // division of sorting part
            size_t from = left_start;
            size_t mid = std::min(left_start + curr_size - 1, n-1);
            size_t to = std::min(left_start + 2*curr_size - 1, n-1);

            // merging sorting parts
            merge(arr, temp, from, mid, to);
        }
    }
}