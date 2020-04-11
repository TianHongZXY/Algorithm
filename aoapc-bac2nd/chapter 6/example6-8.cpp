//
// Created by TianHongZXY on 2020/4/10.
//
#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

const int maxv = 10000;
int in_order[maxv], post_order[maxv], lch[maxv], rch[maxv];
int n;

bool read_list(int* a){
    string line;
    if(!getline(cin, line)) return false;
    stringstream ss(line);
    n = 0;
    int x;
    while(ss >> x) a[n++] = x;
    return n > 0;
}

int build(int L1, int R1, int L2, int R2){
    // 0代表上一个根节点的子树为NULL
    if(L1 > R1) return 0;
    // 后序遍历的最后一个是根节点
    int root = post_order[R2];
    int p = L1;
    while(in_order[p] != root) p++; // 找到中序遍历的根节点所在，其左边都为根的左子树，右边为右子树
    int cnt = p - L1; // 左子树的元素个数
    lch[root] = build(L1, p - 1, L2, L2 + cnt - 1); // 根据左子树的中/后序遍历，重建根节点的左子树，返回其左子树根节点
    rch[root] = build(p+1, R1, L2+cnt, R2-1); // 根据右子树的中/后序遍历，重建根节点的右子树，返回其右子树根节点
    return root;
}

int best, best_sum;
void dfs(int u, int sum){
    sum += u;
    if(lch[u] == 0 && rch[u] == 0)
        if(sum < best_sum || (sum == best_sum && u < best)) {best = u; best_sum = sum;}
    if(lch[u]) dfs(lch[u], sum);
    if(rch[u]) dfs(rch[u], sum);


}
int main(){
    while(read_list(in_order)){
        read_list(post_order);
        build(0, n - 1, 0, n-1);
        best_sum = 10000 * 10000;
        best = 10000;
        dfs(post_order[n-1], 0);
        printf("%d\n", best);
    }

    return 0;
}