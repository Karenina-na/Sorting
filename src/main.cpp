#include <iostream>
#include "algorithm/Algorithm.h"
#include "structure/DataStructure.h"

int main() {
    std::cout<<algorithm::Algorithm::demo()<<std::endl;
    DataStructure::BidirectionalLinkList<int> list;
    return 0;
}
