bool isUgly(int n) {
    // An ugly number is a positive integer
    if (n <= 0) return false;
    int primes[3] = {2, 3, 5};
    for (int i = 0; i < 3; i++) {
        while (n % primes[i] == 0) n /= primes[i];
    }
    return n == 1;
}