#include "Algorithm.h"
#include "AlgInclude.cc"
#include "Distribution.h"
#include "DisInclude.cc"
#include "BidirectionalLinkList.cc"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

structure::BidirectionalLinkList<int>* create(int n){
    // 随机生成数据插入链表
    srand((unsigned)time(NULL));
    auto* list = new structure::BidirectionalLinkList<int>();
    for (int i = 0; i < n; i++) {
        list->insertAtTail(rand() % n);
    }
    return list;
}

void test(structure::BidirectionalLinkList<int>* list, bool build){
    structure::BidirectionalLinkList<int>* l;
    algorithm::Evaluate evaluate;

    std::cout<<"original list: "<<std::endl;

    l = list->copy();
    if (build) {
        l->build();
    }
    std::cout<<"insertion sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::insertionSort(*l, algorithm::Compare::greater, evaluate);
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::insertionSort(*l, algorithm::Compare::less, evaluate);
    std::cout<<"time: "<<evaluate.getTime()<<std::endl;
    std::cout<<"comp count: "<<evaluate.getCompCount()<<std::endl;
    std::cout<<"move count: "<<evaluate.getMoveCount()<<std::endl;
    std::cout<<std::endl;

    l = list->copy();
    if (build) {
        l->build();
    }
    std::cout<<"bubble sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::bubbleSort(*l, algorithm::Compare::greater, evaluate);
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::bubbleSort(*l, algorithm::Compare::less, evaluate);
    std::cout<<"time: "<<evaluate.getTime()<<std::endl;
    std::cout<<"comp count: "<<evaluate.getCompCount()<<std::endl;
    std::cout<<"move count: "<<evaluate.getMoveCount()<<std::endl;
    std::cout<<std::endl;

    l = list->copy();
    if (build) {
        l->build();
    }
    std::cout<<"selection sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::selectionSort(*l, algorithm::Compare::greater, evaluate);
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::selectionSort(*l, algorithm::Compare::less, evaluate);
    std::cout<<"time: "<<evaluate.getTime()<<std::endl;
    std::cout<<"comp count: "<<evaluate.getCompCount()<<std::endl;
    std::cout<<"move count: "<<evaluate.getMoveCount()<<std::endl;
    std::cout<<std::endl;

    l = list->copy();
    if (build) {
        l->build();
    }
    std::cout<<"shell sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::shellSort(*l, algorithm::Compare::greater, evaluate);
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::shellSort(*l, algorithm::Compare::less, evaluate);
    std::cout<<"time: "<<evaluate.getTime()<<std::endl;
    std::cout<<"comp count: "<<evaluate.getCompCount()<<std::endl;
    std::cout<<"move count: "<<evaluate.getMoveCount()<<std::endl;
    std::cout<<std::endl;

    l = list->copy();
    if (build) {
        l->build();
    }
    std::cout<<"quick sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::quickSort(*l, algorithm::Compare::greater, evaluate);
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::quickSort(*l, algorithm::Compare::less, evaluate);
    std::cout<<"time: "<<evaluate.getTime()<<std::endl;
    std::cout<<"comp count: "<<evaluate.getCompCount()<<std::endl;
    std::cout<<"move count: "<<evaluate.getMoveCount()<<std::endl;
    std::cout<<std::endl;

    l = list->copy();
    if (build) {
        l->build();
    }
    std::cout<<"heap sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::heapSort(*l, algorithm::Compare::greater, evaluate);
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::heapSort(*l, algorithm::Compare::less, evaluate);
    std::cout<<"time: "<<evaluate.getTime()<<std::endl;
    std::cout<<"comp count: "<<evaluate.getCompCount()<<std::endl;
    std::cout<<"move count: "<<evaluate.getMoveCount()<<std::endl;
    std::cout<<std::endl;

    l = list->copy();
    if (build) {
        l->build();
    }
    std::cout<<"radix sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::radixSort(*l, algorithm::Compare::greater, evaluate);
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::radixSort(*l, algorithm::Compare::less, evaluate);
    std::cout<<"time: "<<evaluate.getTime()<<std::endl;
    std::cout<<"comp count: "<<evaluate.getCompCount()<<std::endl;
    std::cout<<"move count: "<<evaluate.getMoveCount()<<std::endl;
    std::cout<<std::endl;

    l = list->copy();
    if (build) {
        l->build();
    }
    std::cout<<"merge sort: "<<std::endl;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::mergeSort(*l, algorithm::Compare::greater, evaluate);
    algorithm::Algorithm<structure::BidirectionalLinkList<int>,
            structure::BidirectionalLinkListNode<int>>::mergeSort(*l, algorithm::Compare::less, evaluate);
    std::cout<<"time: "<<evaluate.getTime()<<std::endl;
    std::cout<<"comp count: "<<evaluate.getCompCount()<<std::endl;
    std::cout<<"move count: "<<evaluate.getMoveCount()<<std::endl;
    std::cout<<std::endl;
}

void checkForGreater(structure::BidirectionalLinkList<int>& list){
    // 检验从大到小
    structure::BidirectionalLinkListNode<int> last = list[0];
    for (int i = 1; i < list.size(); i++) {
        if (last < list[i]) {
            std::cout<<"error"<<std::endl;
            return;
        }
        last = list[i];
    }
}

void checkForLess(structure::BidirectionalLinkList<int>& list){
    // 检验从小到大
    structure::BidirectionalLinkListNode<int> last = list[0];
    for (int i = 1; i < list.size(); i++) {
        if (last > list[i]) {
            std::cout<<"error"<<std::endl;
            return;
        }
        last = list[i];
    }
}

void testAlgorithm(structure::BidirectionalLinkList<int> list,
                    void (*algorithm)(structure::BidirectionalLinkList<int>&,
                            bool (*)(structure::BidirectionalLinkListNode<int>,
                                    structure::BidirectionalLinkListNode<int>),
                            algorithm::Evaluate&),
                            bool show){
    /*
    structure::BidirectionalLinkList<int>* list = create(2);
//    list->print();
    std::cout<<std::endl;

    testAlgorithm(*list, algorithm::Algorithm<structure::BidirectionalLinkList<int>,
                    structure::BidirectionalLinkListNode<int>>::radixSort, false);
     */
    algorithm::Evaluate evaluate;
    structure::BidirectionalLinkList<int> *l;

    // 从小到大
    l = list.copy();
    l->build();
    std::cout<<"from less to greater: "<<std::endl;
    algorithm(*l, algorithm::Compare::less, evaluate);
    checkForLess(*l);
    std::cout<<"time: "<<evaluate.getTime()<<std::endl;
    std::cout<<"comp count: "<<evaluate.getCompCount()<<std::endl;
    std::cout<<"move count: "<<evaluate.getMoveCount()<<std::endl;
    if (show) {
        l->print();
    }
    std::cout<<std::endl;

    // 从大到小
    l = list.copy();
    l->build();
    std::cout<<"from greater to less: "<<std::endl;
    algorithm(*l, algorithm::Compare::greater, evaluate);
    checkForGreater(*l);
    std::cout<<"time: "<<evaluate.getTime()<<std::endl;
    std::cout<<"comp count: "<<evaluate.getCompCount()<<std::endl;
    std::cout<<"move count: "<<evaluate.getMoveCount()<<std::endl;
    if (show) {
        l->print();
    }
}

void testDistribution(int n){
    // 均匀分布
    std::cout<<"uniform distribution: "<<std::endl;
    distribution::Uniform<int> uniform(n, 0, 20);
    std::vector<int> *uVector = uniform.generate();
    std::vector<int> uCount(20, 0);
    for (int i : *uVector) {
        uCount[i]++;
    }
    for (int i = 0; i < uCount.size(); i++) {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    for (int i : uCount) {
        std::cout<<" "<<i;
    }
    std::cout<<std::endl<<std::endl;

    // 高斯分布
    std::cout<<"gaussian distribution: "<<std::endl;
    distribution::Gaussian<int> gaussian(n, -10, 10, 0, 1, 100);
    std::vector<int> *gVector = gaussian.generate();
    std::vector<int> gCount(21, 0);
    for (int i : *gVector) {
        gCount[i + 10]++;
    }
    for (int i = 0; i < gCount.size(); i++) {
        std::cout<<i - 10<<" ";
    }
    std::cout<<std::endl;
    for (int i : gCount) {
        std::cout<<" "<<i;
    }
    std::cout<<std::endl<<std::endl;

    // 泊松分布
    std::cout<<"poisson distribution: "<<std::endl;
    distribution::Poisson<int> poisson(n, 0, 20, 3);
    std::vector<int> *pVector = poisson.generate();
    std::vector<int> pCount(20, 0);
    for (int i : *pVector) {
        pCount[i]++;
    }
    for (int i = 0; i < pCount.size(); i++) {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    for (int i : pCount) {
        std::cout<<" "<<i;
    }
    std::cout<<std::endl<<std::endl;

    // 指数分布
    std::cout<<"exponential distribution: "<<std::endl;
    distribution::Exponential<int> exponential(n, 0, 20, 0.1);
    std::vector<int> *eVector = exponential.generate();
    std::vector<int> eCount(20, 0);
    for (int i : *eVector) {
        eCount[i]++;
    }
    for (int i = 0; i < eCount.size(); i++) {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    for (int i : eCount) {
        std::cout<<" "<<i;
    }
    std::cout<<std::endl<<std::endl;
}

int main(int argc, char *argv[]) {
    std::cout<<algorithm::Algorithm<int, int>::demo()<<std::endl;
    return 0;
}