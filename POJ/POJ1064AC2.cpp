#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define ll long long
#define INF 0x3f3f3f3f
#define Maxn 10000+5
using namespace std;
int l,r;//左，右
int N,K;
int main()
{
    while(scanf("%d%d", &N, &K) == 2)
    {
        int len[Maxn];//绳子
        for(int i=0; i<N; i++)
        {
            double t;
            scanf("%lf", &t);
            len[i]=t*100.0;
        }
        // sort(len,len+N);//排序，直接找最大值
        l=1,r=100*1000*100;
        int ans=0;//答案
        while(l<=r)
        {
            int mid=(l+r)/2;
            int cnt=0;//计数器，是否大于等于K
            for(int i=0; i<N; i++)
                cnt+=len[i]/mid;
            if(cnt>=K)
            {
                l=mid+1;
                ans=max(ans,mid);//找最大值
            }
            else
                r=mid-1;
        }
        printf("%.2f\n",(double)ans/100.0);
    }
    return 0;
}