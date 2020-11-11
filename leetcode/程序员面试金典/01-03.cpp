#include <string>
#include <iostream>
#include <cstring>
using namespace std;
char pOutput[50 + 10];
char pInput[50 + 10];
char Src[] = " ";
char Dst[] = "%20";

void efficient_replace(char *pI, char *pO, char *pSrc, char *pDst){
    char *pi, *po, *p;
    int len_src, len_dst, len;
    pi = pI; po = pO;
    len_src = strlen(pSrc);
    len_dst = strlen(pDst);
    p = strstr(pi, pSrc);
    if(p){
        while(p){
            len = (int)(p - pi);
            memcpy(po, pi, len);
            memcpy(po + len, pDst, len_dst);
            pi = p + len_src;
            po = po + len + len_dst;
            p = strstr(pi, pSrc);
        }
        strcpy(po, pi);
    }
    else{
        strcpy(po, pi);
    }
}

string replaceSpaces(string S, int length) {
    S = S.substr(0, length);
    strcpy(pInput, S.c_str());
    efficient_replace(pInput, pOutput, Src, Dst);
    string res(pOutput);
    // memset(pInput, 0, sizeof(pInput));
    // memset(pOutput, 0, sizeof(pOutput));
    return res;
}

string replaceSpaces2(string S, int length) {
    S = S.substr(0, length);
    int M = 0;
    int N = length;
    for(int i = 0; i < N; i++)
        if(S[i] == ' ')
            M++;
    char *p = (char*)malloc(sizeof(char) * (2 * M + N + 10));
    int j = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == ' '){
            p[j++] = '%';
            p[j++] = '2';
            p[j++] = '0';
        }
        else
            p[j++] = S[i];
    }
    p[j] = '\0';
    return string(p);
}

string replaceSpaces3(string S, int length) {
    int pos = S.size()-1;
    for (int i = length-1; i >= 0; --i) {
        if (S[i] == ' ') {
            S[pos--] = '0';
            S[pos--] = '2';
            S[pos--] = '%';
        }
        else {
            S[pos--] = S[i];
        }
    }
    return S.substr(pos+1);
}

int main(){
    string S = "Mr John Smith    ";
    int length = 13;
    string res = replaceSpaces3(S, length);
    cout << res << endl;
    S = "           ";
    length = 5;
    res = replaceSpaces3(S, length);
    cout << res << endl;

    return 0;
}