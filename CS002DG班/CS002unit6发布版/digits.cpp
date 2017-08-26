#include <iostream>
using namespace std;

int main()
{
	int n, a[20]; //数组a保存n的各位数字 
	int l=0; //数字长度 
	cin >> n;
	while (n) {  	 //当n至少为1位数，执行循环 
		int r;
		r = n % 10;  //取个位数字，并保存 
		a[l++] = r;
		n /= 10;  	 // n减少一位数字
	}
	// 依次输出n的各位数字 
	for (int i=l-1; i >= 0; --i) {
		cout << a[i] << " ";
	}
	return 0;
}
