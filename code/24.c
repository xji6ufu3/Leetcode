/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    struct ListNode* next = head->next;
    struct ListNode* nextHead = next->next;

    next->next = head;
    head->next = swapPairs(nextHead);
    
    return next;
}