//
// Created by Karenina-na on 2023/9/21.
//

#include "Algorithm.h"
#include <thread>

// 排序
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::sort(T &arr, bool (*compare)(NT, NT), Evaluate& evaluate) {

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

    // 如果数组元素小于20个，使用插入排序
    if (arr.size() < 20) {
        sortInsertion(arr, 0, arr.size() - 1, compare, evaluate);
        evaluate.end();
        return;
    }
    // 多线程
    // lambda
    std::thread t([&](){
        sortStack(arr, 0, arr.size() - 1, compare, evaluate, 0);
    });
    t.join();

    evaluate.end();
}

// 快速排序(并发版)
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::sortStack(T &arr, int begin, int end, bool (*compare)(NT, NT), Evaluate& evaluate, int deep) {

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
    std::thread* t1 = nullptr;
    if (begin < i - 1){
        // 小数组插入排序
        if (i - 1 - begin < 20) {
            sortInsertion(arr, begin, i - 1, compare, evaluate);
        } else {
            if (deep < stack_deep) {
                // lambda
                t1 = new std::thread([&](){
                    sortStack(arr, begin, i - 1, compare, evaluate, deep + 1);
                });
            }else{
                sortStack(arr, begin, i - 1, compare, evaluate, deep + 1);
            }
        }
    }
    // 右边递归
    std::thread* t2 = nullptr;
    if (i + 1 < end){
        // 小数组插入排序
        if (end - i - 1 < 20) {
            sortInsertion(arr, i + 1, end, compare, evaluate);
        } else {
            if (deep < stack_deep) {
                // lambda
                t2 = new std::thread([&](){
                    sortStack(arr, i + 1, end, compare, evaluate, deep + 1);
                });
            }else{
                sortStack(arr, i + 1, end, compare, evaluate, deep + 1);
            }
        }
    }

    // 等待线程结束
    if (t1 != nullptr){
        t1->join();
        delete t1;
    }
    if (t2 != nullptr){
        t2->join();
        delete t2;
    }
}

// 小数组插入排序
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::sortInsertion(T& arr, int begin, int end, bool (*compare)(NT, NT), Evaluate& evaluate) {

    // 寄存key值
    NT temp;
    int j;

    for (int i = begin + 1; i <= end; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= begin && compare(temp, arr[j])) {
            evaluate.addCompCount(1);
            arr[j + 1] = arr[j];
            evaluate.addMoveCount(1);
            j--;
        }
        arr[j + 1] = temp;
        evaluate.addMoveCount(1);
    }
}