/*
*费马小定理的应用，求质数
*Miller-Rabin算法
*2008 12 27
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int Btest(int a, int n) {
    int s = 0;
    int t = n - 1;
    int i , j , k;
    int x = 1;
    int y;
    i = 1;

    do {
        s++;
        t = t / 2;
    } while((t % 2) != 1);

    while(i <= t) {
        x = (x * a) % n;
        i++;
    }

    if((x == 1) || (x == n - 1))
        return 1;

    for(j = 1 ; j <= s - 1 ; j++) {
        y = 1;

        for(k = 1 ; k <= j ; k++) {
            y = 2 * y;
        }

        i = 1;
        x = 1;

        while(i <= (y * t)) {
            x = (x * a) % n;
            i++;
        }

        if(x == n - 1)
            return 1;
    }

    return 0;
}

int MillRab(int n) {
    int a;
    /*利用时间作为随机种子产生随机数*/
    srand(time(NULL));
    a = rand() % (n - 3) + 2;
    return Btest(a, n);
}

int MillerRabin(int n, int k) {
    int i;

    for(i = 1; i <= k; i++) {
        if(MillRab(n) == 0)return 0;
    }

    return 1;
}


int main() { /*费马小定理的应用*/
    int i;
    int n = 10000; /*定义测试范围*/
    int count = 0;
    printf("2 3 ");/*先输出2跟3*/

    for(i = 5; i <= n;) { /*从5开始循环判断*/
        if(MillerRabin(i , (int)log10(i))) { /*符合条件？*/
            printf("%d ", i);
            count++;
        }

        i = i + 2;
    }

    printf("\nthere %d prime(s)\n", count);
    return 0;
}
