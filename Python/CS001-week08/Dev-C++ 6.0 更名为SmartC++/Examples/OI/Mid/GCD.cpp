#include <cstdio>
int a, b;
int gcd(int a, int b) {
    if(b == 0) return a;

    return gcd(b , a % b);
}

int lcm(int a, int b) {
    return a / gcd(a , b) * b;
}
int main(void) {
    scanf("%d %d", &a, &b);
    printf("最大公约数: %d\n最小公倍数: %d\n", gcd(a, b), lcm(a, b));
    return 0;
}
