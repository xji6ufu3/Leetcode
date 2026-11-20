/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    while(root && root->val != val){
        if(val < root->val){
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return root;
}
