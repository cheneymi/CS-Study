#include <cstdio>
int n;
int lowbit(int t) {
    return t & (t ^ (t - 1));
}
int main(void) {
    scanf("%d", &n);
    printf("%d\n", lowbit(n));
    return 0;
}

