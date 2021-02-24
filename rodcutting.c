#include <stdio.h>

#define maximize(a,b) (a>b)?a:b

int rodcut(int price[], int len){
    int T[len + 1];
    // init
    for (int i = 0; i <= len; i++) {
        T[i] = 0;
    }
    // start fillin
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= i; j++) {
            T[i] = maximize(T[i], price[j] + T[i - j]);   
        }
    }

    return T[len];
}

int main(){
    //             { 0, 1, 2, 3, 4,  5,  6,  7,  8 };
    int price [] = { 0, 1, 5, 8, 9, 10, 17, 17, 20 };
    printf("%d\n", rodcut(price, 4));
    return 0;
}