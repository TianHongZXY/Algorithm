//
// Created by TianHongZXY on 2020/4/9.
//
#include <queue>
using namespace std;
const int maxn = 100;

struct Node{
    bool have_value;
    int v;
    Node *left, *right;
    Node():have_value(false),left(NULL),right(NULL){};
};

queue<Node*> freenodes;
Node node[maxn];

void init(){
    for(int i = 0; i < maxn; i++)
        // push进去的是引用
        freenodes.push(&node[i]);
}

Node* newnode(){
    // 从内存池取出一个Node，对其重新初始化
    Node* u = freenodes.front();
    u->left = u->right = NULL;
    u->have_value = false;
    freenodes.pop();
    return u;
}

void deletenode(Node* u){
    // 把一个不用的node放回内存池
    freenodes.push(u);
}

int main(){
    init();
    Node* u = newnode();
    u->v = 10;
    u->have_value = true;
    deletenode(u);
    return 0;
}
