//
// Created by TianHongZXY on 2020/4/16.
//
#include <iostream>
using namespace std;

int main(){
    string a, b;
    while(cin >> a >> b) {
        try {
            if (a != b)
                throw runtime_error("Enter two same string!");
            cout << a.append(" ").append(b) << endl;
        } catch (runtime_error err){
            cout << err.what() << "\nTry Again? Enter y or n" << endl;
            char c; cin >> c;
            if(!cin || c == 'n') break;
        }
    }
}