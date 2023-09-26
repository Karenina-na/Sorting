//
// Created by Karenina-na on 2023/9/17.
//
#include "AlgInclude.h"

// 快速排序
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::quickSort(T &arr, bool (*compare)(NT, NT), Evaluate& evaluate) {

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

    // 快排
    partSort(arr, 0, arr.size() - 1, compare, evaluate);

    evaluate.end();
}

// 单次快速排序
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::partSort(T& arr, int begin, int end, bool (*compare)(NT, NT), Evaluate& evaluate){

    // 寄存key值
    NT temp = arr[begin];
    int i = begin, j = end;

    while (i < j) {

        // 找到第一个比 key 大/小的元素
        while (i != j && (compare(temp, arr[j]) || temp == arr[j])){
            evaluate.addCompCount(1);
            j--;
        }

        // 放入左边
        arr[i] = arr[j];

        // 找到第一个比 key 小/大的元素
        while (i != j && (compare(arr[i], temp) || temp == arr[j])) {
            evaluate.addCompCount(1);
            i++;
        }

        // 放入右边
        arr[j] = arr[i];
        evaluate.addMoveCount(2);
    }

    // begin == end
    arr[i] = temp;
    evaluate.addMoveCount(2);

    // 左边递归
    if (begin < i - 1){
        partSort(arr, begin, i - 1, compare, evaluate);
    }
    // 右边递归
    if (i + 1 < end){
        partSort(arr, i + 1, end, compare, evaluate);
    }
}