//
// Created by TianHongZXY on 2020/3/25.
//
#include <iostream>
using namespace std;
template<typename T>
struct Point{
    T x, y;
    Point(T x=0, T y=0):x(x), y(y){}
//    Point(int x=0, int y=0) {this->x = x; this->y = y;} //与上一行等效
};

template<typename T>
Point<T> operator + (const Point<T>& A, const Point<T>& B){
    return Point<T>(A.x+B.x, A.y+B.y);
}

template<typename T>
ostream& operator << (ostream &out, const Point<T>& p){
    out << "(" << p.x << "," << p.y << ")";
    return out;
}
template<typename T>
T sum(T* begin, T* end){
    T ans = 0;
    for(T *p = begin; p != end; p++)
        ans = ans + *p;
    return ans;
}

int main(){
    Point<int> p1, p2(1, 1);
    p1.x = 99;
    cout << p1 + p2 << endl;
    double a[] = {1.1, 2.2, 3.3, 4.4};
    cout << sum(a, a+4) << endl;
    Point<int> b[] = {Point<int>(1, 2), Point<int>(3, 4), Point<int>(5, 6), Point<int>(7, 8)};
    cout << sum(b, b+4) <<endl;
    Point<double> c(1.1, 2.2);
    Point<double> d(3.3, 4.4);
    cout << c + d << endl;

    return 0;
}