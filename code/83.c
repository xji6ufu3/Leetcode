/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* ptr = head;
    while(ptr != NULL && ptr->next != NULL){
        struct ListNode* next = ptr->next;
        while(next != NULL){
            if(next->val == ptr->val){
                next = next->next;
            } else {
                break;
            }
        }
        ptr->next = next;
        ptr = next;
    }
    return head;
}