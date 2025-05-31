/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void postorder(struct TreeNode* node, int* size, int* ans){
    if(node == NULL) return;
    postorder(node->left, size, ans);
    postorder(node->right, size, ans);
    ans[(*size)++] = node->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = malloc(sizeof(int) * 100);
    *returnSize = 0;
    postorder(root, returnSize, ans);
    return ans;
}