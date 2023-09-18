#include <iostream>
#include "Algorithm.h"
#include "BidirectionalLinkList.cc"
#include "AlgInclude.cc"
#include <cstdlib>
#include <vector>

structure::BidirectionalLinkList<int>* create(int n){
    // 随机生成数据插入链表
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

    l = list->copy();
    std::cout<<"insertion sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::insertionSort(*l, algorithm::Compare::greater);
    l->print();
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::insertionSort(*l, algorithm::Compare::less);
    l->print();

}

int main(int argc, char *argv[]) {
    std::cout<<algorithm::Algorithm<int, int>::demo()<<std::endl;
    structure::BidirectionalLinkList<int>* list = create(20);
    test(list);
    return 0;
}
