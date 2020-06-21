#include <cstdio>
#include <cstring>
char a[1000][1000];
int idx = 0;

struct Node{
    Node *left, *right;
    char info;
    Node():left(NULL), right(NULL), info('\0'){};
};

void insert(Node* root, char c){
    Node* cur = root;
    while(cur != NULL){
        if(c > cur->info){
            if(cur->right == NULL){
                Node* x = new Node; x->info = c;
                cur->right = x;
                return;
            }
            else{
                cur = cur->right; continue;
            }
        }
        else{
            if(cur->left == NULL){
                Node* x = new Node; x->info = c;
                cur->left = x;
                return;
            }
            else{
                cur = cur->left; continue;
            }
        }
    }
}

void print(Node* root){
    if(root == NULL) return;
    printf("%c", root->info);
    if(root->left) print(root->left);
    if(root->right) print(root->right);
    return;
}

void solve(){
    Node *root = new Node;
    root->info = a[idx--][0];
    while(idx >= 0){
        for(int i = 0; a[idx][i] != '\0'; i++){
            insert(root, a[idx][i]);
        }
        idx--;
    }
    print(root); printf("\n");
    return;
}

int main(){
    while(scanf("%s", a[idx]) >= 1 && a[idx][0] != '$'){
        if(a[idx][0] == '*'){
            idx--; // 退到上一例子的根节点
            solve();
            idx = 0;
            continue;
        }
        idx++;
    }
    idx--; solve();

    return 0;
}