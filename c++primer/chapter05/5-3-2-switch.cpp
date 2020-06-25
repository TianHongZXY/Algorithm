#include <cstdio>
#include <iostream>
int main(){
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch = '1';
    while(std::cin >> ch && ch != 'Q'){
        switch (ch){
            case 'a': aCnt++; int i; break; // i没有被初始化，合法，如果给i初始化一个值，就不合法了
            case 'e': eCnt++; break;
            case 'i': iCnt++; break;
            case 'o': oCnt++; i = 1; break;
            case 'u': uCnt++; break;
            default:
                printf("%c", ch);
        }
    }
    printf("%d %d %d %d %d\n", aCnt, eCnt, iCnt, oCnt, uCnt);
    return 0;
}