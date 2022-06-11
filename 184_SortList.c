#include <stdio.h>
#include <stdlib.h>

/* 
Success
Runtime: 118 ms, faster than 31.90% of C online submissions for Sort List.
Memory Usage: 19.2 MB, less than 40.50% of C online submissions for Sort List.
#LinkedList #MergeSort
*/

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeSort(struct ListNode *);
struct ListNode* merge(struct ListNode *, struct ListNode *);
struct ListNode* getMid(struct ListNode *);

struct ListNode* mergeSort(struct ListNode *head) {
    if(!head||!head->next)
        return head;
    struct ListNode* mid = getMid(head);
    struct ListNode* right = mid->next, *left = head;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

struct ListNode* merge(struct ListNode *left, struct ListNode *right) {
    struct ListNode dummy;
    struct ListNode* d = &dummy;
    while(left && right) {
        if(left->val < right->val) {
            d->next = left;
            left = left->next;
        }
        else {
            d->next = right;
            right = right->next;
        }
        d = d->next;
    }
    if(left) d->next = left;
    if(right) d->next = right;
    return dummy.next;
}

struct ListNode* getMid(struct ListNode *head) {
    struct ListNode *oneStep = head, *twoStep = head;
    if (!oneStep->next) return oneStep; // one node left
    while(twoStep->next) {
        if(!twoStep->next->next) return oneStep;
        oneStep = oneStep->next;
        twoStep = twoStep->next->next;
    }
    return oneStep;
}

struct ListNode* sortList(struct ListNode *head){
    struct ListNode *ans = mergeSort(head);
    return ans;
}