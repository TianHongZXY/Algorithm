#include <iostream>

using namespace std;

int reused = 33;

int main(int argc, char const *argv[])
{
    // 在C语言里，0开头的数被解释为8进制，9大于了8，所以不被允许
    // int month = 09, day = 07;
    int month = 9, day = 7;
    cout << month << endl;
    string book("C++ primer");
    cout << book << endl;

    long double ld = 3.1415926536;
    // 不可用列表初始化来做存在丢失信息风险的初始化，但实际下行可以运行
    // int a{ld}, b = {ld};
    int c(ld), d = ld;
    cout << c << ' ' << d << endl;

    // 任何函数体内部都不可以初始化 extern 标记的变量
    extern int i;
    int j;

    cout << reused << endl;
    int reused = 0;
    cout << reused << endl;
    // 显式地访问全局变量
    cout << ::reused << endl;

    
    return 0;
}