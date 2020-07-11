// 原博客链接 https://blog.csdn.net/yandaoqiusheng/article/details/84782655
#include <iostream>
using namespace std;
const int maxn = 1e3;
int w[maxn], v[maxn], f[maxn], p[maxn];
int N, V;

void version1(){
// 方法一：直接把第i种物品转换成p[i]件一样的物品，用01背包解
    for(int i = 1; i <= N; i++)
        for(int k = 1; k <= p[i]; k++)
            for(int j = V; j >= w[i]; j--)
                f[j] = max(f[j], f[j - w[i]] + v[i]);
}

void version2(){
    /*将第i种物品分成若干件物品，其中每件物品有一个系数，这件物品的费用和价值均是原来的费用和价值乘以这个系数。
    使这些系数分别为1,2,4,...,2^(k−1),p[i]−2^k+1，且k是满足 p[i]−2^k+1 > 0的最大整数。
    例如，如果p[i]为13，就将这种物品分成系数分别为1,2,4,6的四件物品。分成的这几件物品的系数和为p[i]，
    表明不可能取多于p[i]件的第i种物品。另外这种方法也能保证对于0...p[i]间的每一个整数，均可以用若干个系数的和表示，
    这个证明可以分0...2^(k−1)和2^k...p[i]两段来分别讨论得出：因为p[i]-2^k+1的前面是2的等比数列，和为2^k-1，
    所以0~2^k-1的数都可以通过从里面选若干个数得到，而它们加上p[i]-2^k+1 = p[i]，
    从里面任意拿掉前面等比数列的若干数就能得到p[i],p[i]-1,p[i]-2,...,p[i]-2^k+1，
    而因为k是使得p[i]+1 > 2^k成立，那么p[i]+1 < 2^(k+1) = 2^k + 2^k一定成立，
    所以p[i]-2^k+1<2^k，所以上面这段数覆盖了[2^k,p[i]]这个区间，得证。
    这样就将第i种物品分成了O(log(p[i]))种物品，将原问题转化为了复杂度为O(V*Σlog(p[i]))的01背包问题，是很大的改进。
    */
    for (int i = 1; i <= N; i++) {
        int num = min(p[i], V / w[i]); // V/w[i]是背包总容量最多能放几个，p[i]是能选几个，二者取小
        for (int k = 1; num > 0; k = k << 1) {
            if (k > num) k = num;
            num -= k;
            for (int j = V; j >= w[i] * k; j--)
                f[j] = max(f[j], f[j - w[i] * k] + v[i] * k);
        }
    }
}