/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    int sum = INT_MAX, cnt = 0, maxx = -1;
    char** ans = malloc(sizeof(char*)*(list1Size > list2Size ? list1Size : list2Size));
    for(int i = 0; i < list1Size && i <= sum; i++){
        for(int j = 0; j < list2Size && i+j <= sum; j++){
            if(!strcmp(list1[i], list2[j])){
                if(i+j < sum){
                    cnt = 0;
                    sum = i+j;
                }
                if(cnt > maxx){
                    maxx++;
                    ans[maxx] = malloc(35);
                }
                strcpy(ans[cnt++], list1[i]);
            }
        }
    }
    *returnSize = cnt;
    return ans;
}