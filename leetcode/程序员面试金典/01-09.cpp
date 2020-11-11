#include <string>
#include <set>
#include <vector>
using namespace std;

bool isFlipedString(string s1, string s2) {
    if(s1.length() != s2.length()) return false;
    if(s2 == "") return true;
    // set<int> head;
    vector<int> head;
    for(int i = 0; i < s2.length(); i++)
        // 再往后多检测一位可以大幅提升效率
        if(s2[i] == s1[0] && (i == s2.length() - 1 || s1[1] == s2[i+1]))
            head.push_back(i);
            // head.insert(i);
    for(int hd : head){
        if(s2.substr(hd) + s2.substr(0, hd) == s1)
            return true;
    }
    return false;
}

bool isFlipedString2(string s1, string s2) {
    // 如果s2是s1旋转后形成，则让s2和自身相加后，s1必在其中
    if(s1.length() != s2.length()) return false;
    string ss = s2 + s2;
    return ss.find(s1) != string::npos ? true : false;

    // return s1.size() == s2.size() && (s2 + s2).find(s1) != string::npos;
}

int main(){
    string s1 = "waterbottle", s2 = "bottlewatre";
    printf("%s", isFlipedString2(s1, s2) ? "True" : "False");
    
    return 0;
}