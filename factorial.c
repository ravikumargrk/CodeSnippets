#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the extraLongFactorials function below.

#define MAX_DIGIT 200

typedef struct _number{
    __uint8_t digits[MAX_DIGIT];
    int len;
}number;

// number* number_init(){
//     number* x = malloc(sizeof(number));
//     str2digit(x, "", 0);
//     return x;
// }

#define print(x) for (int i = (x)->len - 1; i >=0 ; i--) printf("%d",(x)->digits[i]);

void str2digit(number* x, char* str, int len){
    __uint8_t i = 0;
    int j = 0;
    for (int i = len - 1; i >= 0; i--){
        if(str[i] >= 48 && str[i] <= 57){
            // append digit to x.digits and increase digit index
            x->digits[j] = str[i]-48;
            j++;
        }
    }
    x->len = j;
}

number* number_init(char* str, int len){
    number* x = malloc(sizeof(number));
    str2digit(x, str, len);
    return x;
}

#define clear(x) for(int i=0; i< MAX_DIGIT; i++) (x)->digits[i]=0;
// Operations

void multiply(number* x, number* res,__uint8_t factor){
    __uint8_t carryover = 0, buffer = 0; int i;
    res->len = x->len;
    for (i = 0 ; i < x->len ; i++){
        buffer = (carryover + x->digits[i]*factor);
        carryover = buffer/10; 
        res->digits[i] = buffer%10;
    }
    if (carryover!=0) {
        res->len = x->len + 1;
        res->digits[i] = carryover;
    }
}

void add(number*x, number* y, number* res){
    int maxdigit = (x->len > y->len)?x->len:y->len;
    res->len = maxdigit;
    __uint8_t carryover = 0, buffer = 0,dx,dy;
    int i;
    for (i = 0; i < maxdigit ; i++){
        dx = (i >= x->len)?0:x->digits[i];
        dy = (i >= y->len)?0:y->digits[i];
        buffer = dx + dy + carryover;
        carryover = buffer/10;
        res->digits[i] = buffer%10;
    }
    if (carryover!=0) {
        res->len = maxdigit + 1;
        res->digits[i] = carryover;
    }
}

void multiply2(number*x, number* y, number* res){
    number buffer;
    for (int i = 0; i < y->len; i++){
        multiply(x, &buffer, y->digits[i]);
        for (int j = 0; j < i; j++){
            multiply(&buffer, &buffer, 10); // shift left
        }
        add(&buffer, res, res);
    }
    
}

number* factorial(int x){
    number* res = number_init("1",1); // result
    number* one = number_init("1",1); // used to increment
    number* zero = number_init("0",0); // used to copy
    number* counter = number_init("1",1); // counter
    number* buffer = number_init("0",0);
    for(int i = 0; i < x; i++){
        multiply2(res,counter,buffer); // buffer = counter * result
        clear(res);
        add(zero,buffer,res); // copy buffer to result
        clear(buffer);
        add(one,counter,counter); //increase counter
    }
    return res;
}

//Main
int main() {
    number* res = factorial(100);
    print(res);

    printf("\n"); return 0;
}

