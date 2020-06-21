#include <cstdio>
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isrunnian(int y){
    return (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0));
}

void print_frist_line(int& xingqiji, int& day){
    if(xingqiji == 7){
        printf("% 3d", xingqiji);
        xingqiji = 1;
        day++;
    }
    else printf("   ");
    for(int i = 1; i <= 6; i++){
        if(xingqiji != i)
            printf("    ");
        else break;
    }
    for(; xingqiji != 7; day++){
        switch (xingqiji)
        {
        case 6:
            printf("%4d", day);
            printf("\n");
            xingqiji++;
            break;
        default:
            printf("%4d", day);
            xingqiji++;
            break;
        }
    }
}

int main(){
    int y, m;
    scanf("%d%d", &y, &m);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    int d = 0;
    for(int i = 1900; i < y; i++){
        if(isrunnian(i)) d += 366;
        else d += 365;
    }
    for(int i = 1; i < m; i++){
        if(i == 2 && isrunnian(y)) d += 29;
        else d += month[i];
    }
    d = d % 7 + 1;
    int totald = month[m];
    int i = 1;
    if(m == 2 && isrunnian(y)) totald++;
    print_frist_line(d, i);
    for( ; i <= totald; i++){
        switch (d)
        {
        case 6:
            printf("%4d", i);
            printf("\n");
            d++;
            break;
        case 7:
            printf("%3d", i);
            d = 1;
            break;
        default:
            printf("%4d", i);
            d++;
            break;
        }
    }
}