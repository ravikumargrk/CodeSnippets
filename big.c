#include <stdio.h>

#define MAX_MAX_DIGIT 32766 //Theoretical limit
#define MAX_DIGIT 126
#define MAX_LEN MAX_DIGIT/2

__uint16_t strlen(char* str){
    __uint16_t len = 0;
    while(str[len]!='\0') len++;
    return len;
}

// MAX_DIGIT
typedef struct _big{
    __uint8_t digits[MAX_LEN];
}big;

big* newbig(){
    big* returnBig = (big*)malloc(sizeof(big));
    for(int i = 0; i < MAX_LEN; i++) returnBig->digits[i]=0;
    return returnBig;
}

big* newbigN(char* str){
    big* returnBig = (big*)malloc(sizeof(big));
    for(int j = 0; j < MAX_LEN; j++) returnBig->digits[j]=0;
    __uint16_t len = strlen(str);
    
    __uint16_t j = 0, buffer = 0;
    for (__uint16_t i = len - 1; i >= 0; i--){
        if(str[i] >= 48 && str[i] <= 57){
            // append digit to x.digits and increase digit index
            buffer = str[i]-48;
            returnBig->digits[j] = buffer >> 4;
            j++;
        }
    }
    if (str[0]=='-') returnBig->sign = 1;
    else returnBig->sign = 0;
    returnBig->len = j;
    return returnBig;
}

int main(){
    big x;
    printf("%ld\n",sizeof(x));
}

