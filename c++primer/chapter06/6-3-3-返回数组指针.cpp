#include <cstdio>
typedef int arrT[10]; // arrT是一个类型别名，类型是含10个整型的数组
using arrT = int[10]; // 等价上面
arrT* func(){// func返回一个指向有10个整形的数组的指针
    static arrT s;
    for(int i = 0; i < 10; i++) s[i] = i;
    return &s;
}

int (*func2(int i))[10]; // 返回类型是一个数组指针，指向一个有10个整型的数组，维度前必须有括号，不然返回的类型是指针数组

int main(int argc, char const *argv[])
{
    arrT* x = func();
    for(int i = 0; i < 10; i++){
        printf("%d ", *x[i]);
        printf("%d\n", (*x)[i]);
    }

    int arr[10];
    int *p1[10]; // p1是一个含有10个整型指针的数组
    int (*p2)[10]; // p2是一个指针，指向一个含有10个整型的数组
    return 0;
}


