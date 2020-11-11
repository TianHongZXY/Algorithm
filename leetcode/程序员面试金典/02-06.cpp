#include <cstdio>
#include <string>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse_linklist(ListNode* head){
    if(!head || !head->next) return head;
    ListNode *newhead = reverse_linklist(head->next);
    ListNode *p = head->next;
    p->next = head;
    head->next = NULL;
    return newhead;
}

bool isPalindrome(ListNode* head) {
    ListNode* p = head;
    string ori = "", aft = "";
    while(p){
        ori += to_string(p->val);
        p = p->next;
    }
    head = reverse_linklist(head);
    p = head;
    while(p){
        aft += to_string(p->val);
        p = p->next;
    }
    return ori == aft;
}

bool isPalindrome2(ListNode* head) {
    ListNode* fast = head, *slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode* rev_second_part = reverse_linklist(slow);
    while(rev_second_part){
        if(rev_second_part->val != head->val)
            return false;
        rev_second_part = rev_second_part->next;
        head = head->next;
    }
    return true;
}


ListNode *root;
bool flag = true;
void dfs(ListNode *head){
    
    if(head == NULL){
        return ;
    }
    dfs(head->next);
    if(head->val != root->val){
        flag = false;
    }
    root = root->next;
}
bool isPalindrome3(ListNode* head) {
    root = head;
    dfs(head);
    return flag;
}