//
// Created by TianHongZXY on 2020/3/27.
//
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

struct BigInterger{
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;

    BigInterger(long long num = 0){ *this = num;}
    BigInterger operator = (long long num){
        s.clear();
        do{
            s.push_back(num % BASE);
            num /= BASE;
        }while(num > 0);
        return *this;
    }
    BigInterger operator = (const string& str){
        s.clear();
        int x, len = (str.length() - 1) / WIDTH + 1;
        for(int i = 0; i < len; i++){
            int end = str.length() - i * WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end-start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }
    BigInterger operator + (const BigInterger& b) const{
        BigInterger c;
        c.s.clear();
        for(int i = 0, g = 0; ;i++){
            if(g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = g;
            if(i < s.size()) x += s[i];
            if(i < b.s.size()) x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }

    BigInterger operator += (const BigInterger& b){
        *this = *this + b; return *this;
    }

    bool operator < (const BigInterger& b) const {
        if(s.size() != b.s.size()) return s. size() < b.s.size();
        for(int i = s.size() - 1; i >= 0; i--)
            if(s[i] != b.s[i]) return s[i] < b.s[i];
        return false; // 相等
    }
};

ostream& operator << (ostream &out, const BigInterger& x){
    out << x.s.back();
    for(int i = x.s.size() - 2; i >= 0; i--){
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for(int j = 0; j < strlen(buf); j++) out << buf[j];
    }
    return out;
}

istream & operator >> (istream &in, BigInterger& x){
    string s;
    if(!(in >> s)) return in;
    x = s;
    return in;
}

int main(){
    BigInterger x(12345678987654321) ;
    cout << x << endl;
    x = "98765432123456789";
    cout << x << endl;
    BigInterger y(123);
    cout << (x < y) << endl;
    printf("%d", BigInterger::BASE);
}