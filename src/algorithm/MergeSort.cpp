//
// Created by Karenina-na on 2023/9/17.
//
#include "Algorithm.h"

// 归并排序
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::mergeSort(T &arr, bool (*compare)(NT, NT)) {

    // 判空 & 判空指针
    if (arr.empty() || compare == nullptr) {
        return;
    }

    // 如果只有一个元素，直接返回
    if (arr.size() == 1) {
        return;
    }

}