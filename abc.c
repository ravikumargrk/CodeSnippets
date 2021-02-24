#include <stdio.h>
#include <stdlib.h>

int prime(int n){
    int* bools = (int*)calloc(sizeof(int), n + 1);
    bools[0] = 0; bools[1] = 0;
    for (int i = 2; i < n + 1; i++) {
        bools[i] = 1;
    }
    for (int p = 2; p * p <= n + 1; p++){
        // If bools[p] is not changed, 
        // then it is a prime
        if (bools[p] == 1){
            // Update all multiples 
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple 
            // of p and are less than p^2 
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                bools[i] = 0;
        }
    }
    return bools[n];
}

int countbits(int n){
    int count = 0;
    while ( n ) {
        n = n & (n-1);
        count++;
    }
    return count;
}

int isPowerof2(int n){
    if (n == 1) return 1;
    if (n == 0) return 0;
    while( n > 1){
        if(n%2) return 0;
        else n = n/2;
    }
    return 1;
}

int main(){
    int i = 0; int j = 0;
    printf("%d\t%d\n", i++, ++j);
    printf("%d\t%d\n", i, j);
    printf("%d\t%d\n", isPowerof2(2), countbits(2));
    printf("%d\t%d\n", isPowerof2(1024), countbits(1024));
    return 0;
}