long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
    long long total = 0;
    long long cost = costBoth < cost1 + cost2 ? costBoth : cost1 + cost2;
    int need = need1 < need2 ? need1 : need2;

    total += cost * need;
    need1 -= need;
    need2 -= need;

    if(need1){
        cost = costBoth < cost1 ? costBoth : cost1;
        total += cost * need1;
    }
    if(need2){
        cost = costBoth < cost2 ? costBoth : cost2;
        total += cost * need2;
    }

    return total;
}
