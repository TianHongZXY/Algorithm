/* ====================================================
#   Copyright (C) 2021  All rights reserved.
#
#   Author        : Xinyu Zhu
#   Email         : zhuxy21@mails.tsinghua.edu.cn
#   File Name     : 1.cpp
#   Last Modified : 2021-10-16 20:17
#   Describe      : 
#
# ====================================================*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int dog_food_left[10000 + 10];
long cat_food_left[10000 + 10];

int main() {
    int T, N, D, C, M;
    bool unfeed;
    string S;
    cin >> T;
    for(int k = 1; k <= T; k++){
        unfeed = false;
        memset(dog_food_left, 0, sizeof(int) * 10010);
        memset(cat_food_left, 0, sizeof(int) * 10010);
        cin >> N >> D >> C >> M;
        cin >> S;
        dog_food_left[0] = D; 
        cat_food_left[0] = C;

        for(int i = 0; i < S.length(); i++) {
            cat_food_left[i + 1] = cat_food_left[i];
            dog_food_left[i + 1] = dog_food_left[i];
            if(S[i] == 'C') {
                if(cat_food_left[i] > 0)
                    cat_food_left[i + 1]--;
                else {
                    for(int j = i + 1; j < S.length(); j++)
                        if(S[j] == 'D'){
                            unfeed = true;
                            break;
                        }
                    if(unfeed) break;
                }
            }
            else {
                if(dog_food_left[i] > 0) {
                    dog_food_left[i + 1]--;
                    cat_food_left[i + 1] += M;
                }
                else {
                    unfeed = true;
                    break;
                }
            }
        }
        if(unfeed)
            cout << "Case #" << k << ": " << "NO" << endl;
        else
            cout << "Case #" << k << ": " << "YES" << endl;
    }
    return 0;
}
