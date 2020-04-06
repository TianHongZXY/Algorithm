//
// Created by TianHongZXY on 2020/3/31.
//

#include<iostream>
#include<algorithm>
#include <vector>

using namespace std;

static bool myfunc(int i, int j)
{
    return (i + 1) == j;
    //return i == j;
}

int main()
{

    vector<int> a = {1,3,3,4,5,6,6,7};
    vector<int>::iterator it_1 = a.begin();
    vector<int>::iterator it_2 = a.end();

    //sort(it_1,it_2);
    cout << "去重前的 a : ";
    for(int i = 0 ; i < a.size(); i++)
        cout << a[i];
    cout << endl;
    //it_h = unique(it_1,it_2);
    //unique(it_1,it_2,myfunc);
    int x = unique(it_1,it_2) - it_1;
    cout << "去重后的 a : ";
    for(int i = 0 ; i < a.size(); i++)
        cout << a[i];
    cout << endl;
}