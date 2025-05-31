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

void preorder(struct TreeNode* node, int* size, int* ans){
    if(node == NULL) return;
    ans[(*size)++] = node->val;
    preorder(node->left, size, ans);
    preorder(node->right, size, ans);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = malloc(sizeof(int) * 100);
    *returnSize = 0;
    preorder(root, returnSize, ans);
    return ans;
}