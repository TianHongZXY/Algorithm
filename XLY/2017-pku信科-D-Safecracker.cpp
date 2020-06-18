#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
char letters[20];
int vis[20];
int target;

int compute(string a){
    int res = 0;
    for(int i = 1; i <= 5; i++){
        res += pow(a[i - 1] - 'A' + 1, i) * pow(-1, i + 1);
    }
    return (int)res;
}

bool cmp(const int a, const int b){
    return a > b;
}

string search(int n){
    string ans = "#####";
    for(int i = 0 ; i < n; i++){
        ans[0] = letters[i];
        vis[i] = 1;
        for(int j = 0; j < n; j++){
            if(vis[j]) continue;
            ans[1] = letters[j];
            vis[j] = 1;
            for(int k = 0; k < n; k++){
                if(vis[k]) continue;
                ans[2] = letters[k];
                vis[k] = 1;
                for(int l = 0; l < n; l++){
                    if(vis[l]) continue;
                    ans[3] = letters[l];
                    vis[l] = 1;
                    for(int m = 0; m < n; m++){
                        if(vis[m]) continue;
                        ans[4] = letters[m];
                        vis[m] = 1;
                        if(compute(ans) == target){
                            return ans;
                        }
                        vis[m] = 0;
                    }
                    vis[l] = 0;
                }
                vis[k] = 0;
            }
            vis[j] = 0;
        }
        vis[i] = 0;
    }
    return "";
}

int main(){
    while(scanf("%d", &target) == 1 && target){
        scanf("%s", letters);
        int n = strlen(letters);
        sort(letters, letters + n, cmp); // 要最大字典序输出，逆序排序
        string result = search(n);
        if(result == ""){
            printf("no solution\n");
        }
        else{
            cout << result << endl;
        }
        memset(vis, 0, sizeof(vis));
        memset(letters, 0, sizeof(letters));
    }
    return 0;
}