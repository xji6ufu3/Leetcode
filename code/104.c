/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxdep(struct TreeNode* node, int dep){
    if(node == NULL) return dep;
    int depl = maxdep(node->left, dep+1), depr = maxdep(node->right, dep+1);
    return depl > depr ? depl : depr;
}

int maxDepth(struct TreeNode* root) {
    return maxdep(root, 0);
}