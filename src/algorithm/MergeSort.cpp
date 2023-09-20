//
// Created by Karenina-na on 2023/9/17.
//
#include "Algorithm.h"
#include <stack>

// 归并排序
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::mergeSort(T &arr, bool (*compare)(NT, NT), Evaluate& evaluate) {

    // 判空 & 判空指针
    if (arr.empty() || compare == nullptr) {
        return;
    }

    // 如果只有一个元素，直接返回
    if (arr.size() == 1) {
        return;
    }

    // 归并排序
    for (int i = 1; i < arr.size(); i *= 2) {
        // 每循环一次，数组长度翻倍
        for (int j = 0; j < arr.size() - i; j += 2 * i) {
            // arr1[j, j + i - 1] 与 arr2[j + i, j + 2 * i - 1] 合并
            merge(arr, j, j + i - 1, j + i,
                    j + 2 * i - 1 < arr.size() - 1 ? j + 2 * i - 1 : arr.size() - 1, compare);
        }
    }
}

// 两个有序数组合并
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::merge(T &arr, int begin1, int end1, int begin2, int end2, bool (*compare)(NT, NT), Evaluate& evaluate) {
    auto* temp = new NT[end2 - begin2 + end1 - begin1 + 2];
    int k = 0, i = begin1, j = begin2;

    // 两个数组合并
    while (i <= end1 && j <= end2) {
        if (compare(arr[i], arr[j])) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // 处理归并剩余
    while (i <= end1) {
        temp[k++] = arr[i++];
    }

    while (j <= end2) {
        temp[k++] = arr[j++];
    }

    // 将 temp 中的元素复制到 arr 指定地点中
    for (int l = 0; l < end2 - begin1 + 1; l++) {
        arr[begin1 + l] = temp[l];
    }
    for (int l = 0; l < end2 - begin2 + 1; l++) {
        arr[begin2 + l] = temp[end1 - begin1 + 1 + l];
    }
}