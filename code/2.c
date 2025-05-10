/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    bool up = 0;
    struct ListNode* answer = malloc(sizeof(struct ListNode));
    struct ListNode* ptr = answer;
    while (l1 || l2) {
        int sum = up;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        ptr->val = sum % 10;
        up = sum / 10;
        if (l1 || l2 || up) {
            ptr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            ptr = ptr->next;
        }
    }
    if (up) {
        ptr->val = up;
    }
    ptr->next = NULL;
    return answer;
}