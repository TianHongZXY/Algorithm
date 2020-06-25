#include <cstdio>
typedef int T;
void f(T);
void g(T&); // 说明函数的参数类型是T的引用
// void h(&T); 在函数定义和声明的时候这种写法不符合语法。只有在函数调用的时候才可以 
// 例如:f(&T); 此时函数的声明应该是void f(T*)，参数类型是T的指针
size_t count_calls(){
    static size_t ctr = 0;
    return ++ctr;
}

int main(){
    for(size_t i = 0; i != 10; i++)
        printf("%zu\n", count_calls());
}