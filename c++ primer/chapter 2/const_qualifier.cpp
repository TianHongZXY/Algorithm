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

    return 0;
}
