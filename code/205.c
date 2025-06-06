/**
 * 要確保兩字串每個字元映射唯一且互不衝突
 * 也就是說，s 合法映射到 t，同時也要 t 能合法映射到 s
 * 否則可能出現以下不合法的現象
 * s = ab, t = aa
 * 如果只檢查 s->t 會通過，但 t->s 出現一對多的錯誤
 * 沒有兩個字元映射到同一個字元，反過來說就是對方的一個字元沒有映射到兩個字元的意思
 */

bool isIsomorphic(char* s, char* t) {
    char mapST[128] = {0}, mapTS[128] = {0};
    for (int i = 0; s[i]; i++) {
        if ((mapST[s[i]] && mapST[s[i]] != t[i]) ||
            (mapTS[t[i]] && mapTS[t[i]] != s[i]))
            return false;
        mapST[s[i]] = t[i];
        mapTS[t[i]] = s[i];
    }
    return true;
}