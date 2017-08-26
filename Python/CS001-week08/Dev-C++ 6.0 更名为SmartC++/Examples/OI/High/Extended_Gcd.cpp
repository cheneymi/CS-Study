//Extended_gcd

# include <cstdio>
# include <cstdlib>
int a, b, d, x ,y;
int ext_gcd(int a, int b)
{
	int y1;
	if ( b == 0 )
	{
		x = 1; y = 0;
		return a;
	}
	else
	{
		d = ext_gcd(b, a%b);
		y1 = y;
		y = x - (a/b)*y;
		y = y1;
	}
	return d;
}
int main()
{
	scanf("%d%d", &a, &b);
	d = ext_gcd(a, b);
	printf("d = %d, x = %d, y = %d\n", d, x ,y);
	return 0;
}
