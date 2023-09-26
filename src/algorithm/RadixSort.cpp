//
// Created by Karenina-na on 2023/9/17.
//
#include "AlgInclude.h"
#include <queue>

// 基数排序
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::radixSort(T &arr, bool (*compare)(NT, NT), Evaluate& evaluate) {

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

    // 找到最大的数
    int in = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[in] < arr[i]) {
            in = i;
        }
    }

    evaluate.addCompCount(1);
    bool flag = compare(arr[in], arr[in + 1 < arr.size() ? in + 1 : in - 1]);

    // 计算最大数的位数
    int maxDigit = 0;
    NT t = arr[in];
    while (t != 0) {
        maxDigit++;
        t = t / 10;
    }

    // 从最低位开始，对数组 arr 按照"指数"进行排序
    std::queue<NT> queue[10];
    for (int i = 0, exp = 1; i < maxDigit; i++, exp *= 10) {

        // 将数组 arr 中的元素索引按照指数 exp 放入队列中
        for (int j = 0; j < arr.size(); j++) {
            evaluate.addMoveCount(1);
            queue[(arr[j] / exp) % 10].push(arr[j]);
        }

        // 将队列中的元素按照顺序放入数组 arr 中
        int index = 0;
        for (auto & j : queue) {
            while (!j.empty()) {
                evaluate.addMoveCount(1);
                arr[index++] = j.front();
                j.pop();
            }
        }
    }

    // 如果是降序，反转数组
    if (flag) {
        for (int i = 0; i < arr.size() / 2; i++) {
            NT temp = arr[i];
            arr[i] = arr[arr.size() - i - 1];
            arr[arr.size() - i - 1] = temp;
        }
    }

    evaluate.end();
}