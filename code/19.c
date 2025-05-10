struct ListNode* createNode(int val) {
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // 虛擬 head 節點，處理刪除到 head 的問題
    struct ListNode* dummy = createNode(0);
    dummy->next = head;

    struct ListNode* first = dummy;
    struct ListNode* second = dummy;

    for (int i = 0; i <= n; i++) {
        first = first->next;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    struct ListNode* nodeToDelete = second->next;
    second->next = second->next->next;
    free(nodeToDelete);

    struct ListNode* newHead = dummy->next;
    free(dummy);

    return newHead;
}
