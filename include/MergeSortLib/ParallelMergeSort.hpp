#include <thread>

template<typename T>
void merge(T* arr, T* temp, int size)
{
    int middle = size / 2;

    int index_left = 0;
    int index_right = middle;
    int index_sequence = 0;

    while (index_left < middle && index_right < size)
    {
        if (arr[index_left] < arr[index_right])
            temp[index_sequence++] = arr[index_left++];
        else
            temp[index_sequence++] = arr[index_right++];
    }

    while (index_left < middle)
        temp[index_sequence++] = arr[index_left++];

    while (index_right < size)
        temp[index_sequence++] = arr[index_right++];

    for (int i = 0; i < size; i++)
        arr[i] = temp[i];
}

template<typename T, int min_size_to_thread = 10000>
void parallel_mergesort(T* arr, T* temp, int size)
{
    if (size > 1)
    {
        int middle = size / 2;
        if (size > min_size_to_thread)
        {
            std::thread left(parallel_mergesort<T, min_size_to_thread>, &arr[0], temp, middle);
            std::thread right(parallel_mergesort<T, min_size_to_thread>, &arr[middle], temp, size - middle);
            left.join();
            right.join();
        }
        else
        {
            parallel_mergesort<T, min_size_to_thread>(&arr[0], temp, middle);
            parallel_mergesort<T, min_size_to_thread>(&arr[middle], temp, size - middle);
        }
        merge<T>(arr, temp, size);
    }
}