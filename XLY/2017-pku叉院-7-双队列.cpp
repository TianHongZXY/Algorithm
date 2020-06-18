//
// Created by TianHongZXY on 2020/4/15.
//

#include <bits/stdc++.h>
using namespace std;

struct user{
    int id, prior;
    user(int id, int prior): id(id), prior(prior) {};
    bool operator < (const user& b) const{
        return prior < b.prior;
    }

    bool operator > (const user& b) const{
        return prior > b.prior;
    }

};

int main(){
    priority_queue<user, vector<user>, less<user> > pqbig;
    priority_queue<user, vector<user>, greater<user> > pqsmall;
    int cmd, k, p, n = 0;
    while(cin >> cmd && cmd){
        if(cmd == 1){
            cin >> k >> p;
            pqbig.push(user(k, p));
            pqsmall.push(user(k, p));
            n++;
        }
        else if(cmd == 2){
            if(n) {
                user x = pqbig.top(); pqbig.pop();
                cout << x.id << endl;
                n--;
            } else cout << "0" << endl;
        }
        else if(cmd == 3){
            if(n) {
                user x = pqsmall.top(); pqsmall.pop();
                cout << x.id << endl;
                n--;
            } else cout << "0" << endl;
        }
    }
    return 0;
}
