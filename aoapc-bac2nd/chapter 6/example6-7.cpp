//
// Created by TianHongZXY on 2020/4/9.
//
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
bool failed;

struct Node{
    bool have_value;
    int v;
    Node *left, *right;
    Node():have_value(false),left(NULL),right(NULL){};
};
Node *root;
Node* newnode(){ return new Node();}

void addnode(int v, char *s){
    int n = strlen(s);
    Node *u = root;
    for(int i = 0; i < n - 1; i++) // 在这把最后一个字符')'去掉
        if(s[i] == 'L'){
            if(u->left == NULL) u->left = newnode();
            u = u->left;
        }else if(s[i] == 'R'){
            if(u->right == NULL) u->right = newnode();
            u = u->right;
        }
    if (u->have_value) failed = true;
    u->v = v;
    u->have_value = true;
}
const int maxn = 100;
char s[maxn];

bool bfs(vector<int> &ans){
    queue<Node*> q;
    ans.clear();
    q.push(root);
    while(!q.empty()){
        Node *u = q.front(); q.pop();
        if(!u->have_value) return false;
        ans.push_back(u->v);
        if(u->left != NULL) q.push(u->left);
        if(u->right != NULL) q.push(u->right);
    }
    return true;
}

void remove_tree(Node* u){
    if(u == NULL) return;
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}

bool read_input(){
    failed = false;
    remove_tree(root);
    root = newnode();
    while(1){
        if(scanf("%s", s) != 1) return false;
        if(strcmp(s, "()") == 0) break;
        int v;
        sscanf(&s[1], "%d", &v);
        addnode(v, strchr(s, ',')+1); // 这里把字符串最后一个括号也算进去了
    }
    return true;
}

int main(){
    vector<int> ans;
    while(read_input()){
        if(!failed && bfs(ans)) {
            int num = ans.size();
            for(int i = 0; i < num - 1; i++)
                printf("%d ", ans[i]);
            printf("%d\n", ans[num - 1]);
        }
        else
            printf("not complete\n");
    }

    return 0;
}
