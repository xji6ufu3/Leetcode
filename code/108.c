/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * 不能直接將中間節點當作 root，然後往左建左子樹、右建右子樹，變成一條鏈，因為這樣不平衡
 * 需要分區，像是 binarySearch 那樣，往下區分範圍，每個範圍都拿 mid 當作 parent，往下建立 children
 * 這樣的分治法，每次都拿 mid 建 node，才能確保 height balanced
 */

struct TreeNode* build(int* nums, int l, int r){
    if(l > r) return NULL;
    int mid = (l + r) / 2;
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    node->left = build(nums, l, mid-1);
    node->right = build(nums, mid+1, r);
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return build(nums, 0, numsSize-1);
}