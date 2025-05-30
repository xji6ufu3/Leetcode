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

void inorder(struct TreeNode* node, int* ans, int* cnt){
    if(node == NULL) return;
    inorder(node->left, ans, cnt);
    ans[(*cnt)++] = node->val;
    inorder(node->right, ans, cnt);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // The number of nodes in the tree is in the range [0, 100]
    int* ans = malloc(sizeof(int)*100);
    *returnSize = 0;

    inorder(root, ans, returnSize);

    return ans;
}