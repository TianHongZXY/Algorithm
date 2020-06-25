#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> process(int n){
    if(!n){
        return {};
    }
    else if(n == 1)
        return {"n", "is 1"};
    else if(n == 2)
        return {"n", "is", "2"}; // 返回的列表初始化vector
}

int &get(int *arry, int index){
    return arry[index];
}

int main(){
    int n = 2;
    for(auto s : process(n)){
        cout << s << endl;
    }
    int ia[10];
    for(int i = 0; i != 10; i++)
        get(ia, i) = i;
    return 0;
}