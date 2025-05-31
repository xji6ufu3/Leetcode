/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 雙指標，A 走完改從 B 的開頭走，這樣的話要麼在相交點相會，要麼一起走到盡頭
// 例如 lenA, lenB 是 A 跟 B 沒相交前，各自的長度。 lenC 則是相交後共同的長度
// A 走完全程的長度是 lenA + lenC，接著換從 B 的起點走到相交點時，又走了 lenB，所以共走了 lenA + lenB + lenC 個點
// B 走完全程的長度是 lenB + lenC，接著換從 A 的起點走到相交點時，又走了 lenA，所以也走了 lenA + lenB + lenC 個點
// 因此，雙指標一定會相遇。即使沒有相交點，最後也會指向相同的 NULL

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* ptrA = headA, *ptrB = headB;
    while(ptrA != ptrB){
        ptrA = (ptrA == NULL) ? headB : ptrA->next;
        ptrB = (ptrB == NULL) ? headA : ptrB->next;
    }
    return ptrA;
}