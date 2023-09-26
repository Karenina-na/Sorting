//
// Created by Karenina-na on 2023/9/17.
//
#include "AlgInclude.h"

// 选择排序
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::selectionSort(T &arr, bool (*compare)(NT, NT), Evaluate& evaluate) {

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

    // 从第一个元素开始遍历
    int index;
    NT temp;
    for (int i = 0; i < arr.size(); i++){
        index = i;
        // 找到最小/最大的元素
        for (int j = i + 1; j < arr.size(); j++){
            evaluate.addCompCount(1);
            if (compare(arr[j], arr[index])){
                index = j;
            }
        }
        evaluate.addMoveCount(2);
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }

    evaluate.end();
}