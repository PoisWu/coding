# include <stdio.h>
# include <assert.h>
# include <stdlib.h>


void swap(int* a, int* b){
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}

void bubble_sort(int* arr, int len){
    int swapped ;
    do{
        swapped = 0;
        for (int i = 0 ; i < len-1; i++){
            if (arr[i] > arr[i+1]){
                swap(&arr[i], &arr[i+1]);
                swapped = 1;
            }
        }
    }while(swapped);

}


void print_arr(int* arr, int len){
    for (int i =0; i< len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

}

int cmp(const void *a, const void *b){
    return *(int*)a > *(int*)b;
}


int findContentChildren(int* g, int glen, int* s, int slen){
    qsort(g, glen, sizeof(int), cmp);
    qsort(s, slen, sizeof(int), cmp);
    int result = 0;
    int ids = 0;

    for (int idg = 0; idg < glen; idg++){
        while (ids < slen && s[ids] < g[idg]){
            ids ++;
        }
        if (ids >= slen) break;
        result ++;
        ids ++;
    }
    return result;
}
int main(){
    int g[] = {10, 9, 8 , 7};
    int glen = 4;
    int s[] = {5, 6, 7, 8};
    int slen = 4;
    printf("%d\n", findContentChildren(g, glen, s, slen));

    int g2[] = {1,2};
    int g2len = 2;
    int s2[] = {1,2,3};
    int s2len = 3;
    printf("%d\n", findContentChildren(g2, g2len, s2, s2len));

}
