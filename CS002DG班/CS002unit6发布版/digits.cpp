#include <iostream>
using namespace std;

int main()
{
	int n, a[20]; //����a����n�ĸ�λ���� 
	int l=0; //���ֳ��� 
	cin >> n;
	while (n) {  	 //��n����Ϊ1λ����ִ��ѭ�� 
		int r;
		r = n % 10;  //ȡ��λ���֣������� 
		a[l++] = r;
		n /= 10;  	 // n����һλ����
	}
	// �������n�ĸ�λ���� 
	for (int i=l-1; i >= 0; --i) {
		cout << a[i] << " ";
	}
	return 0;
}
