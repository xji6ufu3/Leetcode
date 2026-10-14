#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool isLeaf(TreeNode* node){
        if(node->left == nullptr && node->right == nullptr){
            return true;
        } else {
            return false;
        }
    }    

    int sumOfLeftLeaves(TreeNode* root) {
        return ((root->left)?
            (isLeaf(root->left)?root->left->val:
                sumOfLeftLeaves(root->left)):0) + 
            ((root->right)?
            (isLeaf(root->right)?0:
                sumOfLeftLeaves(root->right)):0);
    }
};
