#include <cstdio>
#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    // 头插法，greater和smaller是dummy头结点，最后把smaller的尾s与greater的头接上
    ListNode *greater = new ListNode(-1), *g = greater;
    ListNode *smaller = new ListNode(-1), *s = smaller;
    ListNode *p = head;
    while(p){
        if(p->val < x){
            s->next = p;
            s = s->next;
        }
        else{
            g->next = p;
            g = g->next;
        }
        p = p->next;
    }
    g->next = NULL; //防止死循环
    s->next = greater->next;
    return smaller->next;
}

ListNode* partition2(ListNode* head, int x) {
    // pre在前面，cur往后走，每当cur碰到比x小的值，就把它和pre交换，
    // 然后pre往后走一步，因为cur和pre都从头开始，所以pre只会停在大于等于x的值的位置，
    // 不然会跟着cur一直往前走。cur继续往后走寻找比x小的值，然后与pre交换
    ListNode *pre=head, *cur=head;
    while(cur){
        if(cur->val < x){
            int temp = cur->val;
            cur->val = pre->val;
            pre->val = temp;
            pre = pre->next;
        }
        cur = cur->next;
    }
    return head;
}

ListNode* partition3(ListNode* head, int x) {
    if (!head || !head->next)  return head;
	struct ListNode* h1 = (struct ListNode*)malloc(sizeof(struct ListNode)), *t1 = h1;
	struct ListNode* h2 = (struct ListNode*)malloc(sizeof(struct ListNode)), *t2 = h2;
	t1->next = NULL; t2->next = NULL;
	while (head){
		if (head->val < x){
			t1->next = head;
			t1 = t1->next;
		}
		else{
			t2->next = head;
			t2 = t2->next;
		}
		head = head->next;
	}
	t1->next = h2->next;
	t2->next = NULL;
	return h1->next;
}

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    // for(int i = 10; i > 0; i--){
    //     p->next = new ListNode(i);
    //     p = p->next;
    // }
    ListNode *res = partition(head, 0);
    int i = 100;
    while(i && res){
        printf("%d->", res->val);
        res = res->next;
        i--;
    }
    return 0;
}
