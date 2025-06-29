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

bool isleaf(struct TreeNode* node){
    return node->left == NULL && node->right == NULL;
}

void dfs(struct TreeNode* node, char* path, char** ans, int* cnt) {
    if(!node) return;
    
    char newpath[605];
    if (!*path) sprintf(newpath, "%d", node->val);
    else sprintf(newpath, "%s->%d", path, node->val);

    if (isleaf(node)) {
        ans[*cnt] = malloc(strlen(newpath) + 1);
        strcpy(ans[(*cnt)++], newpath);
        return;
    }

    dfs(node->left, newpath, ans, cnt);
    dfs(node->right, newpath, ans, cnt);
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char** ans = malloc(sizeof(char*) * 100);
    char path[1] = "";
    *returnSize = 0;
    dfs(root, path, ans, returnSize);
    return ans;
}
