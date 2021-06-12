#include <thread>

/// Helper function that merges 2 adjacent sub-arrays on place.
/// \tparam T
/// \param arr - pointer to array being sorted in the main function
/// \param temp - pointer to an axillary array
/// \param size - size of the sorting part
template<typename T>
void merge(T* arr, T* temp, size_t size)
{
    size_t middle = size / 2;

    size_t index_left = 0;
    size_t index_right = middle;
    size_t index_sequence = 0;

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

    for (size_t i = 0; i < size; i++)
        arr[i] = temp[i];
}

/// Main sorting function.
/// \tparam T
/// \tparam min_size_to_thread - minimal amount of elements sorted in which another thread will be created
/// \param arr - pointer to array being sorted
/// \param temp - pointer to an axillary array
/// \param size - size of arr and temp
template<typename T, int min_size_to_thread = 10000>
void parallel_mergesort(T* arr, T* temp, size_t size)
{
    if (size > 1)
    {
        size_t middle = size / 2;
        if (size > min_size_to_thread)
        {
            // creating threads for right and left part
            std::thread left(parallel_mergesort<T, min_size_to_thread>, &arr[0], temp, middle);
            std::thread right(parallel_mergesort<T, min_size_to_thread>, &arr[middle], temp, size - middle);
            left.join();
            right.join();
        }
        else
        {
            // merge sort runs itself recurrently
            parallel_mergesort<T, min_size_to_thread>(&arr[0], temp, middle);
            parallel_mergesort<T, min_size_to_thread>(&arr[middle], temp, size - middle);
        }
        merge<T>(arr, temp, size);
    }
}