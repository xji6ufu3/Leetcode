/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int postorder(struct TreeNode* node, bool* check){
    if(node == NULL || *check == false) return 0;
    int depl = postorder(node->left, check);
    int depr = postorder(node->right, check);
    if(abs(depl-depr) > 1) *check = false;
    node->val = depl > depr ? depl : depr;
    return node->val+1;
}

bool isBalanced(struct TreeNode* root) {
    bool* check = malloc(sizeof(bool));
    *check = true;
    int ret = postorder(root, check);
    bool ans = *check;
    free(check);
    return ans;
}