/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int getEdgeDep(struct TreeNode* node, bool way){
    int dep = 0;
    while(node != NULL){
        dep++;
        node = way ? node->left : node->right;
    }
    return dep;
}

int countNodes(struct TreeNode* root) {
    if(root == NULL) return 0;
    
    int leftEdgeDep = getEdgeDep(root, true);
    int rightEdgeDep = getEdgeDep(root, false);

    if(leftEdgeDep == rightEdgeDep){ // full binary tree
        return (1 << leftEdgeDep) - 1;  // 2^n - 1 == 2^0 + 2^1 + ... + 2^(n-1)
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}