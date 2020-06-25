#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int ival = 1024;
    int &refVal = ival;
    // int &refVal2 = 2; 引用不可初始化为字面值
    refVal = 2;
    cout << ival << endl;

    double dval = 3.1415;
    // int &refVal5 = dval; 引用不可绑定不同类型的对象

    return 0;
}

