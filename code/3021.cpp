class Solution {
public:
    long long flowerGame(int n, int m) {
        // Alice 要贏， x+y 必須是奇數，因此 x 與 y 必須其中一個是奇數，另一個為偶數
        // 若 x 為奇數， y 為偶數， x 在 [1,n] 共有 (n+1)/2 個奇數， y 在 [1,m] 內共有 m/2 個偶數，共有 ((n+1)/2)*(m/2) 種組合
        // 同理，若 x 為偶數， y 為奇數， x 在 [1,n] 共有 n/2 個偶數， y 在 [1,m] 內共有 (m+1)/2 個偶數，共有 (n/2)*((m+1)/2) 種組合
        // 加總，並轉型成 long long 回傳
        return (long long)((n+1)/2)*(m/2)+(long long)(n/2)*((m+1)/2);
    }
};