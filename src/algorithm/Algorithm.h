//
// Created by Karenina-na on 2023/9/17.
//

#ifndef SORTING_ALGORITHM_INTERFACE_FRAMEWORK_ALGORITHM_H
#define SORTING_ALGORITHM_INTERFACE_FRAMEWORK_ALGORITHM_H
namespace algorithm {
    // 比较器
    class Compare {
    public:
        template<typename T>
        static bool less(T a, T b) {
            return a < b;
        }

        template<typename T>
        static bool greater(T a, T b) {
            return a > b;
        }
    };

    template<typename T>
    class Algorithm {
    public:
        static void insertionSort(T *arr, bool (*compare)(T, T));

        static void bubbleSort(T *arr, bool (*compare)(T, T));

        static void selectionSort(T *arr, bool (*compare)(T, T));

        static void shellSort(T *arr, bool (*compare)(T, T));

        static void quickSort(T *arr, bool (*compare)(T, T));

        static void heapSort(T *arr, bool (*compare)(T, T));

        static void radixSort(T *arr, bool (*compare)(T, T));

        static void mergeSort(T *arr, bool (*compare)(T, T));

        const static char* demo();
    };

}
#endif //SORTING_ALGORITHM_INTERFACE_FRAMEWORK_ALGORITHM_H