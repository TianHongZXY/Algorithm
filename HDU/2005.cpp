#include <cstdio>

int main(){
    char s[20];
    int y, m, d, days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while(scanf("%s", s) == 1){
        int ans = 0;
        sscanf(s, "%d/%d/%d", &y, &m, &d);
        for(int i = 1; i < m; i++)
            ans += days[i];
        ans += d;
        if(m > 2)
            if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ans += 1; // 闰年，2月多一天
        printf("%d\n", ans);
    }

    return 0;
}