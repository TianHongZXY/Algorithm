#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int kthToLast(ListNode* head, int k) {
    ListNode *p = head, *q = head;
    for(int i = 1; i < k; i++)
        q = q->next;
    while(q->next){
        p = p->next;
        q = q->next;
    }
    return p->val;
}

int main(){

}