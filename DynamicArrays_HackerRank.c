#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MWIDTH  100
#define MHEIGHT 100

float input_array[MHEIGHT][MWIDTH];
int input_height, input_width;

int readmatrix(void){
    FILE* f;
    int ii, jj;

    if((f = fopen("input", "r")) == NULL){
        printf("File couldn't be opened\n"); exit(1);
    }

    if(fscanf(f, "%d%d", &input_height, &input_width) != 2)
        exit(1);
    if (input_height < 1 || input_height > MHEIGHT || input_width < 1 || input_width > MWIDTH)
        exit(1);

    for(jj=0; jj<input_height; jj++)
        for(ii=0; ii<input_width; ii++)
            if(fscanf(f, "%f", &input_array[jj][ii]) != 1)
                exit(1);
    fclose(f);

    // for(jj=0; jj<input_height; jj++){
    //     for(ii=0; ii<input_width; ii++)
    //         printf ("%10.1f", input_array[jj][ii]);
    //     printf("\n");
    // }
    return 0;       
}

int* dynamicinput_array(int n, int queries_rows, int queries_columns, int queries[][3], int* result_count) {
    int** arr = (int**)malloc(sizeof(int*)*n); // all input_arrays
    int* sizes = (int*)malloc(sizeof(int)*n); // their sizes
    
    // results
    int* results = (int*)malloc(sizeof(int)*0);
    
    // init
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(sizeof(int)*0);
        sizes[i] = 0;
    }
    
    int lastAnswer = 0, idx;
    int p, x, y;
    for(int i = 0; i < queries_rows; i++){
        p = queries[i][0]; x = queries[i][1]; y = queries[i][2]; // helps with confusion
        idx = (x^lastAnswer) % n; // calculate idx anyway
        if(p==1){ // write \ apend
            arr[idx] = (int*)realloc(arr[idx], sizeof(int)*(++sizes[idx]));
            arr[idx][sizes[idx]-1] = y;
            // printf("Appended %d at array[%d][%d]\n",y,idx,sizes[idx]-1);
        }
        if(p==2){ // read 
            lastAnswer = arr[idx][y%sizes[idx]];
            // printf("Read %d at array[%d][%d]\n",lastAnswer,idx,y%sizes[idx]);
            results = (int*)realloc(results,sizeof(int)*(++(*result_count)));
            results[(*result_count)-1] = lastAnswer;
        }
    }
    return results;
}
/*
* OUTPUT : 
* 7
* 3
*/

int main(){
    int c = 3;
    int n, m, result_size;
    readmatrix();
    int array[input_height - 1][input_width];
    n = input_array[0][0]; m =input_array[0][1];
    
    // printf("%d\t%d\n",n,m);
    for (int i = 0; i < input_height - 1; i++){
        for (int j = 0; j < input_width ; j++){
            array[i][j] = input_array[i+1][j];
            // printf("%d\t",array[i][j]);
        }
        // printf("\n");
    }

    int* results = dynamicinput_array(n, m, input_width, array, &result_size);

    for (int j = 0; j < result_size ; j++) printf("%d\t",results[j]);

    printf("\n");return 0;
}
