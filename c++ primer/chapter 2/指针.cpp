#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    int *ip1, *ip2;
    double dp, *dp2;

    int ival = 33;
    int *p = &ival;
    cout << *p << endl;

    double dval = 30;
    double *pd = &dval;
    double *pd2 = pd;
    int pi;
    // int  *pi = pd; 类型不同不允许
    // pd = &pi; 类型不同不允许

    cout << *pd << ' ' << *pd2 << ' ' << dval << endl;
    *pd = 26;
    cout << dval << endl;

    // int *p1 = nullptr;
    int *p2 = 0;
    int *p3 = NULL;

    double obj = 3.14, *pp = &obj;
    void *pv = &obj;
    pv = pp;
    // cout << *pv << endl; 无法操作void指针所指的对象

    int *pp1, pp2; // p1是指针，而p2是int

    int iival = 1024;
    int *ppi = &iival;
    int **pppi = &ppi; // 指向指针的指针，存储指针的地址
    int ***ppppi = &pppi; // 指向(指向指针的指针)的指针，存储(指向指针的指针)的地址
    cout << iival << ' ' << *ppi << ' ' << **pppi << ' ' << ***ppppi << endl;

    // 引用非对象，因此指针不可以指向引用，但指针是对象，因此可以引用指针
    int j = 33;
    int *q;
    // r是对指针的引用，从右往左读定义来理解类型
    // 首先由&确定r是引用，其次由*确定它引用的类型是指针，最后由int确定是引用一个指向int的指针
    int *&r = q; 
    r = &j;
    *r = 0;

    return 0;
}
