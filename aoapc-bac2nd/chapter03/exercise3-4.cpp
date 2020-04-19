//
// Created by TianHongZXY on 2020/3/17.
//

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int t; cin >> t;
    char s[85];
    while (t--)
    {
        memset(s, 0, sizeof(s));
        scanf("%s", s);
        int len = strlen(s);
        int j;
        for (int i = 1; i <= len; ++i)
            if (len%i == 0)
            {
                for (j = i; j <= len; j++)
                    if (s[j] != s[j%i])
                        break;
                if (j == len)
                {
                    cout << i << endl;
                    break;
                }
            }
        if (t)cout << endl;
    }
}