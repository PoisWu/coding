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
    if (n==0) return 1;
    else return n*factorial(n-1);
}

int num_perm(int* arr, int len){
    int result = factorial(len);
    int count = 1;
    for (int i=1; i<len; i++){
        if (arr[i] == arr[i-1]){
            count ++;
        }else{
            result /= factorial(count);
            count = 1;
        }
    }
    result /= factorial(count);
    return result;
}

int cmp(const void* a, const void* b){
    return *(int*) a - *(int*)b;
}

void print_arr (int* arr, int len){
    for ( int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findfirstoffset(int* arr, int len){
    int firstoffset = -1;
    for (int i = 0; i < len-1; i++){
        if(arr[i] < arr[i+1]){
            firstoffset = i;
        }
    }
    return firstoffset;
};

int findceiloffset(int* arr, int len, int firstoffset){
    int ceiloffset = firstoffset+1;
    for (int j = firstoffset+ 2; j < len; j++){
        if (arr[j] > arr[firstoffset] && arr[j] < arr[ceiloffset] ){
            ceiloffset = j;
        }
    }
    return ceiloffset;
}

void heap_dump_to_console(int* arr, int len){
    qsort(arr, len, sizeof(int), cmp);
    print_arr(arr, len);

    while(1){
        int firstoffset = findfirstoffset(arr, len);
        if (firstoffset == -1) break;
        int ceiloffset =  findceiloffset(arr, len, firstoffset);
        swap(arr+firstoffset, arr+ceiloffset);
        qsort(arr + firstoffset+1, len - firstoffset -1, sizeof(int), cmp);
        print_arr(arr,len);
    }
}


void copy(int *from, int* to, int len){
    for (int i=0; i < len; i++){
        to[i] = from[i];
    }
}

void heap(int* arr, int len, int** result ){
    int iter = 0;
    result[iter] = malloc(len* sizeof(int));
    copy(arr, result[iter], len);
    iter = iter+1;

    while(1){
        int firstoffset = findfirstoffset(arr, len);
        if (firstoffset == -1) break;
        int ceiloffset =  findceiloffset(arr, len, firstoffset);
        swap(arr+firstoffset, arr+ceiloffset);
        qsort(arr + firstoffset+1, len - firstoffset -1, sizeof(int), cmp);
        result[iter] = malloc(len* sizeof(int));
        copy(arr, result[iter], len);
        iter = iter+1;
    }
}

int** permuteUnique(int* arr, int len, int* total_perm, int** arr_len){
    qsort(arr, len, sizeof(int), cmp);
    *total_perm = num_perm(arr, len);

    *arr_len = (int*) malloc(*total_perm* sizeof(int));
    for (int i = 0 ; i < *total_perm; i++){
        (*arr_len)[i] = len;
    }

    int** result = (int**) malloc(*total_perm * sizeof(int*)); 
    heap(arr, len, result);
    return result;

}


int main(){
    // int arr1[] = {1,1,1, 2,2, 4, };
    // int returnSize = num_perm(arr1, 6);
    // printf("%d \n", returnSize);
    //
    // heap_dump_to_console(arr1, 6);
    // printf("\n");

    int arr2[] = {1,1};
    int total_perm;
    int *returnColumnSizes;

    int** result = permuteUnique(arr2,  2, &total_perm, &returnColumnSizes);
    for (int i=0; i< total_perm; i++){
        print_arr(result[i], returnColumnSizes[i]);
    }


    return 0;

}

