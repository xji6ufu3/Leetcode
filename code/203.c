/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* fakehead = malloc(sizeof(struct ListNode));
    struct ListNode* pre = fakehead, *tmp;
    fakehead->next = head;
    while(head != NULL){
        if(head->val == val){
            pre->next = head->next;
            tmp = head;
            head = head->next;
            free(tmp);
        } else {
            pre = pre->next;
            head = head->next;
        }
    }
    return fakehead->next;
}