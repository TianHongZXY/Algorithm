//
// Created by TianHongZXY on 2020/4/11.
//
#include <string>

struct ListNode{
    ListNode* next;
    int val;
    ListNode(): next(NULL){}
    ListNode(int x): val(x), next(NULL){}
};

ListNode* init(int n){
    ListNode* dump = new ListNode();
    ListNode* p = dump;
    for(int i = 1; i <= n; i++){
        p->next = new ListNode(i);
        p = p->next;
    }
    return dump->next;
}

ListNode* reverseLinklist(ListNode* head){
    if(head->next == NULL || head == NULL)
        return head;
    ListNode* newhead = reverseLinklist(head->next);
    ListNode* t = head->next;
    t->next = head;
    head->next = NULL;

    return newhead;
}

ListNode* reverseKgroup(ListNode* head, int k){
    if(k == 1) return head;
    ListNode* p = head;
    // 如果能翻转的不足K个，直接返回头
    for(int i = 0; i < k - 1; i++){
        if(p == NULL) return head;
        p = p->next;
    }
    if(p == NULL) return head;
    // 如果有K个能翻转，留下第K+1个元素的指针，然后将这K个元素和后面的链表断开，翻转它们
    ListNode* next = p->next;
    p->next = NULL;
    ListNode* newhead = reverseLinklist(head);
    // head为当前翻转过的长度为K的链表的尾部，它指向剩余翻转好的链表
    head->next = reverseKgroup(next, k);

    return newhead;
}

int main(){
    int n;
    scanf("%d", &n);
    ListNode* head = init(n);
    ListNode* p = head;
    while(p!=NULL){
        printf("%d ", p->val);
        p = p ->next;
    }
    printf("\n");
//    head = reverseLinklist(head);
    head = reverseKgroup(head, 3);

    while(head!=NULL){
        printf("%d ", head->val);
        head = head->next;
    }
    return 0;
}