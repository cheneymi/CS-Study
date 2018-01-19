#include<iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int x = 1, y = 1, dx = 1, dy = 1;
	int cnt = 0;
	while (cnt != 2) {
		cnt = 0;
		x = x + dx;
		y = y + dy;
		if (x == 1 || x == n) {
			++cnt;
			dx = -dx;
		}
		if (y == 1 || y == m) {
			++cnt;
			dy = -dy;
		}
	}
	cout << x << " " << y<< endl;
	return 0;
}

