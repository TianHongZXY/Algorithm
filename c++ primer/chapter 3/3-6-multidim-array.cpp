//
// Created by TianHongZXY on 2020/4/14.
//
#include <iostream>
using namespace std;

int main(){
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    int (&row)[4] = ia[1]; // row定义为一个含有4个整数的数组的引用，绑定到ia的第二行
    for (auto &row : ia) {
        for (auto &col : row) {
            cout << col << " ";
        }
        cout << endl;
    }

    // 用范围for处理多维数组，除了最内层的循环外，其他所有循环的控制变量都应该是引用类型
//    for (auto row : ia)  // 不合法，row是int* 而非像上面是数组的引用
//        for (auto col : row) {
//            cout << col << " ";
//        }
    cout << "--------" << endl;
    int (*p)[4]; // p是一个指向维度为4的数组的指针
    int *p1[4]; // p1是大小为4的整型指针的数组
    p = &ia[2];
    for (auto p = ia; p != ia + 3; p++){ // p是一个指针，指向ia的第一个内层数组，依次迭代ia的三行
        for (auto q = *p; q != *p + 4; q++) // q是一个指针，指向p所在行的第一个元素，*p是一个含有4个整数的数组
            cout << *q << " ";
        cout << endl;
    }
    cout << "--------" << endl;
    for (auto p = begin(ia); p != end(ia); p++){
        for (auto q = begin(*p); q != end(*p); q++) // q是一个指针，指向p所在行的第一个元素，*p是一个含有4个整数的数组
            cout << *q << " ";
        cout << endl;
    }
}
