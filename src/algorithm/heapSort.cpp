//
// Created by Karenina-na on 2023/9/17.
//
#include "Algorithm.h"

// 堆排序
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::heapSort(T &arr, bool (*compare)(NT, NT)) {
    int size = arr.size();

    // 创建堆
    createHeap(arr, size, compare);
    NT temp;

    // 排序
    for (int i = size - 1; i > 0; i--) {

        // 交换堆顶元素和最后一个元素
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 重新调整堆
        createHeap(arr, i, compare);
    }

}

template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::createHeap(T& arr, int size, bool (*compare)(NT, NT)){


}