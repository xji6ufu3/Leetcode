/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 不該改變 linked list 的架構，例如修改 next 指回 head 當作 visited 的標記
// 因為在 caller 使用 free 時會出錯
// 使用：Floyd’s Cycle Detection，利用快慢指標(快的每次走兩步，慢的每次走一步)
// 如果有迴圈，兩指標最終一定會相遇，時間複雜度為 O(N1+N2)-O(λ+N)
// N1 為 list 起點到迴圈起點間的節點數，N2 為迴圈起點到會合點間的節點數
// λ 為循環的長度， N 為循環外的節點數
// λ+N≥N1+N2
// 可說時間複雜度是 O(n)，因為就算有環，每個節點頂多遍歷兩次

typedef struct ListNode node;

bool hasCycle(node *head) {
    node *fast = head, *slow = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}