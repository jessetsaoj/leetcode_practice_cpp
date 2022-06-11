#include <stdlib.h>
// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

/* 
Success
Runtime: 2 ms, faster than 95.94% of C online submissions for Odd Even Linked List.
Memory Usage: 7 MB, less than 22.12% of C online submissions for Odd Even Linked List.
#LinkedList

*/

struct ListNode* oddEvenList(struct ListNode* head){
    struct ListNode evenHead = {0};
    struct ListNode *e = &evenHead, *t = head;
    if (!head) return head;
    while(t->next) {
        e->next = t->next;
        t->next = t->next->next;
        e = e->next;
        e->next = NULL;
        if(t->next) t = t->next;
    }
    t->next = evenHead.next;
    return head;
}