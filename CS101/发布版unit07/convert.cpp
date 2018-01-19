#include<iostream>
using namespace std;

void convert(int n, int base)
{
    char digit;
    if(n) {
        convert(n / base, base);
        digit = n % base;
        if(digit >= 10)
            digit = 'A' + digit - 10;
        else
            digit += '0';
        cout<<digit;
    }
}

int main() {
    int n,b;
    cin>>n>>b;
	convert(n, b);
    return 0;
}
