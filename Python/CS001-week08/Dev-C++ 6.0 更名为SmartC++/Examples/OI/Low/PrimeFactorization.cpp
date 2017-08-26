#include <cstdio>
int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d=", n);
	for (int i = 2; n > 1; ++ i){
		while (n % i == 0) {
			n /= i;
			printf("%d", i);
			if (n != 1) {
				printf("*");
			}
		}
	}
	printf("\n");
	return 0;
}

