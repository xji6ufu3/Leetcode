/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* ptr1 = NULL, *ptr2 = head, *ptr3 = head;
    while(ptr2){
        ptr3 = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr3;
    }
    return ptr1;
}