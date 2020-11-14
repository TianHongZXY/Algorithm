#include <cstdio>
#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p = headA, *q = headB;
    while(p){
        q = headB;
        while(q){
            if(q == p) return p;
            else q = q->next;
        }
        p = p->next;
    }
    return NULL;
}

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    ListNode *p = headA, *q = headB;
    while(p != q){
        p = p == NULL ? headB : p->next;
        q = q == NULL ? headA : q->next;
    }
    return p;
}

ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB) {
    ListNode *p = headA, *q = headB;
    int lena = 0, lenb = 0;
    while(p) { p = p->next; lena++; }
    while(q) { q = q->next; lenb++; }
    if(lena >= lenb){ p = headA; q = headB; }
    else { p = headB; q = headA; }
    for(int i = 0; i < abs(lena - lenb); i++){
        p = p->next;
    }
    while(p && q){
        if(p == q) return p;
        p = p->next;
        q = q->next;
    }
    return NULL;
}
