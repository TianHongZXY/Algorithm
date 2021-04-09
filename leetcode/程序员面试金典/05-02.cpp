#include <string>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    string printBin(double num) {
        string res = "0.";
        for(int i = 1; i <= 30; i++) {
            if(num == 0) break;
            if(num >= pow(2, -i)) {
                num -= pow(2, -i);
                res += "1";
            }
            else res += "0";
        }
        if(num == 0) return res;
        else return "ERROR";
    }

    string printBin2(double num) {
        string res = "0.";
        double frac = 0.5;
        while(num > 0) {
            if(res.length() > 32) return "ERROR";
            if(num >= frac) {
                res += "1";
                num -= frac;
            }
            else res += "0";
            frac /= 2;
        }
        return res;
    }
};

