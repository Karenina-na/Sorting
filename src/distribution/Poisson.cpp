//
// Created by Karenina-na on 2023/9/21.
//
#include "DisInclude.h"

// 生成随机数
template<typename T>
std::vector<T>* distribution::Poisson<T>::generate() {

    // 不合法
    if (size <= 0 || min > max){
        return new std::vector<T>();
    }

    // 概率
    std::vector<double> prob;
    double sum = 0;
    for (int i = 0; i < max - min + 1; i++){
        prob.push_back(pdf(i, lambda));
        sum += prob[i];
    }
    // 归一化
    for (int i = 0; i < max - min + 1; i++){
        prob[i] /= sum;
    }

    // 生成随机数
    auto* arr = new std::vector<T>();
    std::default_random_engine e(seed);   //  随机数引擎
    std::discrete_distribution<int> d(prob.begin(), prob.end());    // 离散分布
    for (int i = 0; i < size; i++){
        arr->push_back(d(e) + min);
    }

    return arr;
}

// 概率密度函数
template<typename T>
double distribution::Poisson<T>::pdf(T x, double lambda){
    // (lambda^x / x!) * exp(-1 * lambda)
    double result = 1;
    for (int i = 1; i <= x; i++){
        result *= lambda / i;
    }
    result *= exp(-1 * lambda);
    return result;
}