#include "Algorithm.h"
#include "Distribution.h"
#include "BidirectionalLinkList.h"
#include <iostream>


structure::BidirectionalLinkList<int>* create(int n){
    // 随机生成数据插入链表
    srand((unsigned)time(NULL));
    auto* list = new structure::BidirectionalLinkList<int>();
    for (int i = 0; i < n; i++) {
        list->insertAtTail(rand() % n);
    }
    return list;
}

template<typename T>
void checkForGreater(T& list){
    // 检验从大到小
    int last = list[0];
    for (int i = 1; i < list.size(); i++) {
        if (last < list[i]) {
            std::cout<<"error"<<std::endl;
            return;
        }
        last = list[i];
    }
}

template<typename T>
void checkForLess(T& list){
    // 检验从小到大
    int last = list[0];
    for (int i = 1; i < list.size(); i++) {
        if (last > list[i]) {
            std::cout<<"error"<<std::endl;
            return;
        }
        last = list[i];
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

void testAlgorithm(structure::BidirectionalLinkList<int>& list,bool show, bool flag){
    algorithm::Evaluate evaluate;
    evaluate.flag = flag;
    structure::BidirectionalLinkList<int> *l;
    algorithm::Algorithm<structure::BidirectionalLinkList<int>, int> algorithm{};

    // 从小到大
    l = list.copy();
    l->build();
    std::cout<<"from less to greater: "<<std::endl;
    algorithm.quickSort(*l, algorithm::Compare::less, evaluate);
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
    algorithm.quickSort(*l, algorithm::Compare::greater, evaluate);
    checkForGreater(*l);
    std::cout<<"time: "<<evaluate.getTime()<<std::endl;
    std::cout<<"comp count: "<<evaluate.getCompCount()<<std::endl;
    std::cout<<"move count: "<<evaluate.getMoveCount()<<std::endl;
    if (show) {
        l->print();
    }
    std::cout<<std::endl;

    // 从小到大
    l = list.copy();
    l->build();
    std::cout<<"from less to greater: "<<std::endl;
    algorithm.sort(*l, algorithm::Compare::less, evaluate);
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
    algorithm.sort(*l, algorithm::Compare::greater, evaluate);
    checkForGreater(*l);
    std::cout<<"time: "<<evaluate.getTime()<<std::endl;
    std::cout<<"comp count: "<<evaluate.getCompCount()<<std::endl;
    std::cout<<"move count: "<<evaluate.getMoveCount()<<std::endl;
    if (show) {
        l->print();
    }
}

int main(int argc, char *argv[]) {
    std::cout << algorithm::Algorithm<int, int>::demo() << std::endl;
    structure::BidirectionalLinkList<int> *list = create(10000000);
    testAlgorithm(*list, false, false);
    return 0;
}