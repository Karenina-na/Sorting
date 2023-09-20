//
// Created by Karenina-na on 2023/9/17.
//
#include "Algorithm.h"

// 堆排序
template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::heapSort(T &arr, bool (*compare)(NT, NT), Evaluate& evaluate) {

    // 判空 & 判空指针
    if (arr.empty() || compare == nullptr) {
        return;
    }

    // 如果只有一个元素，直接返回
    if (arr.size() == 1) {
        return;
    }

    int size = arr.size();

    // 创建堆
    createHeap(arr, size, compare);
    NT temp;

    // 排序
    for (int i = size - 1; i > 0; i--) {

        // 交换堆顶元素和最后一个元素
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 重新调整堆
        createHeap(arr, i, compare);
    }

}

template<typename T, typename NT>
void algorithm::Algorithm<T, NT>::createHeap(T& arr, int size, bool (*compare)(NT, NT), Evaluate& evaluate){
    NT temp;
    int j;

    // 从最后一个非叶子节点开始调整堆
    for (int i = (size - 2) / 2; i >= 0; i--) {

        j = i;
        temp = arr[j];

        // 调整堆，k指向后代节点
        int k = 2 * j + 1;
        while (k < size) {

            // 找到左右孩子中较大的一个
            if (k + 1 < size && compare(arr[k], arr[k + 1])) {
                k++;
            }

            if (compare(temp, arr[k])) {
                arr[j] = arr[k];

                // 继续将指针指向后代节点，继续调整堆
                j = k;
                k = 2 * j + 1;

            } else {
                // 如果父节点大于左右孩子，则不需要调整
                break;
            }
        }

        arr[j] = temp;
    }
}