//
// Created by TianHongZXY on 2020/2/27.
//
#include <iostream>
#include "Sales_data.h"
using namespace std;


int main(){
    Sales_data data1, data2;
    double price1, price2;
    cin >> data1.bookNo >> data1.units_sold >> price1;
    data1.revenue = data1.units_sold * price1;
    cin >> data2.bookNo >> data2.units_sold >> price2;
    data2.revenue = data2.units_sold * price2;

    if (data1.bookNo == data2.bookNo){
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;

        cout << data1.bookNo << ' ' << totalCnt << ' '
        << totalRevenue << endl;
        if (totalCnt != 0)
            cout << totalRevenue / totalCnt << endl;
        else
            cout << "(no sales)" << endl;
    }
    else{
        cerr << "Data must refer to the same ISBN" << endl;
        return -1;
    }
    return 0;
}