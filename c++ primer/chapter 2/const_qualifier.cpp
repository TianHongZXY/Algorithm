#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    const int bufSize = 512;
    // bufSize = 512; // bufSize is read-only
    // const int k;  // must be initialized

    // const can be used to initialize other const or non-const
    const int j = bufSize;
    int l = bufSize;
    l = 42;
    const int m = l;

    const int ci = 1024;
    const int &ri = ci;

    // ri = 42; // reference to const can't change the obj it is bound
    // int &r2 = ci; // non-const reference to a const obj is illegal

    int i = 33;
    const int &r1 = i; // we can bind a const int& to a plain int obj
    const int &r2 = 42; // r2 is reference to const
    const int &r3 = r1 * 2; // r3 is reference to a const and has nothing to do with r1 or i anymore
    const int &r4 = r1; // r4 is reference to i
    // int &r4 = r1 * 2; // error: r4 is a non-const reference
    cout << r1 << ' ' << r3 << ' ' << r4 << endl;
    i = 42;
    cout << r1 << ' ' << r3 << ' ' << r4 << endl;
    // r1 = 50; // const reference can't change the value of obj it references to

    double dval = 3.14;
    const int &rd = dval;
    // int &rd = dval; // not allowed if rd isn't const and reference to a different type.
    cout << rd << endl;
    // rd = 4; // rd is bound to a temporary obj,

    int k = 33;
    int &rk = k;
    const int &rkk = k;
    rk = 55;
//    rkk = 66; // not allowed reference to const can refer to non-const, but can't change it

//  Pointer to const
    const double pi = 3.14;
//    double *ptr = &pi; // error, pointer must be const too
    const double *cptr = &pi;
//    *cptr = 9.99 // error, can't assign to *cptr

    cptr = &dval; // const pointer can point to non-const obj

//  const Pointer
    int errNumb = 0;
    int *const curErr = &errNumb; // curErr will always point to errNumb
    const double PI = 3.14159;
    const double *const pip = &PI; // pip is a const pointer to a const obj

//    *pip = 3.0 // error, pip points to a const obj
    if (*curErr){
//      const pointer can change the value of obj it points to if the obj itself is non-const
//      no matter whether the pointer is const or not
        *curErr = 10;
    }

//    when copy an obj, top-level consts are ignored
//    copy an obj doesn't change the copied obj
    int q = 0;
    const int r = 10;
    q = r; // q copy r's value, r's top-level const is ignored
    cout << q << endl;
    q = 9; // q is still plain int

    const int *p1 = &q;
    const int *const p2 = &r;
    p1 = p2; // p2 is a const pointer, p1 copies p2's value, e.g. r's address
    p1 = &q; // p1 is still a plain pointer

    return 0;
}
