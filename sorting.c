#include <stdio.h>

void CopyArray(int A[], int l, int r, int B[]){
    int b = 0;
    for( int k = l; k < r+1; k++)
        B[b++] = A[k];
}

void Merge(int array[], int l, int m, int r){
    // merge sub arrays A[l, m] and A[m+1, r] 
    // such that the final array is ascending
    // array len = end_index - start_index + 1
    int left[m - l + 1];
    int right[r - m]; //r - (m+1) + 1
    // init left and right
    CopyArray(array, l, m, left);
    CopyArray(array, m+1, r, right);
    // shit
    int i = 0; int j = 0; int k = 0;
    while( i < (m - l + 1) && j < (r - m) ) {
        if(left[i] <= right[j]){
            array[i] = left[i];
            i++;
        }else{
            array[i] = right[j];
            j++;
        }
        k++;
    }
    // remaining shit
    while ( i < (m - l + 1) ) {
        array[k] = left[i];
        i++; k++;
    }
    // even more remaining shit
    // remaining shit
    while ( j < (r - m) ) {
        array[k] = right[j];
        j++; k++;
    }
}
int part_index(int array[], int l, int r){
    int pivot = array[r];
    int swap_buffer;
    int i = l-1;
    for (int j = l; i < r; i++) {
        // swap
        if(array[j] < pivot){
            i++;
            swap_buffer = array[i];
            array[i] = array[j];
            array[j] = swap_buffer;
        }
    }
    // swap_buffer = array[i+1];
    // array[i+1] = array[r];
    // array[r] = swap_buffer;
    return i;
}
void QuickSort(int array[], int l, int r){
    if(l<r){
        int m = part_index(array,   l, m);
        QuickSort(array,   l, m);
        QuickSort(array, m+1, r);
    }
}
void MergeSort(int array[], int l, int r){
    if (l >=r ) return; //break
    int m = l + (r - l)/2;
    MergeSort(array,   l, m);
    MergeSort(array, m+1, r);
    Merge(array, l, m, r);
}

void PrintArray(int A[], int start, int len)
{
    for( int k = start; k < len + start; k++){
        printf("%d\t",A[k]);
    }
    printf("\n");
}

int main(){
    int A[] = {38, 27, 43, 3, 9, 82, 10};
    int l = 0;
    int r = 6;
    int len = 7;
    PrintArray(A, l, len);
    QuickSort(A, l, r);
    PrintArray(A, l, len);
    return 0;
}