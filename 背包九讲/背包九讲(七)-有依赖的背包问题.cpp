// 原博客链接 https://blog.csdn.net/yandaoqiusheng/article/details/84782655
#include <iostream>
using namespace std;
const int maxn = 1e3;
int w[maxn], v[maxn], f[maxn];
int N, V;

void version1(){
    // i依赖于j，表示若选物品i，则必须选物品j。为了简化起见，我们先设没有某个物品既依赖于别的物品，
    // 又被别的物品所依赖；另外，没有某件物品同时依赖多件物品。
    /*
    将不依赖于别的物品的物品称为“主件”，依赖于某主件的物品称为“附件”。由这个简化条件可知所有的物品由若干主件和依赖于每个主件的一个附件集合组成。
    c[i]是主件i的费用，我们可以对主件i的“附件集合”先进行一次01背包，得到费用依次为0...V−c[i]所有这些值时相应的最大价值f′[0...V−c[i]]。
    那么这个主件及它的附件集合相当于V−c[i]+1个物品的物品组，其中费用为c[i]+k的物品的价值为f′[k]+w[i]。
    通过一次01背包后，将主件i转化为V−c[i]+1个物品的物品组，就可以直接应用分组背包的算法解决问题了。
    */
}