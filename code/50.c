#include <stdio.h>

double myPow(double x, int n){
    if(n == 0 || x == 1) return 1;
    if(x == 0) return 0;
    if(n == 1) return x;
    if(n == 2) return x * x;

    if(n < 0){ // avoid accumulated floating-point error
        return 1 / (myPow(myPow(x, (-1)*(n/2)), 2) * myPow(x, (-1)*(n%2)));
    } else {
        return myPow(myPow(x, n/2), 2) * myPow(x, n%2);
    }

}

int main(){
    double x;
    int n;

    printf("x: ");
    scanf("%lf", &x);
    printf("n: ");
    scanf("%d", &n);

    printf("ans: %lf\n", myPow(x, n));
}