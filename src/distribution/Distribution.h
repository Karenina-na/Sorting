//
// Created by Karenina-na on 2023/9/21.
//

#ifndef SORTING_ALGORITHM_INTERFACE_FRAMEWORK_DISTRIBUTION_H
#define SORTING_ALGORITHM_INTERFACE_FRAMEWORK_DISTRIBUTION_H

#include <vector>
#include <random>
#include <cmath>

namespace distribution{
    // 均匀分布
    template<typename T>
    class Uniform{
    public:
        Uniform(int size, T min, T max, unsigned seed = 0) : size(size), min(min), max(max), seed(seed) {}
        std::vector<T>* generate();
    private:
        int size;
        T min;
        T max;
        unsigned seed;
        // 概率密度函数
        double pdf(double x, T min, T max);
    };

    // 高斯分布
    template<typename T>
    class Gaussian{
    public:
        Gaussian(int size, T min, T max, double mean, double stddev, unsigned seed = 0)
        : size(size), min(min), max(max), mean(mean), stddev(stddev), seed(seed) {}
        std::vector<T>* generate();
    private:
        int size;
        T min;
        T max;
        unsigned seed;
        double mean;
        double stddev;
        // 概率密度函数
        double pdf(T x, double mean, double stddev);
    };

    // 泊松分布
    template<typename T>
    class Poisson{
    public:
        Poisson(int size, T min, T max, double lambda, unsigned seed = 0)
        : size(size), min(min), max(max), lambda(lambda), seed(seed) {}
        std::vector<T>* generate();
    private:
        int size;
        T min;
        T max;
        unsigned seed;
        double lambda;
        // 概率密度函数
        double pdf(T x, double lambda);
    };

    // 指数分布
    template<typename T>
    class Exponential{
    public:
        Exponential(int size, T min, T max, double lambda, unsigned seed = 0)
        : size(size), min(min), max(max), lambda(lambda), seed(seed) {}
        std::vector<T>* generate();
    private:
        int size;
        T min;
        T max;
        unsigned seed;
        double lambda;
        // 概率密度函数
        double pdf(T x, double lambda);
    };
}

#endif //SORTING_ALGORITHM_INTERFACE_FRAMEWORK_DISTRIBUTION_H