//
// Created by Karenina-na on 2023/9/17.
//
#include "AlgInclude.h"

// 冒泡排序
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::bubbleSort(T &arr, bool (*compare)(NT, NT), Evaluate& evaluate) {

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
    NT temp;
    for (int i = 1; i < arr.size(); i++){
        for (int j = 0; j < i; j++){
            evaluate.addCompCount(1);
            if (compare(arr[i], arr[j])){
                evaluate.addMoveCount(2);
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    evaluate.end();

}

