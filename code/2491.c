int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

long long dividePlayers(int* skill, int skillSize) {
    long long chemistry = 0;

    qsort(skill, skillSize, sizeof(int), cmp);

    int teamSum = skill[0] + skill[skillSize-1];

    for(int i = 0; i < skillSize/2; ++i){
        if(skill[i] + skill[skillSize-i-1] == teamSum){
            chemistry += (long long)skill[i] * (long long)skill[skillSize-i-1];
        } else{
            return -1;
        }
    }

    return chemistry;
}