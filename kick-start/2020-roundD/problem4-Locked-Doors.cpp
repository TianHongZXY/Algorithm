// test set2 超出内存了
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1e5 + 2;
int D[maxn];
int T, N, Q, S, K, ans;

struct state{
    int biggestK = 0;
    vector<int> cur;
    vector<int> left;
    vector<int> right;
}Status[maxn];


int solve(int s, int k){
    if(Status[s].biggestK >= k) return Status[s].cur[k - 1];
    int left = 0, right = maxn; // 左边和右边的第一个房门序号
    if(s > 1) left = s - 1;
    if(s < N) right = s;
    int vis = 1, cur = s;
    if(vis > Status[s].biggestK){
        Status[s].biggestK = vis;
        Status[s].cur.push_back(cur);
        Status[s].left.push_back(left);
        Status[s].right.push_back(right);
    }
    while(vis != k){
        if(left == 0){
            cur = right + 1; right++;
        }
        else if(right > N - 1){
            cur = left; left--;
        }
        else{
            if(D[left] < D[right]){
                cur = left; left--;
            }
            else{
                cur = right + 1; right++;
            }
        }
        vis++;
        if(vis > Status[s].biggestK){
            Status[s].biggestK = vis;
            Status[s].cur.push_back(cur);
            Status[s].left.push_back(left);
            Status[s].right.push_back(right);
        }
    }
    return cur;
}

int main(){
    scanf("%d", &T);
    for(int c = 1; c <= T; c++){
        printf("Case #%d:", c);
        scanf("%d%d", &N, &Q);
        for(int i = 1; i <= N-1; i++)
            scanf("%d", &D[i]);
        for(int i = 1; i <= Q; i++){
            scanf("%d%d", &S, &K);
            ans = solve(S, K);
            printf(" %d", ans);
        }
        printf("\n");
        for(int i = 0; i < 1e5; i++)
            if(Status[i].biggestK){
                Status[i].biggestK = 0;
                Status[i].cur.clear(); Status[i].cur.shrink_to_fit();
                Status[i].left.clear(); Status[i].left.shrink_to_fit();
                Status[i].right.clear(); Status[i].right.shrink_to_fit();
            }
    }
    return 0;
}