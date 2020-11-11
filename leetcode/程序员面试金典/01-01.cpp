#include <string>
#include <cctype>
#include <cstring>
using namespace std;
int a[26];
bool isUnique(string astr) {
    memset(a, 0, sizeof(a));
    int len = astr.size();
    // for(int i = 0; i < len; i++)
        // astr[i] = tolower(astr[i]);
    for(int i = 0; i < len; i++)
        if(a[astr[i] - 'a'])
            return false;
        else
            a[astr[i] - 'a']++;
    return true;
}

bool isUnique2(string astr) {
    // 位运算，不使用其他数据结构
    int b = 0;
    int len = astr.size();
    for(int i = 0; i < len; i++){
        if(b & (1 << (astr[i] - 'a')))
            return false;
        b |= 1 << (astr[i] - 'a');
    }
    return true;
}

int main(){
    string astr = "letcod";
    bool res = isUnique2(astr);
    printf("%s", res ? "true" : "false");
}
