#include <stdio.h>
#include <string.h>
char a[100001], b[100001];
int c[100001], d[100001];
int main(void) {
    int i, j;
    int la, lb, l;

    scanf("%s%s", a, b);
    la = strlen(a);
    lb = strlen(b);
    l = la > lb ? la : lb;
    j = 0;

    for(i = la - 1; i >= 0; i--) {
        c[j] = a[i] - '0';
        j++;
    }

    j = 0;

    for(i = lb - 1; i >= 0; i--) {
        d[j] = b[i] - '0';
        j++;
    }

    for(i = 0; i < l; i++) {
        c[i] = c[i] + d[i];

        if(c[i] >= 10) {
            c[i] = c[i] - 10;

            if(i < l - 1)
                c[i + 1]++;
            else
                printf("1");

        }
    }

    for(i = l - 1; i >= 0; i--)
        printf("%d", c[i]);

    printf("\n");
    return 0;
}

