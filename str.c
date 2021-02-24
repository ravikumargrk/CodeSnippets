#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Solves missing digits in equation "A(operator)B=C" passed as a string
void SolveMissingDigits(char input[]){
    // extract a
    char* token;
    char* brk = strpbrk(input, "-+*/");
    char op[] = {input[(int)(brk-input)]};
    token = strtok(input, op); // break at operator
    
    char a[10];
    strcpy(a,token); 
    // printf("%s\n", a); // a stored
    
    char b[10];
    token = strtok(NULL, "=");
    strcpy(b, token);
    // printf("%s\n", b); // b stored
    
    char c[10];
    token = strtok(NULL, "=");
    strcpy(c, token);
    // printf("%s\n",c); // c stored

    int qa_i = (int)(strpbrk(a, "?")-a); // position of missing digit in a
    int qc_j = (int)(strpbrk(c, "?")-c); // position of missing digit in c

    int A,B,C; // numbers in equation
    B = atoi(b); 
    int i = 0,j = 0; // missing digits
    int result = 0;
    for (i = 0; i < 10; i++) {
        // if(qa_i==0 && i == 0){
        //     continue;
        // }
        A = atoi(a);
        a[qa_i] = (char) ( (int)'0' + i ); 
        for (j = 0; j < 10; j++) {
            // if(qc_j==0 && j == 0){
            //     continue;
            // }
            c[qc_j] = (char) ( (int)'0' + j ); 
            C = atoi(c);
            // printf("C : %d\tA %c B = ", C, op[0]);
            if(op[0]=='-'){
                result = A-B;
            }
            if(op[0]=='+'){
                result = A+B;
            }
            if(op[0]=='*'){
                result = A*B;
            }
            if(op[0]=='/'){
                result = A/B;
            }
            // printf("%d\n", result);
            if(result == C) break;
        }
        if(result == C) break;
    }
    printf("C : %d\tA %c B = %d %c %d = %d\n", C, op[0], A, op[0], B, result);
}

char teststr[] = "Looking back on a childhood filled with events and memories, I find it rather difficult to pick one that leaves me with the fabled warm and fuzzy feelings. As the daughter of an Air Force major, I had the pleasure of traveling across America in many moving trips. I have visited the monstrous trees of the Sequoia National Forest, stood on the edge of the Grand Canyon and have jumped on the beds at Caesar's Palace in Lake Tahoe.\nThe day I picked my dog up from the pound was one of the happiest days of both of our lives. I had gone to the pound just a week earlier with the idea that I would just look at a puppy. Of course, you can no more just look at those squiggling little faces so filled with hope and joy than you can stop the sun from setting in the evening. I knew within minutes of walking in the door that I would get a puppy… but it wasn't until I saw him that I knew I had found my puppy.\nLooking for houses was supposed to be a fun and exciting process. Unfortunately, none of the ones that we saw seemed to match the specifications that we had established. They were too small, too impersonal, too close to the neighbors. After days of finding nothing even close, we began to wonder: was there really a perfect house out there for us?";

#define min2(a,b) a<b?a:b
#define min3(a,b,c) min2(a,b)<c?min2(a,b):c

// function prints all sentences in a given string
void printallsentences(char essay[]){
    char* remaining_essay = essay;
    char* token;
    char delim[1];
    char* brk;
    while(1){
        // strpbrk
        brk = strpbrk(remaining_essay,".?!");
        if(brk==NULL) break;
        delim[0] = remaining_essay[(int)(brk-remaining_essay)];
        token = strtok(remaining_essay, delim); 
        if(token==NULL){
            break;
        }
        printf("%s%s\n", (token[0]==' ')?token+1:token, delim);
        remaining_essay = remaining_essay + strlen(token) + 1;
    }
}


int main() {
    // test
    printallsentences(teststr);

    // 12?4.34=23?5
    char input[35];
    strcpy(input, "5?6*24=1?824");
    SolveMissingDigits(input);
    return 0;
}