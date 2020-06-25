#include <cstdio>
#include <iostream>
using namespace std;
void fcn(const int i){
    // 可以读取i的值，但不可改变i的值
    return;
}
// void fcn(int i){ // 错误，重复定义了fcn
//     return;
// }
int main(){
    const int ci = 42; // const是顶层的，无法修改ci的值
    int i = ci; // 拷贝ci的值到i中，忽略ci的顶层const
    int * const p = &i; // const是顶层的，无法修改p所指向的东西，即无法修改p存储的地址
    *p = 0; // 可以，是修改了p所指向的东西的值，现在i等于0
    fcn(ci); fcn(i); // 实参初始化形参时会忽略顶层const，当形参有顶层const时，传给他常量对象或非常量对象都可以
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[100];
    for(int i = 0; i < 9; i++) b[i] = i + 1;
    int *beg = begin(a);
    int *last = end(a);
    beg = begin(b);
    last = end(b);
    printf("%d", a[8]);
    return 0;
}