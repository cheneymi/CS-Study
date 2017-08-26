/*

高精度乘法
输入：两行，每行表示一个非负整数（不超过10000位）
输出：两数的乘积。
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

#define MAX 10001

int high_precision(int *sum, int *a, int *b, int a_len, int b_len) {
    int i, j;
    memset(sum, 0, sizeof(sum));
    int sum_len = 0 ;

    for(i = 1; i <= a_len; i++) /*用数组模拟运算*/
        for(j = 1, sum_len = i - 1; j <= b_len; j++)
            sum[++sum_len] += b[j] * a[i];

    for(i = 1; i <= sum_len; i++) /*进位处理*/
        if(sum[i] >= 10) {
            if(sum[sum_len] >= 10)
                sum_len++;

            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
        }

    return sum_len;
}

void multiply(char* a, char* b, char* c) {
    int i, j, ca, cb, * s;
    ca = strlen(a);
    cb = strlen(b);
    s = (int*)malloc(sizeof(int) * (ca + cb));

    for(i = 0; i < ca + cb; i++)
        s[i] = 0;

    for(i = 0; i < ca; i++)
        for(j = 0; j < cb; j++)
            s[i + j + 1] += (a[i] - '0') * (b[j] - '0');

    for(i = ca + cb - 1; i >= 0; i--)
        if(s[i] >= 10) {
            s[i - 1] += s[i] / 10;
            s[i] %= 10;
        }

    i = 0;

    while(s[i] == 0)
        i++;

    for(j = 0; i < ca + cb; i++, j++)
        c[j] = s[i] + '0';

    c[j] = '\0';
    free(s);
}

int main(int argc, char *argv[]) {
    int a[MAX] = {0}, b[MAX] = {0}, sum[MAX * 2] = {0};
    int a_len = 0, b_len = 0, sum_len = 0;
    int i, j;
    char c_a[MAX], c_b[MAX], c_sum[MAX * 2];

    scanf("%s%s", c_a, c_b);

    a_len = strlen(c_a);
    b_len = strlen(c_b);

    for(i = 1, j = a_len - 1; i <= a_len; i++, j--)
        a[i] = c_a[j] - '0';

    for(i = 1, j = b_len - 1; i <= b_len; i++, j--)
        b[i] = c_b[j] - '0';

    sum_len = high_precision(sum, a, b, a_len, b_len) ;

    multiply(c_a, c_b, c_sum);
    printf("%s\n", c_sum);

    return 0 ;
}
