#include <stdio.h>
#include <string.h>
#define MAXDIGITS 100
char number[100];
char reverse_of_incremented_number[100];

char* nextbigpalindrome(char* input){
    // case 1 all 9s 9999
    int all_9s = 1;
    int no_9s = 1;
    for (int i = 0; i < strlen(input); i++) {
        // break out moment you find a non 9
        if(input[i]!='9'){
            all_9s = 0; 
        }
        if(input[i]=='9'){
            no_9s = 0;
        }
    }
    if(all_9s){
        char output[100];
        // input  9999
        // output 10001
        output[0] = '1'; // one 1
        for (int i = 1; i < strlen(input); i++) {
            output[i] = '0';
        }
        output[strlen(input)] = '1';
        return output;
    }

    // case 2 
    int left, right, center ; // indices
    if(strlen(input)%2){
        left = (int)(strlen(input)/2) - 1;
        center = (int)(strlen(input)/2);
        right = (int)(strlen(input)/2) + 1;    
    }else{
        left = (int)(strlen(input)/2);
        center = left;
        right = left + 1;
    }
    // traverse from middle to edges
    int asymmetry = 0;
    while( left > -1 && right < strlen(input)){
        if(input[left]!=input[right]){
            asymmetry = 1; // flag
            break;
        }else{
            left--; right++;
        }
    }
    int need_to_increment = 0;
    if(!asymmetry){
        // add 1 to middle digit and mirror
        need_to_increment = 1;
    }else{
        // there is assymetry
        // case 2.1 mirror and return 
        if (input[left] > input[right]){
            while( left > -1 && right < strlen(input)){
                input[right] = input[left];
                left--; right++;
            }
            return input;
        }
        // case 2.2 mirror will reduce the value
        else{
            // add 1 to the middle digit and mirror
            need_to_increment = 1;
        }
    }
    // increment
    if(need_to_increment){
        // case 3 : no 9s in the number
        if(no_9s){
            if(strlen(input)%2){
                input[center] = input[center] + 1;
            }else{
                input[center] = input[center] + 1;
                input[center + 1] = input[center + 1] + 1;;
            }
        }else{
            // continuation of case 2.2
            int carryover = 0;
            int digit_value = 0;
            // increment left side and mirror
            while( left > -1 && right < strlen(input)){
                
                input[right] = input[left];
                left--; right++;
            }
        }
    }
}

int main(){
    strcpy(number, "123658");

    return 0;
}