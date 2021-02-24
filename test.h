#include <stdio.h>
#include <stdlib.h>

typedef struct _testcase{
    int len;
    int* data;
}testcase;

int isnum(char c){
    if( c >= 48 && c <= 57){
        return 1;
    }
    return 0;
}

testcase* readtest(char* filename){
    testcase* testdata = (testcase*)malloc(sizeof(testcase));
    FILE* f = fopen(filename, "r");
    int counter = 0;
    char prev = ' ';
    char c;
    while ((c = fgetc(f)) != EOF){
        // if you hit a number and previos char was not a number,
        // then you hit a new word
        if(isnum(c) && (!isnum(prev))){
            counter++;
        }
        prev = c;
    }
    
    fclose(f);
    // reopen to copy
    testdata->len = counter;
    f = fopen(filename, "r");
    int* data = malloc(sizeof(int)*counter);
    int val;
    for(int i = 0; i < counter; i++){
        fscanf(f, "%d", &val);
        data[i] = val;
    }
    testdata->data = data;
    fclose(f);
    return testdata;
}