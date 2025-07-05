/*
像是顆二元樹， root 為 b
左子樹與 parent 相同，右子樹為 (parent + 1) % 26
像是 b => b,c
減去開頭的 a 後，找 k-1 在樹的哪個位置就好
*/

char kthCharacter(int k) {
    k -= 2;
    if(k == -1) return 'a';
    bool path[9];
    int cnt = 0;
    while(k){
        path[cnt++] = k%2;
        k = (k-1)/2;
    }
    int ans = 1;
    for(--cnt; cnt >= 0; --cnt){
        ans = (ans + (!path[cnt])) % 26;
    }
    return (char)('a' + ans);
}