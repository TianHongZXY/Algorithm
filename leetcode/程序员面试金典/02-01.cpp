#include <cstdio>
#include <cstring>
int vis[20000+10];

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeDuplicateNodes(ListNode* head) {
    // 除了用数组，还可以用哈希表或集合
    if(head==NULL) return head;
    ListNode *p = head;
    memset(vis, 0, sizeof(vis));
    vis[p->val] = 1;
    while(p->next){
        if(vis[p->next->val])
            p->next = p->next->next;
        else{
            vis[p->next->val] = 1;
            p = p->next;
        }
    }
    return head;
}

ListNode* removeDuplicateNodes2(ListNode* head) {
    // 不使用额外空间
    if(head==NULL) return head;
    ListNode *p, *q = head; 
    while(q){ // q每次往后移动一格，p每次从q开始往后扫描，凡是遇到和q一样val的节点就把它丢掉
        p = q;
        int cur = p->val;
        while(p->next){
            if(p->next->val == cur)
                p->next = p->next->next;
            else
                p = p->next;
        }
        q = q->next;
    }
    return head;
}