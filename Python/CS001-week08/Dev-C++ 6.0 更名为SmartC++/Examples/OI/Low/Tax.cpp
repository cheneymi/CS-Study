#include <stdio.h>

double sal2tax(double salary) {
    salary -= 2000;
    double tax = 0;
    double sal[][2] = {
        {0, 0.05},
        {500, 0.1},
        {2000, 0.15},
        {5000, 0.2},
        {20000, 0.25},
        {40000, 0.3},
        {60000, 0.35},
        {80000, 0.4},
        {100000, 0.45}
    };

    for(int i = 0; i < 8; ++i) {
        if(salary < sal[i][0])break;

        double t = ((salary - sal[i][0]) > (sal[i + 1][0] - sal[i][0]) ?
                    (sal[i + 1][0] - sal[i][0]) : (salary - sal[i][0])) * sal[i][1];
        tax += t;
    }

    return tax;
}

double tax2sal(double tax) {
    double sal_h = 80000;
    double sal_l = 0;

    while(sal_h > sal_l) {
        double mid = sal_h + sal_l;
        mid /= 2;

        if(sal2tax(mid) > tax) {
            sal_h = mid - 1;
        } else if(sal2tax(mid) < tax) {
            sal_l = mid + 1;
        } else {
            sal_l = mid;
            break;
        }
    }

    return sal_l;
}

int main() {
    double salary;

    while(1) {
        printf("---------------------\n"
               "1. from salary to tax\n"
               "2. from tax to salary\n"
               "---------------------\n"
              );
        int c;

        do {
            scanf("%d", &c);
        } while(c != 1 && c != 2);

        if(c == 1) {
            fprintf(stderr, "salary = ");
            scanf("%lf", &salary);
            printf("%lf\n", sal2tax(salary));
        } else {
            fprintf(stderr, "tax = ");
            scanf("%lf", &salary);
            printf("%lf\n", tax2sal(salary));
        }
    }
}

