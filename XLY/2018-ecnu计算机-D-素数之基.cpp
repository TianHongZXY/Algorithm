// 不会写，可能要用数论，也没找到解法

#include <cstdio>
#include <vector>
#include <cmath>
#include <numeric>
#include <set>
using namespace std;
const int maxn = 1e6 + 10;
vector<int> prime[maxn];
int vis[maxn];
int n;

bool isprime(int x){
    if(x == 2) return true;
    for(int i = 2; i <= ceil(sqrt(x)); i++)
        if(x % i == 0) return false;
    return true;
}

void init(){
    for(int i = 2; i <= n; i++){
        if(isprime(i))
            for(int j = i; j <= n; j++)
                prime[j].push_back(i);
    }
}

int main(){
    scanf("%d", &n);
    init();
    vector<int> min_basis = prime[n];
    set<int> res;
    set<int> curr;
    int num = min_basis.size();

    for(int i = 0; i < num; i++){
        int cur = min_basis[i];
        if(curr.count(cur)) continue; // 如果通过组合res里的数已经能组成该数，跳过

        for(int j = 1; j <= cur; j++){
            if(j == cur){ // 如果到最后都没找到能组合成它的数，就把它单独加入答案中，并使用它和res其他所有数组成和加入curr
                for(int x : res){
                    curr.insert(cur + x);
                }
                res.insert(cur);
                curr.insert(cur);
                break;
            }

            int found = 0;
            for(int x : curr){ // 尝试从curr中寻找小于cur的数，与j组成和来等于cur
                if(j + x == cur){
                    if(res.count(j)) continue; // curr里不包含cur，则已经确定了不能通过组合res里的数来求得cur，如果j在res里则说明发生了数字重复使用
                    else{
                        for(int x : res){
                            curr.insert(j + x);
                        }
                        res.insert(j);
                        curr.insert(j);
                        found = 1; break;
                    } 
                }
            }
            if(found) break;
        }
        
    }
    printf("%d\n", (int)res.size());
    for(int x : res)
        printf("%d ", x);
    return 0;
}