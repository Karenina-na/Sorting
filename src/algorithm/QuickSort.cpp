//
// Created by Karenina-na on 2023/9/17.
//
#include "Algorithm.h"
#include <stack>
#include <iostream>

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

    // 第一趟为整个数组排序
    std::stack<int> s;
    int mid, begin, end;
    s.push(0);
    s.push(arr.size() - 1);

    // 快速排序--堆栈实现
    while (!s.empty()) {

        // 取出本次快速排序的左右边界
        end = s.top();
        s.pop();
        begin = s.top();
        s.pop();

        mid = partSort(arr, begin, end, compare, evaluate);

        // 将左右两边的子数组压入栈中
        if (begin < mid - 1){
            s.push(begin);
            s.push(mid - 1);
        }

        if (mid + 1 < end){
            s.push(mid + 1);
            s.push(end);
        }
    }

    evaluate.end();
}

// 单次快速排序
template<typename T, typename NT>
int algorithm::Algorithm<T, NT>::partSort(T& arr, int begin, int end,bool (*compare)(NT, NT), Evaluate& evaluate){

    // 寄存key值
    NT temp = arr[begin];

    while (begin < end) {

        // 找到第一个比 key 大/小的元素
        while (begin != end && (compare(temp, arr[end]) || temp == arr[end])){
            evaluate.addCompCount(1);
            end--;
        }

        // 放入左边
        arr[begin] = arr[end];

        // 找到第一个比 key 小/大的元素
        while (begin != end && (compare(arr[begin], temp) || temp == arr[end])) {
            evaluate.addCompCount(1);
            begin++;
        }

        // 放入右边
        arr[end] = arr[begin];
        evaluate.addMoveCount(2);
    }

    // begin == end
    arr[begin] = temp;
    evaluate.addMoveCount(1);

    return begin;
}