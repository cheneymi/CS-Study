#include <cstdio>
int n, capacity, c[2000], v[2000], f[2000 * 2000];
/*
 * n����Ʒ���� ÿ��ֻ��ѡȡһ��
 * capacity����������
 * c[i]����i����Ʒ�Ļ��� cost
 * v[i]����i����Ʒ�ļ�ֵ value
 * f[j]��i״̬������Ϊjʱ�����ɻ�õ�����ֵ
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
    printf("��Ʒ����: ");
    scanf("%d", &n);
    printf("��������: ");
    scanf("%d", &capacity);

    for(int i = 1; i <= n; ++ i) {
        printf("��i����Ʒ���Ѻͼ�ֵ: %d\n", i);
        scanf("%d %d", &c[i], &v[i]);
    }

    printf("����ֵ: %d", getMaxValue(n, capacity));
    return 0;
}
