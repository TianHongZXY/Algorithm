#include <cstdio>

void print(int (&arr)[10]){ // arr是一个具有10个整数的整数数组的引用
    for(int elem : arr){
        printf("%d", elem);
    }
}
//void print(int &arr[10]); // 错误，arr是一个存储“整数的引用”的数组，但引用不能成为数组的元素
void print(int (*matrix)[10], int rowSize); // matrix是一个数组指针，指向的数组的元素是一个含10个整数的数组
void print(int matrix[][10], int rowSize); // 等价于上一行
void print(int *matrix[10], int rowSize); // matrix是一个存储“整数的指针”的数组，传递多维数组只有第一维的维度可以省略，后面的都不可省

int main(int argc, char *argv[]){ // argv是一个数组，其元素是指向C风格字符串的指针，第二个形参argc表示数组中字符串的数量
    // argv[0]保存程序的名字而非用户输入，可选的实参从argv[1]开始，最后一个元素保证为0或NULL，
    // 即传入x个参数，argc = x + 1，因此从argv[1]~argv[argc - 1]是传入的参数，argv[0]是程序名，argv[argc]是0
    for(int i = 0; i <= argc; i++)
        printf("%dth param : %s\n", i, argv[i]);
    return 0;
}