//
// Created by Karenina-na on 2023/9/17.
//
#include "algorithm.h"

// 冒泡排序
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::bubbleSort(T &arr, bool (*compare)(NT, NT)) {

    // 判空 & 判空指针
    if (arr.empty() || compare == nullptr) {
        return;
    }

    // 如果只有一个元素，直接返回
    if (arr.size() == 1) {
        return;
    }

    // 从第一个元素开始遍历
    NT temp;
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j <= i; j++){
            if (compare(arr[i], arr[j])){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

}

