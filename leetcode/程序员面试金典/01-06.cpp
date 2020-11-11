#include <string>
#include <vector>
using namespace std;

string compressString(string S) {
    vector<string> res;
    int cnt = 1;
    for(int i = 1; i < S.size(); i++){
        if(S[i] == S[i - 1]) cnt++;
        else{
            res.push_back(S[i-1] + to_string(cnt));
            cnt = 1;
        }
    }
    res.push_back(S[S.size() - 1] + to_string(cnt));
    string resstr = "";
    for(string s : res)
        resstr += s;
    return S.size() > resstr.size() ? resstr : S;
}

string compressString2(string S) {
    vector<char> res;
    int cnt = 1;
    string num;
    for(int i = 1; i < S.size(); i++){
        if(S[i] == S[i - 1]) cnt++;
        else{
            res.push_back(S[i-1]);
            num = to_string(cnt);
            for(int j = 0; j < num.size(); j++) res.push_back(num[j]);
            cnt = 1;
        }
    }
    res.push_back(S[S.size() - 1]);
    num = to_string(cnt);
    for(int j = 0; j < num.size(); j++) res.push_back(num[j]);
    if(res.size() >= S.size()) return S;
    else{
        char resstr[S.size() * 2];
        for(int i = 0; i < res.size(); i++)
            resstr[i] = res[i];
        resstr[res.size()] = '\0';
        return string(resstr);
    }
}

string compressString3(string S) {
    string ret = "";
    int cnt = 1;
    for(int i = 0; i < S.size(); i++){
        if(i != S.size() - 1 && S[i] == S[i + 1]){
            cnt++; continue;
        }
        ret.push_back(S[i]);
        ret.append(to_string(cnt));
        cnt = 1;
    }
    return ret.size() < S.size() ? ret : S;
}

string compressString4(string S) {
    int N = S.length();
    string res;
    int i = 0;
    while (i < N) {
        int j = i;
        while (j < N && S[j] == S[i]) j++;
        res += S[i];
        res += to_string(j - i);
        i = j;
    }
    return res.length() < S.length() ? res : S;
}


int main(int argc, char const *argv[])
{
    string S = "rrrrrLLLLLPPPPPPRRRRRgggNNNNNVVVVVVVVVVDDDDDDDDDDIIIIIIIIIIlllllllAAAAqqqqqqqbbbNNNNffffff";
    printf("%s", compressString3(S).c_str());
    return 0;
}
