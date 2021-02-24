#include <stdio.h>
#include <stdlib.h>

// https://www.hackerrank.com/challenges/crush/problem
// given a 1D array of size n, perform m operation of format : a b k
// a b k -> add k to add elements from index a-1 to b-1              | a,b <= n
// print max(array)

long printQ(int n, int queries_rows, int queries[][3]) {
    // Varialbes to read from input

    // create array with len = n, init to 0
    int* cutoffs = (int*)malloc(sizeof(int)*(n+1));
    for (int i = 0; i < n+1; i++){
        cutoffs[i] = 0; 
    }

    // for each query a b k , add +k at [a-1] and -k at [b]
    int i,j = 0;
    for (i = 0; i < queries_rows; i++){
        cutoffs[queries[i][0]-1] += queries[i][2];
        cutoffs[queries[i][1]] += -queries[i][2];
    }
    // array[i] will be cumulative of values from index j = 0 to i
    // just find max of array[i] directly
    long sum = 0, kmax = 0;
    for (int i = 0; i < n; i++){
        sum += cutoffs[i];
        if (kmax < sum) kmax = sum;
    }
    printf("\n");
    return kmax;
}

int ArrayManipulation(int n, int m, int q[][3]){
    long* scores =(long*)malloc(sizeof(long)*n); 
    for (int i = 0; i < n; i++){ // init
        scores[i]=0;
    }
    
}

int main(int argc, char const *argv[]){
    int n = 10;
    int m = 3;
    // int qurs[3][3] = {1,2,100,2,5,100,3,4,100};
    int qurs[3][3] = {1,5,3,4,8,7,6,10,1};
    printf("%ld\n",printQ(n,m,qurs));
    return 0;
}
