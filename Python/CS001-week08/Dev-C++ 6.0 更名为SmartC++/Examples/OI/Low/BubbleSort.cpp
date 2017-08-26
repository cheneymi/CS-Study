#include <cstdio>
int arr[20000];
void bubble_sort(int *a, int n) {
    int *p1 = a;
    int *p2 = a;
    int k;
    int j;

    for(int i = 0; i < n; i++) {
        p2 = p1;
        p2++;

        for(j = n - i - 1; j > 0; j--) {
            if(*p2 < *p1) { // ÉýÐò
                k = *p1;
                *p1 = *p2;
                *p2 = k;
            }

            p2++;
        }

        p1++;
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

    bubble_sort(arr, n);
    printf("After arranging: \n");

    for(int i = 1; i <= n; ++ i) {
        printf("%d ", arr[i]);
    }

    return 0;
}
