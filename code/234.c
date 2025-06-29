/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if(head->next == NULL) return true;
    struct ListNode *left = head, *right = head, *pre = NULL;
    while(right->next != NULL && right->next->next != NULL){
        right = right->next->next;
        struct ListNode *tmp = left->next;
        left->next = pre;
        pre = left;
        left = tmp;
    }
    bool odd = right->next == NULL;
    right = left->next;
    if(odd){
        left = pre;
    } else {
        left->next = pre;
    }
    while(left && right){
        if(left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }
    if(left || right) return false;
    return true;
}