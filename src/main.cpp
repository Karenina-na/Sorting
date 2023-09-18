#include <iostream>
#include "Algorithm.h"
#include "BidirectionalLinkList.cc"
#include "AlgInclude.cc"
#include <cstdlib>
#include <vector>

structure::BidirectionalLinkList<int>* create(int n){
    // 随机生成数据插入链表
    srand((unsigned)time(NULL));
    auto* list = new structure::BidirectionalLinkList<int>();
    for (int i = 0; i < n; i++) {
        list->insertAtTail(rand() % 100);
    }
    return list;
}

void test(structure::BidirectionalLinkList<int>* list){
    structure::BidirectionalLinkList<int>* l;

    std::cout<<"original list: "<<std::endl;
    list->print();
    std::cout<<std::endl;

    l = list->copy();
    std::cout<<"insertion sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::insertionSort(*l, algorithm::Compare::greater);
    l->print();
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::insertionSort(*l, algorithm::Compare::less);
    l->print();
    std::cout<<std::endl;

    l = list->copy();
    std::cout<<"bubble sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::bubbleSort(*l, algorithm::Compare::greater);
    l->print();
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::bubbleSort(*l, algorithm::Compare::less);
    l->print();
    std::cout<<std::endl;

    l = list->copy();
    std::cout<<"selection sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::selectionSort(*l, algorithm::Compare::greater);
    l->print();
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::selectionSort(*l, algorithm::Compare::less);
    l->print();
    std::cout<<std::endl;

    l = list->copy();
    std::cout<<"shell sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::shellSort(*l, algorithm::Compare::greater);
    l->print();
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::shellSort(*l, algorithm::Compare::less);
    l->print();
    std::cout<<std::endl;

    l = list->copy();
    std::cout<<"quick sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::quickSort(*l, algorithm::Compare::greater);
    l->print();
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::quickSort(*l, algorithm::Compare::less);
    l->print();
    std::cout<<std::endl;

    l = list->copy();
    std::cout<<"heap sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::heapSort(*l, algorithm::Compare::greater);
    l->print();
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::heapSort(*l, algorithm::Compare::less);
    l->print();
    std::cout<<std::endl;
}

int main(int argc, char *argv[]) {
    std::cout<<algorithm::Algorithm<int, int>::demo()<<std::endl;
    structure::BidirectionalLinkList<int>* list = create(20);
    test(list);

//    std::vector<int> v{3, 7, 5, 1, 2};
//    algorithm::Algorithm<std::vector<int>,int>::quickSort(v, algorithm::Compare::greater);
    return 0;
}
