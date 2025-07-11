#define MOD 1000000007

int possibleStringCount(char* word, int k) {
    int len = strlen(word);
    int cnt = 1, repeat[len];
    memset(repeat, 0, sizeof(int) * len);
    int recnt = 0; // repeat[] count
    int ptr = 0;
    while(ptr < len){
        char c = word[ptr];
        while(ptr < len && word[ptr] == c) ++repeat[recnt], ++ptr;
        ++recnt;
    }

    long long ans = 1;
    for(int i = 0; i < recnt; i++){
        ans = ans * repeat[i] % MOD;
    }

    // only takes one char from all repeat[] will excess k
    // so all the combination is the answer
    if(recnt >= k) return (int)ans;

    // f(i, j) is the number of ways to construct a string 
    // using the first i+1 elements of freq 
    // such that the total constructed length is j.

    // f(i, j) = sum_(j' = 1 ~ repeat[i]) f(i-1, j-j');
    // 也就是 f(i-1, j-repeat[i]) + ... + f(i-1, j-1)
    // 代表前 i 個元素組成長度為 j 的字串的方法數
    // 但這樣要 O(k^3) (=> i,j,j') 在 k 為 2000 時要 80 億
    // 可以用前綴和 g 來加速

    // 令 g(i-1, j) = sum_(j' = 0~j) f(i-1, j');
    // 這樣計算 f(i, j) 可以降低到 O(1) time
    // f(i, j) = g(i-1, j-1) - g(i-1, j-repeat[i]-1);
    // 之所以後面要減去 g(i-1, j-repeat[i]-1) 是因為
    // g(i-1, j-1) == f(i-1, 0) + ... + f(i-1, j-1)
    // 但我們只要 f(i-1, j-repeat[i]) + ... + f(i-1, j-1)
    // 所以前面的 g(i-1, j-repeat[i]-1) == f(i-1, 0) + ... + f(i-1, j-repeat[i]-1) 要刪掉

    // f_new[i] 代表長度為 i 的方法數
    // g[i] 代表 f[0] ~ f[i] 的前綴和
    int g[k], f_new[k];
    for (int i = 0; i < k; ++i) {
        g[i] = 1;
    }

    // i 代表 f(i,j) 的 i，代表可用前 i+1 個元素
    // f[j] 跟 f_new[j] 都是在固定為 i 的前提
    // 所以其實只記錄一行
    for (int i = 0; i < recnt; ++i) {
        // j 代表組合成的長度
        for (int j = 1; j < k; ++j) {
            // f(i, j) = g(i-1, j-1) - g(i-1, j-repeat[i]-1);
            f_new[j] = g[j - 1];
            if (j - repeat[i] - 1 >= 0) {
                f_new[j] = (f_new[j] - g[j - repeat[i] - 1] + MOD) % MOD;
            }
        }
        g[0] = 0; // f_new[0] 組合成字串長度為 0 的方法數必然是 0
        for (int j = 1; j < k; ++j) {
            g[j] = (g[j - 1] + f_new[j]) % MOD;
        }
    }

    int result = (ans - g[k - 1] + MOD) % MOD;
    return result;
}