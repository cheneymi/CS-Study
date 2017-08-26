#include <cstdio>
int arr[20000];
void select_sort(int *a, int n) {
    int i, j, min, t;

    for(i = 1; i <= n; i ++) {
        min = i;

		//������Сֵ
        for(j = i + 1; j < n; j ++)
            if(a[ min] > a[ j]) min = j;

		//����
        if(min != i) {
            t = a[ min];
            a[ min] = a[ i];
            a[ i] = t;
        }
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

    select_sort(arr, n);
    printf("After arranging: \n");

    for(int i = 1; i <= n; ++ i) {
        printf("%d ", arr[i]);
    }

    return 0;
}
