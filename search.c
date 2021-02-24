#include <stdio.h>
#define LEN 15

int LinearSearch(int array[], int l, int r, int x){
    for (int i = l; i <= r; i++) {
        if(array[i]==x){
            return i;
        }
    }
    return -1;
}
int BinarySearch(int array[], int l, int r, int x){
    int mid = l + ( r - l )/2;
    if(array[mid]==x){
        return mid;
    }
    if(x < array[mid]){
        return BinarySearch(array, l, mid - 1, x); // left
    } else {
        return BinarySearch(array, mid + 1, r, x); // right
    }
    return -1;
}

int FirstBinarySearch(int array[], int l, int r, int x){
    int mid = l + ( r - l )/2;
    // printf("%d\t%d\n",l,r);
    // pick mid only if mid-1 either not exists or x is higher than prev element
    // leaving no room for more x's on the left
    if(x == array[mid]){
        if(mid == 0) return mid;
        if(x < array[mid-1]) return mid; // no more x's on left
        else{
            // go left
        }
    }
    if(x > array[mid]){
        return FirstBinarySearch(array, mid + 1, r, x); // right
    } else {
        return FirstBinarySearch(array, l, mid - 1, x); // left
    }
    return -1;
}

int LastBinarySearch(int array[], int l, int r, int x){
    int mid = l + ( r - l )/2;
    // printf("%d\t%d\n",l,r);
    if(x == array[mid]){
        if(mid == LEN - 1) return mid;
        if(x > array[mid+1]) return mid; // no more x's on right
        else{
            // go right
        }
    }
    if(x < array[mid]){
        return LastBinarySearch(array, l, mid - 1, x); // left
    } else {
        return LastBinarySearch(array, mid + 1, r, x); // right
    }
    return -1;
}

int JumpSearch(int array[], int step, int len, int x){
    for (int i = 0; i*step < len; i++) {
        if(array[i*step] >= x){
            return LinearSearch(array, (i-1)*step, i*step, x);
        }
    }
    return -1;
}

#define minima(a,b) (a<b)?a:b
int ExpSearch(int array[], int len, int x){
    if(array[0]==x) return 0;
    int i;
    // iterate till you hit the index where you know element is < x
    for (i = 1; array[i] <= x && i < len; i *= 2);

    return BinarySearch(array, i/2, minima(i,len-1), x);
}
// smallest fib[i] greater than n:
int fib_gen(int n){
    int fib[n + 5]; fib[0] = 0; fib[1] = 1;
    int j = 0;
    for (int i = 2; i < n + 2; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        if ( fib[i] < n){
            j = i;
        }
    }
    return fib[j + 1];
}

float squareRoot(int number, float step) {
    int start = 0; 
    int mid;
    int end = number;
    float result;
    while(start <= end){
        mid = (start + end)/2;
        // printf("[%d\t%d]\t %d **2 = %d\n",start, end, mid, mid*mid);
        if(mid*mid == number) return mid;
        if(mid*mid < number){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    int i = (int)(-1/step);
    while((mid + i*step)*(mid + i*step) < number){
        i++;
        // printf("%f ^2 =\t%f\n",(mid + i*step),(mid + i*step)*(mid + i*step));
    }
    result = mid + (i-1)*step;
    return result;
}

// int list[LEN] = {14,15,19,31,41,45,52,57,58,62,66,68,80,95,99};
//                0  1  2  3  4  5  6  7  8  9 10 11 12 13 14
int list[LEN] = {45,45,45,45,45,45,45,45,45,45,45,45,45,45,45};

int main(){
    // sqrt(48) = 6.928203
    // sqrt(50) = 7.07106781
    printf("%f\n", squareRoot(48, 0.0001));
    // printf("%d\n", BinarySearch(list, 0, LEN-1, 45));
    // printf("%d\n", FirstBinarySearch(list, 0, LEN-1, 45));
    // printf("%d\n", LastBinarySearch(list, 0, LEN-1, 45));
    // printf("%d\n", LinearSearch(list, 0, LEN-1, 45));
    // printf("%d\n", JumpSearch(list, 3, LEN, 45));
    // printf("%d\n", ExpSearch(list, LEN, 45));

}