int cmp(const void* a, const void* b){
    return *(char*)a - *(char*)b;
}

bool isAnagram(char* s, char* t) {
    int slen = strlen(s), tlen = strlen(t);
    if(slen != tlen) return false;
    qsort(s, slen, 1, cmp);
    qsort(t, tlen, 1, cmp);
    return strcmp(s, t) == 0;
}