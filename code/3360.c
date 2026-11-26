bool canAliceWin(int n) {
    // unsigned long long nn = 0;

    // for(int n = 50; n > 0; --n){
    //     int tmp = n;
    //     for(int i = 10; i; --i){
    //         if(i > n){
    //             nn = (nn << 1) | (i % 2);
    //             break;
    //         }
    //         n -= i;
    //     }
    //     n = tmp;
    // }
    
    // printf("nn: %lld\n", nn); // nn: 861475883449856

    return 861475883449856 & (1ULL << n-1);
}
