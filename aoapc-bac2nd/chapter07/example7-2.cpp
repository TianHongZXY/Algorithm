#include<bits/stdc++.h>
using namespace std;

int S[20];

int main(){
    int n, kase = 0;
    while(scanf("%d", &n) == 1 && n){
        long long res = -1;
        for(int i = 0; i < n; i++)
            scanf("%d", &S[i]);
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++){
                long long temp = 1;
                for(int k = i; k <=j; k++){
                    temp *= S[k];
                }
                res = max(temp, res);
            }
        if(res > 0) printf("Case #%d: The maximum product is %lld.\n\n", ++kase, res);
        else printf("Case #%d: The maximum product is 0.\n\n", ++kase);
    }

    return 0;
}