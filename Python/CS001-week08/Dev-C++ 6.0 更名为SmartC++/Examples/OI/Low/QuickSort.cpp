#include <cstdio>
#include <algorithm>
using namespace std;
int array[20000];
int main(void) {
	int n;
	printf("Input N: (must < 20000)");
	scanf("%d", &n);
	printf("Input array: \n");
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &array[i]);
	}
	sort(array + 1, array + n + 1);
	printf("Arranged: \n");
	for (int i = 1; i <= n; ++ i) {
		printf("%d ", array[i]);
	}
	return 0;
}
