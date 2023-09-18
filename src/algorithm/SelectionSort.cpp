//
// Created by Karenina-na on 2023/9/17.
//
#include "Algorithm.h"

// 选择排序
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::selectionSort(T &arr, bool (*compare)(NT, NT)) {

    // 判空 & 判空指针
    if (arr.empty() || compare == nullptr) {
        return;
    }

    // 如果只有一个元素，直接返回
    if (arr.size() == 1) {
        return;
    }

    // 从第一个元素开始遍历
    int index = 0;
    NT temp;
    for (int i = 0; i < arr.size(); i++){
        for (int j = i + 1; j < arr.size(); j++){
            if (compare(arr[j], arr[index])){
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}