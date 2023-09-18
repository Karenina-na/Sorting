//
// Created by Karenina-na on 2023/9/17.
//
#include "algorithm.h"

// 插入排序
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::insertionSort(T &arr, bool (*compare)(NT, NT)) {

    // 判空 & 判空指针
    if (arr.empty() || compare == nullptr) {
        return;
    }

    // 如果只有一个元素，直接返回
    if (arr.size() == 1) {
        return;
    }

    // 从第二个元素开始遍历
    int j = 0;
    NT temp;
    for (int i = 1; i < arr.size(); i++){

        temp = arr[i];
        j = i - 1;

        // 找到第一个比 arr[i] 大/小的元素
        while (j >= 0 && compare(temp, arr[j])) {
            arr[j + 1] = arr[j];
            j--;
        }

        // 在 j+1 处插入 arr[i]
        arr[j + 1] = temp;
    }
}