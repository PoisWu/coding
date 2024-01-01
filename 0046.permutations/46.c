# include <stdio.h>
# include <assert.h>
# include <stdlib.h>

void swap(int* a, int* b){
    *a = *a^*b;
    *b = *a^*b;
    *a = *b^*a;
}

int factorial(int n){
    assert(n>=0);
    if (n == 0) return 1;
    else return n*factorial(n-1);
}

void print_arr (int* arr, int len){
    for ( int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 1. Implementation of Heap's algorithm
void heap_dump_to_console(int* arr, int k, int len){
    if (k == 1){
        print_arr(arr, len);
    }
    else{
        heap_dump_to_console(arr,  k-1, len);
        for (int i = 0; i < k-1; i++){
            if(k%2){
                // k is odd
                swap(&arr[0], &arr[k-1]);
            }else{
                swap(&arr[i], &arr[k-1]);
            }
            heap_dump_to_console(arr, k-1, len);
        }
    }
}

void copy(int *from, int* to, int len){
    for (int i=0; i < len; i++){
        to[i] = from[i];
    }
}

// 2. Modify Heap's implementation, copy the permutation into 'result' array
// The iter variable is to memorize the the location where new permutation is
// stored.
void heap(int* arr, int k, int len, int** result, int* iter ){
    // int num_perm = factorial(len);
    if (k == 1){
        result[*iter] = malloc(len* sizeof(int));
        copy(arr, result[*iter], len);
        *iter = *iter+1;
    }
    else{
        heap(arr,  k-1, len, result, iter);
        for (int i = 0; i < k-1; i++){
            if(k%2){
                // k is odd
                swap(&arr[0], &arr[k-1]);
            }else{
                // k is even
                swap(&arr[i], &arr[k-1]);
            }
            heap(arr, k-1, len, result, iter);
        }
    }
}




int** permute(int* arr, int len, int* total_perm, int** returnColumnSizes){
    *total_perm = factorial(len);

    *returnColumnSizes = (int*) malloc(*total_perm* sizeof(int));
    for (int i = 0 ; i < *total_perm; i++){
        (*returnColumnSizes)[i] = len;
    }
    int** result = (int**) malloc(*total_perm * sizeof(int*)); 
    int iter = 0;
    heap(arr, len, len, result, &iter);
    return result;
}

int main(){
    int arr1[] = {1,2,3,4};
    heap_dump_to_console(arr1, 4, 4);
    printf("\n");

    int arr2[] = {1,2,3,4};
    int total_perm;
    int *returnColumnSizes;

    int** result = permute(arr2,  4, &total_perm, &returnColumnSizes);
    for (int i=0; i< total_perm; i++){
        print_arr(result[i], returnColumnSizes[i]);
    }

    return 0;

}

