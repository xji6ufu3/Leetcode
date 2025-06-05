bool isHappy(int n) {
    bool visited[810] = {false};
    while(n != 1){
        int sum = 0;
        while(n){
            sum += (n%10)*(n%10);
            n /= 10;
        }
        n = sum;
        if(visited[n]) break;
        visited[n] = true;
    }
    return n == 1;
}