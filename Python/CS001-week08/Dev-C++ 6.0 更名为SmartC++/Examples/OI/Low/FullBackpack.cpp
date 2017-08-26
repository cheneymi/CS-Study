#include <cstdio>
int n, capacity, c[2000], v[2000], f[2000 * 2000];
/*
 * n：物品种类 每种只能选取一种
 * capacity：背包容量
 * c[i]：第i种物品的花费 cost
 * v[i]：第i种物品的价值 value
 * f[j]：i状态下容量为j时背包可获得的最大价值
 */
int max(int a, int b) {
    return a > b ? a : b;
}
int getMaxValue(int n, int capacity) {
    for(int i = 0; i < n; i++)
        for(int j = capacity; j >= 0; j--)
            if(i == 0) {
                if(j >= c[i])f[j] = v[i];
                else f[j] = 0;
            } else if(j >= c[i])f[j] = max(f[j], f[j - c[i]] + v[i]);

    return f[capacity];
}
int main(void) {
    printf("物品种类: ");
    scanf("%d", &n);
    printf("背包容量: ");
    scanf("%d", &capacity);

    for(int i = 1; i <= n; ++ i) {
        printf("第i种物品花费和价值: %d\n", i);
        scanf("%d %d", &c[i], &v[i]);
    }

    printf("最大价值: %d", getMaxValue(n, capacity));
    return 0;
}
