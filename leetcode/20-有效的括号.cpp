//
// Created by TianHongZXY on 2020/4/11.
//

bool isValid(string s) {
    map<char, int> lmp, rmp;
    lmp['('] = 1; lmp['['] = 2; lmp['{'] = 3;
    rmp[')'] = 1; rmp[']'] = 2; rmp['}'] = 3;
    stack<char> stk;
    int n = s.length();
    for(int i = 0; i < n; i++){
        if(lmp.count(s[i]))
            stk.push(lmp[s[i]]);
        else{
            if(stk.empty()) return false;
            int p = stk.top(); stk.pop();
            if(rmp[s[i]] != p) return false;
        }
    }
    if(!stk.empty()) return false;
    return true;
}