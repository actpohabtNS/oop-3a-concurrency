#pragma once
#include <algorithm>

template <typename T>
void merge(T* arr, T* temp, int from, int mid, int to)
{
    int temp_idx = 0, first_idx = from, second_idx = mid+1;

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

    for (int arr_idx = from, temp_idx = 0; arr_idx <= to; arr_idx++, temp_idx++) {
        arr[arr_idx] = temp[temp_idx];
    }
}

template <typename T>
void mergesort(T* arr, T* temp, int n)
{
    for (int curr_size = 1; curr_size <= n-1; curr_size *= 2)
    {
        for (int left_start = 0; left_start < n-1; left_start += 2*curr_size)
        {
            int from = left_start;
            int mid = std::min(left_start + curr_size - 1, n-1);
            int to = std::min(left_start + 2*curr_size - 1, n-1);

            merge(arr, temp, from, mid, to);
        }
    }
}