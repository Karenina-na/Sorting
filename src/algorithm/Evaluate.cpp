//
// Created by 15399 on 2023/9/20.
//

#include <ctime>
#include "AlgInclude.h"

// 评估器
algorithm::Evaluate::Evaluate(){
    this->compCount = 0;
    this->moveCount = 0;
    this->startTime = 0;
    this->endTime = 0;
}

// 算法开始
void algorithm::Evaluate::start(){
    this->startTime = clock();
}

// 算法结束
void algorithm::Evaluate::end(){
    this->endTime = clock();
}

// 比较次数加一
void algorithm::Evaluate::addCompCount(int n){
    if (flag){
        this->compCount += n;
    }
}

// 移动次数加一
void algorithm::Evaluate::addMoveCount(int n){
    if (flag){
        this->moveCount += n;
    }
}

// 获取比较次数
long long algorithm::Evaluate::getCompCount() const{
    return this->compCount.load();
}

// 获取移动次数
long long algorithm::Evaluate::getMoveCount() const{
    return this->moveCount.load();
}

// 获取算法运行时间 单位: ms
double algorithm::Evaluate::getTime() const{
    return (double)(this->endTime - this->startTime);
}

// 重置评估器
void algorithm::Evaluate::reset(){
    this->compCount = 0;
    this->moveCount = 0;
    this->startTime = 0;
    this->endTime = 0;
}




