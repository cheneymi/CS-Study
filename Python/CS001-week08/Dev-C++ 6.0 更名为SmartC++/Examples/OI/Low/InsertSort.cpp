#include <cstdio>
int arr[20000];
void insert_sort(int *array, unsigned int n) {
    int i, j;
    int temp;

    for(i = 1; i <= n; i++) {
        temp = *(array + i);

        for(j = i; j > 0 && *(array + j - 1) > temp; j--) {
            *(array + j) = *(array + j - 1);
        }

        *(array + j) = temp;
    }

    return ;
}
int main(void) {
    int n;
    printf("Input N: ");
    scanf("%d", &n);
    printf("Input array: \n");

    for(int i = 1; i <= n; ++ i) {
        scanf("%d", &arr[i]);
    }

    insert_sort(arr, n);
    printf("After arranging: \n");

    for(int i = 1; i <= n; ++ i) {
        printf("%d ", arr[i]);
    }

    return 0;
}
