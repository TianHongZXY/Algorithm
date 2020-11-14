#include <cstdio>
#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    do{
        if(fast) fast = fast->next;
        if(fast) fast = fast->next;
        if(slow) slow = slow->next;
    }while(fast && fast != slow);
    int lenofcycle = 0;
    if(!fast) return fast;
    else{
        do{
        fast = fast->next->next;
        slow = slow->next;
        lenofcycle++;
        }while(fast != slow);
    }
    fast = slow = head;
    for(int i = 0; i < lenofcycle; i++) fast = fast->next;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

ListNode *detectCycle2(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while(fast && fast->next){ // 二者都不可以为NULL，否则代表着链表有结尾，必无环
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            fast = head;
            while(fast != slow){
                fast = fast->next->next;
                slow = slow->next;
            }
            return fast;
        }
    }
    return NULL;
}