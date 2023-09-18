#include <iostream>
#include "Algorithm.h"
#include "BidirectionalLinkList.cc"
#include "AlgInclude.cc"
#include <cstdlib>
#include <vector>
#include <ctime>

structure::BidirectionalLinkList<int>* create(int n){
    // 随机生成数据插入链表
    srand((unsigned)time(NULL));
    auto* list = new structure::BidirectionalLinkList<int>();
    for (int i = 0; i < n; i++) {
        list->insertAtTail(rand() % 100);
    }
    return list;
}

void test(structure::BidirectionalLinkList<int>* list, bool build){
    structure::BidirectionalLinkList<int>* l;

    std::cout<<"original list: "<<std::endl;

    l = list->copy();
    if (build) {
        l->build();
    }
    std::cout<<"insertion sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::insertionSort(*l, algorithm::Compare::greater);
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::insertionSort(*l, algorithm::Compare::less);

    l = list->copy();
    if (build) {
        l->build();
    }
    std::cout<<"bubble sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::bubbleSort(*l, algorithm::Compare::greater);
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::bubbleSort(*l, algorithm::Compare::less);

    l = list->copy();
    if (build) {
        l->build();
    }
    std::cout<<"selection sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::selectionSort(*l, algorithm::Compare::greater);
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::selectionSort(*l, algorithm::Compare::less);

    l = list->copy();
    if (build) {
        l->build();
    }
    std::cout<<"shell sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::shellSort(*l, algorithm::Compare::greater);
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::shellSort(*l, algorithm::Compare::less);

    l = list->copy();
    if (build) {
        l->build();
    }
    std::cout<<"quick sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::quickSort(*l, algorithm::Compare::greater);
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::quickSort(*l, algorithm::Compare::less);

    l = list->copy();
    if (build) {
        l->build();
    }
    std::cout<<"heap sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::heapSort(*l, algorithm::Compare::greater);
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::heapSort(*l, algorithm::Compare::less);

    l = list->copy();
    if (build) {
        l->build();
    }
    std::cout<<"radix sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::radixSort(*l, algorithm::Compare::greater);
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::radixSort(*l, algorithm::Compare::less);

    l = list->copy();
    if (build) {
        l->build();
    }
    std::cout<<"merge sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::mergeSort(*l, algorithm::Compare::greater);
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::mergeSort(*l, algorithm::Compare::less);
}

int main(int argc, char *argv[]) {
    std::cout<<algorithm::Algorithm<int, int>::demo()<<std::endl;
    structure::BidirectionalLinkList<int>* list = create(2000);

    // 查看时间
    clock_t start1, start2, end1, end2;

    start1 = clock();
    test(list, false);
    end1 = clock();

    start2 = clock();
    test(list, true);
    end2 = clock();

    std::cout<<"time without build: "<<(double)(end1 - start1) / CLOCKS_PER_SEC<<std::endl;
    std::cout<<"time with build: "<<(double)(end2 - start2) / CLOCKS_PER_SEC<<std::endl;

    return 0;
}


