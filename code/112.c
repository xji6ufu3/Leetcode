/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool check(struct TreeNode* node, int sum, int target){
    if(node == NULL) return false;
    if(node->left == NULL && node->right == NULL){  // leaf
        return sum + node->val == target;
    }
    if(node->left == NULL){
        return check(node->right, sum + node->val, target);
    }
    if(node->right == NULL){
        return check(node->left, sum + node->val, target);
    }
    return check(node->left, sum + node->val, target) || check(node->right, sum + node->val, target);
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    return check(root, 0, targetSum);
}