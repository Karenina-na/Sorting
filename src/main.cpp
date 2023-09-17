#include <iostream>
#include "Algorithm.h"
#include "BidirectionalLinkList.cc"

int main(int argc, char *argv[]) {
    std::cout<<algorithm::Algorithm::demo()<<std::endl;
    auto *list = new structure::BidirectionalLinkList<int>();
    return 0;
}
