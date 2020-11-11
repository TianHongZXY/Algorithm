#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(-1), *p = head;
    int carry = 0;
    while(l1 || l2){
        int add = carry;
        add += (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val);
        carry = add / 10;
        head->next = new ListNode(add % 10);
        head = head->next;
        l1 = (l1 == NULL ? l1 : l1->next);
        l2 = (l2 == NULL ? l2 : l2->next);
    }
    if(carry)
        head->next = new ListNode(carry);
    return p->next;
}

