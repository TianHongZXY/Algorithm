// 原博客链接 https://blog.csdn.net/yandaoqiusheng/article/details/84782655
// 有N件物品和一个容量为V的背包。第i件物品的费用是w[i]，价值是v[i]，求将哪些物品装入背包可使价值总和最大。
// i = 1 ~ N
// f[i][j]表示前i件物品恰放入一个容量为j的背包可以获得的最大价值。
#include <iostream>
// #define max(x, y) (x > y ? x : y)
using namespace std;
const int maxn = 1e3;
int f[maxn][maxn], w[maxn], v[maxn], f2[maxn], s[maxn];
int N, V;

void version1(){ // 时间和空间复杂度均为O(VN)
    for(int i = 1; i <= N; i++)
        for(int j = 0; j <= V;j++){
            f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
        }
}

void version2(){ // 优化空间复杂度至O(V)
    for(int i = 1; i <= N; i++)
        for(int j = V; j >= 0; j--){
            // j从后往前，当遍历到j时，f[0]~f[j-1]等价于f[i-1][0]~f[i-1][j-1]
            // 而f[j+1]~f[V]等价于f[i][j+1]~f[i][V]，用j前面的即f[i-1]的状态来更新f[j]得到的即为f[i][j]
            f2[j] = max(f2[j], f2[j - w[i]] + v[i]);
        }
}

void version3(){
    for(int i = 1; i <= N; i++)
        for(int j = V; j >= w[i]; j--){ // j的范围从[0, V]缩小到[w[i], V]
            f2[j] = max(f2[j], f2[j - w[i]] + v[i]);
        }
}

/* 初始化的问题
我们看到的求最优解的背包问题题目中，事实上有两种不太相同的问法。有的题目要求 "恰好装满背包" 时的最优解，
有的题目则并没有要求必须把背包装满。这两种问法的区别是在初始化的时候有所不同。
如果是第一种问法，要求恰好装满背包，那么在初始化时除了f[0]为0 其它f[1...V]均设为−∞，这样就可以保证最终得到的f[V]是一种恰好装满背包的最优解。
如果并没有要求必须把背包装满，而是只希望价格尽量大，初始化时应该将f[0...V]全部设为0。
为什么呢？可以这样理解：初始化的f数组事实上就是在没有任何物品可以放入背包时的合法状态。
如果要求背包恰好装满，那么此时只有容量为0的背包可能被价值为0的nothing“恰好装满”，其它容量的背包均没有合法的解，属于未定义的状态，
它们的值就都应该是−∞了。如果背包并非必须被装满，那么任何容量的背包都有一个合法解“什么都不装”，这个解的价值为0，所以初始时状态的值也就全部为0了。
这个小技巧完全可以推广到其它类型的背包问题
*/

void version4(){ // 一个常数优化, 对V较大时适用
    for (int i = 1; i <= N; i++) cin >> w[i] >> v[i], s[i] = s[i - 1] + w[i];
    
    for (int i = 1; i <= N; i++) {
	    int bound = max(w[i], V - (s[N] - s[i]));
	    for (int j = V; j >= bound; j--)
		    f2[j] = max(f2[j], f2[j - w[i]] + v[i]);
    }
}