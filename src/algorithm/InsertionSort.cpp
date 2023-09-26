//
// Created by Karenina-na on 2023/9/17.
//
#include "AlgInclude.h"

// 插入排序
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::insertionSort(T &arr, bool (*compare)(NT, NT), Evaluate& evaluate) {

    evaluate.reset();
    evaluate.start();

    // 判空 & 判空指针
    if (arr.empty() || compare == nullptr) {
        evaluate.end();
        return;
    }

    // 如果只有一个元素，直接返回
    if (arr.size() == 1) {
        evaluate.end();
        return;
    }

    // 从第二个元素开始遍历
    int j = 0;
    NT temp;
    for (int i = 1; i < arr.size(); i++){

        temp = arr[i];
        j = i - 1;

        // 找到第一个比 arr[i] 大/小的元素
        evaluate.addCompCount(1);
        while (j >= 0 && compare(temp, arr[j])) {
            evaluate.addMoveCount(1);
            arr[j + 1] = arr[j];
            j--;
        }

        // 在 j+1 处插入 arr[i]
        arr[j + 1] = temp;
        evaluate.addMoveCount(2);
    }

    evaluate.end();
}