//
// Created by TianHongZXY on 2020/4/14.
//
#include <cstddef>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    constexpr unsigned sz = 33;
    int *parr[sz]; // 含有sz个整型指针的数组
    int arr[10] = {}; // 全部初始化为0
//    int &refs[10]; // 错误：不存在含引用的数组
    int (*Parray)[10] = &arr; // 从内往外理解，Parray是一个指针，指向一个包含10个元素的数组，元素类型为int
    int (&arrRef)[10] = arr; // 从内往外理解，arrRef是一个引用，引用一个包含10个元素的数组，元素类型为int
    int *(&arry)[sz] = parr; // arry是一个引用，引用一个包含10个元素的数组，元素类型是指向int的指针
    for(size_t i = 0; i < sizeof(arr)/ sizeof(arr[0]); i++) // size_t是一种机器相关的无符号类型，大得足以表示内存中任意对象的大小
        cout << arr[i] << " "; cout << endl;
    auto ia2(arr); // ia2是一个整型指针，指向arr第一个元素，等同于 auto ia2(&arr[0])
    *(++ia2) = 99;
    for(auto i : arr) cout << i << " "; cout << endl;
    decltype(arr) ia3; // 不同于上面的auto，decltype(arr)返回的类型就是由10个整数构成的数组
    for(auto i : ia3) cout << i << " "; cout << endl;

    int *e = &arr[10]; // e为尾后指针，不指向具体元素也不可做解引用或递增操作，不推荐这样取尾后指针，推荐下面的方法
    for(int *b = arr; b != e; b++) cout << *b << " "; cout << endl;

    int *beg = begin(arr); // 标准库函数，beg为指向arr首元素的指针
    int *last = end(arr); // 指向arr尾元素的下一位置的指针
    auto n = last - beg; // n为10，也即arr中元素的数量
    int *p = &arr[3];
    int k = p[-2]; // p[-2]是arr[1]表示的元素
    cout << k << " " << arr[1] << endl;

    // C风格字符串，以及与string的互相转换
    char ca[] = {'C', '+', '+'};
//    cout << strlen(ca) << endl; // 错误，ca没有以空字符结束，不过好像编译运行也没错？
    char ca1[] = "i love", ca2[] = "cj";
    string s1 = "i love", s2 = "cj";
    char largeStr[100];
    strcpy(largeStr, ca1); strcat(largeStr, " "); strcat(largeStr, ca2);
    string largestring = s1 + " " + s2;
    cout << largeStr << " " << largestring << endl;
    const char *str1 = s1.c_str(); // 返回一个指向以空字符结束的字符数组的指针，但如果后续改变了s1，str1可能失效，如果需要str1最好重新拷贝一份
    cout << str1 << endl;
    cout << s1 + str1 << endl; // string加法允许和以空字符结束的字符数组作为一个运算对象(不能两个都是)
    string s3(ca1); // 允许使用以空字符结束的字符数组来初始化string
    // 上面几个string和char[]的性质反过来就不成立了

    // 使用数组初始化vector对象
    int int_arr[] = {1,2,3,4,5,6};
    vector<int> ivec1(begin(int_arr), end(int_arr)); // 两个指针指明了用来初始化的值在数组中的位置
    vector<int> subvec1(int_arr + 1, int_arr + 4);
    // 应尽量使用标准库类型，多用vector和迭代器，少用内置数组和指针，多用sring，少用C风格字符数组

}
