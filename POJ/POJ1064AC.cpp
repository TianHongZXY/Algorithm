#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#define lson l m rt << 1
#define rson m+1 r rt << 1|1
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6+10;
const int mod = 1000;
double a[maxn];
ll T,n,k;
inline void fast()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
 
bool check(double m)
{
    int sum = 0;
    for(int i = 0;i < n;i++)
    {
        sum = sum + (int)(a[i]/m); //可以分出来几个x长的线段
    }
    return sum >= k;
}
 
int main()
{
    fast();
    while(scanf("%lld %lld",&n,&k) != EOF) //二分好像用cin总是超时，也可能是我写的比较丑
    {
        for(int i = 0;i < n;i++)
            scanf("%lf",&a[i]);
 
        sort(a,a+n);
 
        double l = 0,r = INF,mid;
        for(int i = 0;i < 100;i++) //二分的边界问题，对于小数而言eps过大过小都不合适，所以直接强制次数100次的循环可以让精度控制在10-30次方
        {
            mid = (l + r)/2;
            if(check(mid))
                l = mid;
            else
                r = mid;
        }
        printf("%.2f\n",floor(l*100)/100);
    }
	return 0;
}