void back2front(){
    // d[i][j]代表从i,i+1,...,n中选物品，当前容量为j情况下的最大重量
    for(int i = n; i >= 1; i--)
        // 首先要d[n+1]全等于0
        for(int j = 0; j <= C; j++){
            d[i][j] = d[i+1][j];
            if(j >= V[i]) d[i][j] = max(d[i][j], d[i+1][j-V[i]]+ W[i]);
        }
    // 解是d[1][C]
}

void front2back(){
    for(int i = 1; i <= n; i++)
        // 首先要f[0]都为0
        for(int j = 0; j <= C; j++){
            f[i][j] = f[i-1][j];
            if(j >= V[i]) f[i][j] = max(f[i][j], f[i-1][j-V[i]] + W[i]);
        }
    // 解是f[n][C]
}

void onedim(){
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= n; i++){ // i从小到大
        scanf("%d%d", &V, &W);
        for(int j = C; j >= 0; j--){ // 原本f[j] = f[i-1][j]，但每次i都会覆盖，所以用一维数组就行
            if(j >= V) f[j] = max(f[j], f[j-V] + W); // 新f[j] = f[i][j] = max(f[i-1][j], f[i-1][j-V] + W)
        }
    }
    // 解是f[C] 即上面的f[n][C]
}