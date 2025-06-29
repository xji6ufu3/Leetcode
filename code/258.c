int addDigits(int num) {
    /*
    if(num < 10) return num;
    int sum = 0;
    while(num){
        sum += num % 10;
        num /= 10;
    }
    return addDigits(sum);
    */

    // digits sum 等同於對原數 mod 9
    
    // n = a₀ + a₁·10 + a₂·10² + ... + aₖ·10ᵏ
    // n mod 9: 10 ≡ 1
    // → n ≡ a₀ + a₁·1 + a₂·1 + ... + aₖ·1 ≡ s(n)

    // 先減一再加一: 將餘數從 0~8 轉為 1~9

    if (num == 0) return 0;
    return 1 + (num - 1) % 9;
}