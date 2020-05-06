#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    int n;
    vector<char> country;
    for(int i = 0; i < 26; i++){
        country.push_back('A'+i);
        country.push_back('a'+i);
    }
    int cnt = 0;
    while(scanf("%d", &n) == 1 && n){
        if(cnt != 0){ printf("\n"); cnt++; }
        printf("2 %d %d\n", n, n);
        for(int i = 0; i < n; i++){
            string line(n, country[i]);
            cout << line << endl;
        }
        cout << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout << country[j];
            cout << endl;
        }
    }
    return 0;
}