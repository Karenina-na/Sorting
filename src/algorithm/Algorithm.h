//
// Created by Karenina-na on 2023/9/17.
//

#include <ctime>

#ifndef SORTING_ALGORITHM_INTERFACE_FRAMEWORK_ALGORITHM_H
#define SORTING_ALGORITHM_INTERFACE_FRAMEWORK_ALGORITHM_H

namespace algorithm {
    // 比较器
    class Compare {
    public:
        template<typename T>
        static bool less(T a, T b) {
            // 如果 a < b 返回 true, 否则返回 false
            return a <= b;
        }

        template<typename T>
        static bool greater(T a, T b) {
            // 如果 a >= b 返回 true, 否则返回 false
            return a >= b;
        }

    };

    // 评估器
    class Evaluate {
    private:
        long long compCount{};
        long long moveCount{};
        clock_t startTime{};
        clock_t endTime{};
    public:
        Evaluate();

        void start();

        void end();

        void addCompCount(int n);

        void addMoveCount(int n);

        [[nodiscard]] long long getCompCount() const;

        [[nodiscard]] long long getMoveCount() const;

        [[nodiscard]] double getTime() const;

        void reset();
    };

    template<typename T, typename NT>
    class Algorithm {
    private:
        static int partSort(T& arr, int begin, int end,bool (*compare)(NT, NT) );

        static void createHeap(T& arr, int size, bool (*compare)(NT, NT) );

        static void merge(T &arr, int begin1, int end1, int begin2, int end2, bool (*compare)(NT, NT) );
    public:
        static void insertionSort(T &arr, bool (*compare)(NT, NT) );

        static void bubbleSort(T &arr, bool (*compare)(NT, NT) );

        static void selectionSort(T &arr, bool (*compare)(NT, NT) );

        static void shellSort(T &arr, bool (*compare)(NT, NT) );

        static void quickSort(T &arr, bool (*compare)(NT, NT) );

        static void heapSort(T &arr, bool (*compare)(NT, NT) );

        static void radixSort(T &arr, bool (*compare)(NT, NT) );

        static void mergeSort(T &arr, bool (*compare)(NT, NT) );

        const static char* demo();
    };

}
#endif //SORTING_ALGORITHM_INTERFACE_FRAMEWORK_ALGORITHM_H