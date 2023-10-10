//
// Created by Karenina-na on 2023/9/26.
//
#include "AlgInclude.h"

// 排序
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::sort(T &arr, bool (*compare)(NT, NT), algorithm::Evaluate& evaluate) {

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
    if (arr.size() < 0) {
        sortInsertion(arr, 0, arr.size() - 1, *compare, evaluate);
        evaluate.end();
        return;
    }

    sortStack(arr, 0, arr.size() - 1, *compare, evaluate);

    evaluate.end();
}

// 快速排序 (优化)
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::sortStack(T &arr, int begin, int end, bool (&compare)(NT, NT), algorithm::Evaluate& evaluate, int deep) {

    // 三数取中
    int mid = threeGetMid(arr, begin, (begin + end) / 2, end, compare, evaluate);

    // 寄存key值，交换到第一个位置
    NT temp = arr[mid];
    arr[mid] = arr[begin];
    int i = begin, j = end;

    // 聚集元素指针
    int L = begin, R = end;

    while (i < j) {

        // 找到第一个比 key 大/小的元素
        while (i != j && (compare(temp, arr[j]) || temp == arr[j])){

            // 右聚集
            if (temp == arr[j]) {   // 将末尾元素放入j
                evaluate.addMoveCount(1);
                arr[j] = arr[R];
                R--;
            }

            evaluate.addCompCount(1);
            j--;
        }

        // 放入左边
        arr[i] = arr[j];

        // 找到第一个比 key 小/大的元素
        while (i != j && (compare(arr[i], temp) || temp == arr[i])) {

            // 左聚集
            if (temp == arr[i]) {   // 将首元素放入i
                evaluate.addMoveCount(1);
                arr[i] = arr[L];
                L++;
            }

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

    // 左聚集处理，L 前全是 key，倒序
    L--;
    i--;
    while (L >= begin) {
        evaluate.addMoveCount(1);
        arr[L] = arr[i];
        arr[i] = temp;
        L--;
        i--;
    }

    // 右聚集处理，R 后全是 key，正序
    R++;
    j++;
    while (R <= end) {
        evaluate.addMoveCount(1);
        arr[R] = arr[j];
        arr[j] = temp;
        R++;
        j++;
    }

    // 左边递归
    bool left = false, right = false;
    if (begin < i){
        // 小数组插入排序
        if (i - begin < 24) {
            sortInsertion(arr, begin, i, compare, evaluate);
        } else {
            if (deep < max_deep && use_thread) {
                left = true;
            } else {
                sortStack(arr, begin, i, compare, evaluate, deep + 1);
            }
        }
    }
    // 右边递归
    if (j < end){
        // 小数组插入排序
        if (end - j < 24) {
            sortInsertion(arr, j, end, compare, evaluate);
        } else {
            if (deep < max_deep && use_thread) {
                right = true;
            } else {
                sortStack(arr, j, end, compare, evaluate, deep + 1);
            }
        }
    }

    // 并发
    if (left && right) {
        std::thread t1([&]{
            sortStack(arr, begin, i, compare, evaluate, deep + 1);
        });
        std::thread t2([&]{
            sortStack(arr, j, end, compare, evaluate, deep + 1);
        });
        t1.join();
        t2.join();
    } else if (left) {
        std::thread t1([&]{
            sortStack(arr, begin, i, compare, evaluate, deep + 1);
        });
        t1.join();
    } else if (right) {
        std::thread t2([&]{
            sortStack(arr, j, end, compare, evaluate, deep + 1);
        });
        t2.join();
    }
}

// 三数取中
template<typename T, typename NT>
int algorithm::Algorithm<T, NT>::threeGetMid(T &arr, int a, int b, int c, bool (&compare)(NT, NT), algorithm::Evaluate& evaluate) {
    // 三数取中
    if (compare(arr[a], arr[b])) {
        evaluate.addCompCount(1);
        if (compare(arr[b], arr[c])) {
            evaluate.addCompCount(1);
            return b;
        } else {
            evaluate.addCompCount(1);
            if (compare(arr[a], arr[c])) {
                evaluate.addCompCount(1);
                return c;
            } else {
                evaluate.addCompCount(1);
                return a;
            }
        }
    } else {
        evaluate.addCompCount(1);
        if (compare(arr[a], arr[c])) {
            evaluate.addCompCount(1);
            return a;
        } else {
            evaluate.addCompCount(1);
            if (compare(arr[b], arr[c])) {
                evaluate.addCompCount(1);
                return c;
            } else {
                evaluate.addCompCount(1);
                return b;
            }
        }
    }
}

// 小数组插入排序
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::sortInsertion(T& arr, int begin, int end, bool (&compare)(NT, NT), algorithm::Evaluate& evaluate) {

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
