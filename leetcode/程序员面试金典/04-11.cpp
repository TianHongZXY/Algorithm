#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;

class TreeNode {
private:
    int data;
    int size;
public:
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : data(x), left(NULL), right(NULL) , size(1){}

    TreeNode* getRandomNode() {
        printf("current at %d\n", data);
        int leftSize = left == NULL ? 0 : left->get_size();
        int randomIndex = rand() % size;
        if(randomIndex < leftSize) {
            return left->getRandomNode();
        }
        else if (randomIndex == leftSize) {
            return this;
        }
        else {
            return right->getRandomNode();
        }
    }

    void insertInOrder(int d) {
        if (d <= data) {
            if (left == NULL) {
                left = new TreeNode(d);
            }
            else left->insertInOrder(d);
        }
        else {
            if (right == NULL) {
                right = new TreeNode(d);
            }
            else right->insertInOrder(d);
        }
        size++;
    }

    int get_size() { return size; }
    int get_data() { return data; }

    TreeNode* find(int d) {
        if (d == data) return this;
        else if (d < data) return left == NULL ? NULL : left->find(d);
        else return right == NULL ? NULL : right->find(d);

        return NULL;
    }
};


void mid_order(TreeNode* x) {
    if(x == NULL) return;
    mid_order(x->left);
    printf("%d -> ", x->get_data());
    mid_order(x->right);
    return;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->insertInOrder(1);
    root->insertInOrder(8);
    root->insertInOrder(4);
    root->insertInOrder(2);
    root->insertInOrder(3);
    root->insertInOrder(9);
    root->insertInOrder(7);
    root->insertInOrder(6);
    root->insertInOrder(10);
    root->insertInOrder(7);
    srand((unsigned)time(0));
    printf("random data %d\n", root->getRandomNode()->get_data());
    // printf("size %d\n", root->get_size());
    // mid_order(root);
    
    return 0;
}
