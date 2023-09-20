//
// Created by Karenina-na on 2023/9/17.
//
#include "Algorithm.h"

// 希尔排序
template<typename T, typename NT>
void algorithm::Algorithm<T,NT>::shellSort(T &arr, bool (*compare)(NT, NT), Evaluate& evaluate) {

    // 判空 & 判空指针
    if (arr.empty() || compare == nullptr) {
        return;
    }

    // 如果只有一个元素，直接返回
    if (arr.size() == 1) {
        return;
    }

    // 希尔排序
    int gap = arr.size() / 2;
    while (gap > 0) {

        // 分组
        for (int i = 0; i < gap; i++){

            // 对每一组进行插入排序
            int k = 0;
            NT temp;
            for (int j = 1; j < arr.size(); j += gap){

                temp = arr[j];
                k = j - 1;

                // 找到第一个比 arr[i] 大/小的元素
                while (k >= 0 && compare(temp, arr[k])) {
                    arr[k + 1] = arr[k];
                    k--;
                }

                // 在 j+1 处插入 arr[i]
                arr[k + 1] = temp;
            }

        }

        gap /= 2;
    }
}