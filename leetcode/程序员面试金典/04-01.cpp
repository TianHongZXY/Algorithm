#include <vector>
#include <unordered_set>
#include <queue>
#include <cstring>
using namespace std;

class Solution {
public:
bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
    vis = vector<bool>(n, false);
    neigh = vector<unordered_set<int>>(n);
    for(const auto& x : graph){
        neigh[x[0]].insert(x[1]);
    }
    if(neigh[start].count(target)) return true;
    queue<int> Q{{start}};
    // Q.push(start);
    while(!Q.empty()){
        int fr = Q.front(); Q.pop();
        if(fr == target) return true;
        else if(vis[fr]) continue;
        else{
            vis[fr] = true;
            for(const int &a : neigh[fr])
                if(!vis[a]) Q.push(a);
        }
    }
    return false;
}
private:
    vector<unordered_set<int>> neigh;
    vector<bool> vis;
};