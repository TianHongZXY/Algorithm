//
// Created by TianHongZXY on 2020/3/14.
//
#include <stdio.h>
#include <string.h>

void example3_3() {
    char s[20], buf[20];

    int count = 0;
    scanf("%s", s);
    for (int abc = 111; abc <= 999; abc++)
        for(int de = 11; de <= 99; de++){
            int x = abc * (de % 10);
            int y = abc * (de / 10);
            int z = abc * de;
            sprintf(buf, "%d%d%d%d%d", x,y,z,abc,de);
            int ok = 1;
            for (int i = 0; i < strlen(buf); i++)
                if(strchr(s, buf[i]) == NULL) ok = 0;
            if (ok){
                printf("<%d>\n", ++count);
                printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n", abc, de, x, y, z);
            }
        }
    printf("The number of solutions = %d\n", count);
}

int main(){
//  a和b的大小必须都比字符串长度大1及以上才能正确被copy到b，因为还需要保留结束字符'\0'
    char a[100] = "helloworld";
    char b[11];
    strcpy(b, a);
    printf("%s\n", b);
    strcat(a, b);
    printf("%s\n", a);
    printf("%d\n", strcmp(a, b) > 0);
    //    example3_3();
    int n = 0;
    printf("%d %d %d\n", n++, n++, n++);
    n = n++;
    printf("%d\n", n);
    n = ++n;
    printf("%d\n", n);

    char c = fgetc(stdin);
    printf("%c\n", c);
//  给c输入一个字符后回车，之后回车符就会被当做d的输入了
    char d[100];
    fgets(d, 100, stdin);
    printf("%s\n", d);
    return 0;
}
