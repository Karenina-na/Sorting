//
// Created by Karenina-na on 2023/9/28.
//

#include<vector>
#include<chrono>
#include<iostream>
#include <fstream>
#include<filesystem>

#ifndef SORTING_ALGORITHM_INTERFACE_FRAMEWORK_REPORTSTRUCT_H
#define SORTING_ALGORITHM_INTERFACE_FRAMEWORK_REPORTSTRUCT_H
namespace structure{
    // 报告
    template<typename T>
    class Report {
    public:
        Report();

        bool save(std::string path);
        void set_message(std::string algorithm_name, int data_size, std::string file_name, std::string file_path);
        void set_distribution(std::string data_distribution, std::vector<std::string> data_distribution_param_name,
                              std::vector<double> data_distribution_param);
        void set_evaluation(long long comp_count, long long move_count, double time);
        void set_result(std::vector<T>* result);
    private:
        // 记录日期
        std::time_t date;
        // 算法名称
        std::string algorithm_name;
        // 数据规模
        int data_size;
        // 数据分布
        std::string data_distribution;
        // 数据分布参数
        std::vector<double> data_distribution_param;
        // 数据分布参数名称
        std::vector<std::string> data_distribution_param_name;
        // 比较次数
        long long comp_count;
        // 移动次数
        long long move_count;
        // 消耗时间
        double time;
        // 文件名称
        std::string file_name;
        // 文件路径
        std::string file_path;
        // 排序结果
        std::vector<T>* result;
    };

}

// 报告
template<typename T>
structure::Report<T>::Report() {
    date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

// 保存结果与报告
template<typename T>
bool structure::Report<T>::save(std::string path) {
    // 保存结果

    std::ofstream out(std::filesystem::path(path + "/" + file_name + ".txt"));
    if (!out.is_open()){
        return false;
    }
    for (int i = 0; i < result->size(); i++) {
        out<<(*result)[i]<<", ";
    }
    out.close();

    // 保存报告
    std::string report = "";
    report += "======= data =======\n";
    report += "file name: " + file_name + "\n";
    report += "file path: " + file_path + "\n";
    report += "date: " + std::string(std::ctime(&date)) + "\n";
    report += "algorithm: " + algorithm_name + "\n";
    report += "data size: " + std::to_string(data_size) + "\n";
    report += "data distribution: " + data_distribution + "\n";
    for (int i = 0; i < data_distribution_param.size(); i++) {
        report += data_distribution_param_name[i] + ": " + std::to_string(data_distribution_param[i]) + "\n";
    }
    report += "\n";
    report += "======= evaluation =======\n";
    report += "comp count: " + std::to_string(comp_count) + "\n";
    report += "move count: " + std::to_string(move_count) + "\n";
    report += "time: " + std::to_string(time) + "\n";
    report += "\n";

    std::ofstream out2(std::filesystem::path(path + "/" + file_name + "_report.txt"));
    if (!out2.is_open()){
        return false;
    }
    out2<<report;
    out2.close();

    return true;
}

// 设置报告信息
template<typename T>
void structure::Report<T>::set_message(std::string algorithm_name, int data_size, std::string file_name, std::string file_path) {
    this->algorithm_name = algorithm_name;
    this->data_size = data_size;
    this->file_name = file_name;
    this->file_path = file_path;
}

// 设置数据分布
template<typename T>
void structure::Report<T>::set_distribution(std::string data_distribution, std::vector<std::string> data_distribution_param_name,
                                            std::vector<double> data_distribution_param) {
    this->data_distribution = data_distribution;
    this->data_distribution_param_name = data_distribution_param_name;
    this->data_distribution_param = data_distribution_param;
}

// 设置评估
template<typename T>
void structure::Report<T>::set_evaluation(long long comp_count, long long move_count, double time) {
    this->comp_count = comp_count;
    this->move_count = move_count;
    this->time = time;
}

// 设置结果
template<typename T>
void structure::Report<T>::set_result(std::vector<T>* result) {
    this->result = result;
}

#endif //SORTING_ALGORITHM_INTERFACE_FRAMEWORK_REPORTSTRUCT_H
