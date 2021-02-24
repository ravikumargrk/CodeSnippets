#include <stdio.h> 
// Example for bit manipulations

// #define getbit(n,i) ((n&(1<<i))>>i) == -1 ? (int)1 : ((n&(1<<i))>>i)
int getbit(int n,int i){
    if ( ((n&(1<<i))>>i) < 0 ) { return 1;}
    else {return ((n&(1<<i))>>i);}
}

void printbits(int p, int N){
    int totalDigits = N;
    for (int i = (totalDigits - 1) ; i >= 0; i--){
        if((i!=(totalDigits - 1)) && ((i+1)%8==0)){printf(" ");} //optional
        printf("%d",getbit(p,i));
    }
}

int stoi(char* str){
    int result = 0;
    int i = 0, j = 0;
    while(str[i]!='\0'){
        if (str[i]=='1'){
            result += (1<<(32-1-j));
            j++;
        }
        else if (str[i]=='0'){
            j++;
        }
        else{
            
        }
        i++;
    }
    return result;
}

int countbits(int n){
    int count = 0;
    while ( n ) {
        n = n & (n-1);
        count++;
    }
    return count;
}

#include <limits.h>
int main()
{
    char first4last4 = 0;
    int c = 0;
    
    printf("\nProgram to write first 4 bits and last 4 bits of an int into char\n");
    printf("------------------------------------\n");
    char* str = "11011000 11001110 00100000 11101110";
    // int x = 1000000000;
    int N = stoi(str);
    // copy first 4 bits
    int c_exp;
    c = 0;
    for (int i = 31; i >= 28; i--){
    // exponent goes from 31 to 28 in N
    // exponend goes from  7 to  4 in c
        c_exp = i - 24;
        c = c | getbit(N,i)<<c_exp;
    }
    // copy last 4 bits
    for (int i = 3; i >=0 ; i--){
        // exponent goes from 3 to 0 in N
        // exponend goes from 3 to 0 in c
        c_exp = i;
        c = c | getbit(N,i)<<c_exp;
    }
    printf("integer\t: %s\nvalue\t: %d\n# of 1s\t: %d\nchar\t: ",str,N, countbits(c));
    printbits(c,8); 
    printf("\n------------------------------------\n");
}
