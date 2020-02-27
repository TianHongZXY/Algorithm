//
// Created by TianHongZXY on 2020/2/27.
//
#include <iostream>
using namespace std;
typedef double wages; // wages is a synonym for double
typedef wages base, *p; // base is a synonym for double, p for double*
using SI = int; // SI is a synonym for int

int main(){
    p x;
    wages y = 3.14;
    x = &y;
    SI i = 10;

    typedef char *pstring; // pstring == char*, type(pstring) == pointer
    const pstring cstr = 0; // cstr is a const pointer to char, const is top-level
    const pstring *ps; // ps is a pointer, it points to a const pointer to char
    // const char *ccstr doesn't equals to const pstring ccstr
    const char *ccstr = 0; // this is a pointer to const char , not a const pointer to char!!!

    auto i1 = 0, *p1 = &i1; // int and int *
    auto i2 = y + i1;
    auto *p2 = &i2;

    double &r1 = y;
    auto i3 = r1; // i3 is a double, its value == y == 3.14

    // auto ignores top-level, but keeps low-level const
    const int ci = i1, &cr = ci;
    auto b = ci; // b is an int, ci's top-level const is ignored
    auto c = cr; // c is an int
    auto d = &i1; // d is a pointer to int
    auto e = &ci; // e is a pointer to const int
    // if we want the deduced type to have a top-level const, we must say so explicitly
    const auto f = ci;
    auto &g = ci;
    // reference to an auto-deduced type, top-level consts in the initializer are not ignored
//    g = 10; // error, g is const int&
//    auto &h = 42; error
    const auto &j = 42; // ok

    decltype(ci) i4 = 99;

}
