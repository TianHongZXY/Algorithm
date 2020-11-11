#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
int a1[26], a2[26];

bool CheckPermutation(string s1, string s2) {
    int len1 = s1.size(), len2 = s2.size();
    memset(a1, 0, sizeof(a1));
    memset(a2, 0, sizeof(a2));
    for(int i = 0; i < len1; i++)
        a1[s1[i] - 'a']++;
    for(int i = 0; i < len2; i++)
        a2[s2[i] - 'a']++;
    int j = 0;
    while(j < 26 && a1[j] == a2[j])
        j++;
    return (j == 26) ? true : false;
}

bool CheckPermutation2(string s1, string s2) {
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return s1==s2;
}

bool CheckPermutation3(string s1, string s2) {
    unordered_map<char, int> mp;
    for(char c1 : s1)
        mp[c1]++;
    for (char c2 : s2)
        mp[c2]--;
    for(int i = 0; i < 26; i++)
        if(mp['a' + i])
            return false;
    return true;
}

int main(){
    string s1 = "abc";
    string s2 = "bad";
    printf("%s", CheckPermutation(s1, s2) ? "true" : "false");
    return 0;
}