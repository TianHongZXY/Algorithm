//
// Created by TianHongZXY on 2020/2/27.
//
#ifndef CPLUSPLUS_STUDY_SALES_DATA_H
#define CPLUSPLUS_STUDY_SALES_DATA_H
#include <string>
struct Sales_data{
    // Headers Should Not Include "using" Declarations!
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif //CPLUSPLUS_STUDY_SALES_DATA_H

