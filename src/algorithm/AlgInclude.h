//
// Created by Karenina-na on 2023/9/17.
//

#ifndef SORTING_ALGORITHM_INTERFACE_FRAMEWORK_ALGINCLUDE_H
#define SORTING_ALGORITHM_INTERFACE_FRAMEWORK_ALGINCLUDE_H

#include <ctime>
#include <thread>
#include <atomic>

namespace algorithm {
    // 比较器
    class Compare {
    public:
        template<typename T>
        static bool less(T a, T b) {
            // 如果 a < b 返回 true, 否则返回 false
            return a < b;
        }

        template<typename T>
        static bool greater(T a, T b) {
            // 如果 a >= b 返回 true, 否则返回 false
            return a > b;
        }

    };

    // 评估器
    class Evaluate {
    private:
        std::atomic<long long> compCount{};
        std::atomic<long long> moveCount{};
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

        bool flag = true;
    };

    template<typename T, typename NT>
    class Algorithm {
    private:
        void partSort(T& arr, int begin, int end,bool (*compare)(NT, NT), Evaluate& evaluate);

        void createHeap(T& arr, int size, bool (*compare)(NT, NT), Evaluate& evaluate);

        void merge(T &arr, int begin1, int end1, int begin2, int end2, bool (*compare)(NT, NT), Evaluate& evaluate);

        void sortStack(T &arr, int begin, int end, bool (&compare)(NT, NT), algorithm::Evaluate& evaluate, int deep = 0);
        void sortInsertion(T& arr, int begin, int end, bool (&compare)(NT, NT), algorithm::Evaluate& evaluate);
        int threeGetMid(T &arr, int a, int b, int c, bool (&compare)(NT, NT), algorithm::Evaluate& evaluate);
    public:
        void insertionSort(T &arr, bool (*compare)(NT, NT), Evaluate& evaluate);

        void bubbleSort(T &arr, bool (*compare)(NT, NT), Evaluate& evaluate);

        void selectionSort(T &arr, bool (*compare)(NT, NT), Evaluate& evaluate);

        void shellSort(T &arr, bool (*compare)(NT, NT), Evaluate& evaluate);

        void quickSort(T &arr, bool (*compare)(NT, NT), Evaluate& evaluate);

        void heapSort(T &arr, bool (*compare)(NT, NT), Evaluate& evaluate);

        void radixSort(T &arr, bool (*compare)(NT, NT), Evaluate& evaluate);

        void mergeSort(T &arr, bool (*compare)(NT, NT), Evaluate& evaluate);

        const static char* demo();

        void sort(T &arr, bool (*compare)(NT, NT), algorithm::Evaluate& evaluate);
        unsigned int max_deep = 12; //  最大递归深度 线程数 = 2^max_deep
    };

}
#endif //SORTING_ALGORITHM_INTERFACE_FRAMEWORK_ALGINCLUDE_H