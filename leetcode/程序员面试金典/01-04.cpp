#include <string>
#include <cstring>
#include <set>
#include <bitset>
using namespace std;
int cnt[128];

bool canPermutePalindrome(string s) {
    for(int i = 0; i < s.size(); i++){
        cnt[s[i] - ' ']++;
    }
    int odd = 0;
    for(int i = 0; i < 128; i++){
        if(cnt[i] % 2) odd++;
    }
    memset(cnt, 0, sizeof(cnt));
    if(odd > 1) return false;
    return true;
}

bool canPermutePalindrome2(string s) {
    set<char> stt;
    for(int i = 0; i < s.size(); i++){
        if(stt.count(s[i]))
            stt.erase(s[i]);
        else
            stt.insert(s[i]);
    }
    return stt.size() < 2;
}

bool canPermutePalindrome3(const string &s) {
    bitset<128> bits;
    for (auto &c : s) {
        bits.flip(c);
    }
    return bits.count() < 2;
}


int main(){
    string s = "code";
    printf("%s\n", canPermutePalindrome2(s) ? "true" : "false");
    s = "aab";
    printf("%s\n", canPermutePalindrome2(s) ? "true" : "false");
    s = "AaBb//a";
    printf("%s\n", canPermutePalindrome2(s) ? "true" : "false");

    return 0;
}