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

void traverse(struct TreeNode* node, char* str, int* cnt, char** ans){
    if(node == NULL) return;
    char tmp[10];
    sprintf(tmp, "->%d", node->val);
    strcat(str, tmp);
    if(isleaf(node)){
        ans[*cnt] = malloc(strlen(str)+1);
        strcpy(ans[(*cnt)++], str);
        return;
    }
    char strtmp[605];
    strcpy(strtmp, str);
    traverse(node->left, str, cnt, ans);
    traverse(node->right, strtmp, cnt, ans);
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char** ans = malloc(sizeof(char*)*100);
    int cnt = 0;
    char str[605];
    sprintf(str, "%d", root->val);
    if(isleaf(root)){
        ans[cnt] = malloc(strlen(str)+1);
        sprintf(ans[cnt++], "%s", str);
        *returnSize = cnt;
        return ans;
    }
    char strtmp[605];
    strcpy(strtmp, str);
    traverse(root->left, str, &cnt, ans);
    traverse(root->right, strtmp, &cnt, ans);
    *returnSize = cnt;
    return ans;
}