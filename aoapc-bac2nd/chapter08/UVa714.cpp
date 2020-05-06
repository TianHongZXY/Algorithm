// UVa714 Copying Books
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxm = 500 + 5;
int m, k, p[maxm];

// how many scribers needed if each scriber can work on at most maxp pages
int solve(long long maxp) {
  long long done = 0;
  int ans = 1;
  for(int i = 0; i < m; i++) {
    if(done + p[i] <= maxp) done += p[i];
    else { ans++; done = p[i]; }
  }
  return ans;
}

int last[maxm]; // last[i] = 1 if i is the last book assigned to someone
void print(long long ans) {
  long long done = 0;
  memset(last, 0, sizeof(last));
  int remain = k;
  for(int i = m-1; i >= 0; i--) {
    if(done + p[i] > ans || i+1 < remain) { // 如果加上p[i]就超过了ans，就把i后面的划分到一块去
    // 或者剩下的数字不够用来划分的剩余区间个数了，就得立刻把i后面的给划分掉，
    // 比如剩余5个数字，现在还要划分6个区间，就得立刻把后面的划分掉，这样还剩5个数字，5个划分区间，再进行循环
      last[i] = 1; remain--; done = p[i];
    }
    else {
      done += p[i];
    }
  }
  for(int i = 0; i < m-1; i++) {
    printf("%d ", p[i]);
    if(last[i]) printf("/ ");
  }
  printf("%d\n", p[m-1]);
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &m, &k);
    long long tot = 0;
    int maxp = -1;
    for(int i = 0; i < m; i++) {
      scanf("%d", &p[i]);
      tot += p[i];
      maxp = max(maxp, p[i]);
    }
    long long L = maxp, R = tot;
    while(L < R) {
      long long M = L + (R-L)/2;
      if(solve(M) <= k) R = M;  // 如果符合条件，答案需要M最小
      else L = M+1; // 如果划分的序列个数大于了k，增大M
    }
    print(L);
  }
  return 0;
}
