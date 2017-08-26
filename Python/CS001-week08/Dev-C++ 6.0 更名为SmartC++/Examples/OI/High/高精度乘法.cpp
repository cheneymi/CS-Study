# include <cstdio>
# include <cstdlib>
# include <cstring>
const int MOD = 10000;
struct BigNum
{
	int len, num[103];
	BigNum()
	{
		len = 1;
		memset(num, 0, sizeof(num));
	}
};
BigNum a, b, c;
char str[10003];

BigNum operator * (BigNum a, BigNum b)
{
	int i, j, len = a.len+b.len;
	BigNum c;
	for(i = 1; i <= a.len; i++ )
	{
		for(j = 1; j <= b.len; j++ )
			c.num[i+j-1] += a.num[i]*b.num[j];
		for(j = 1; j <= len; j++ )
			if( c.num[j] > MOD )
			{
				c.num[j+1] += c.num[j]/MOD;
				c.num[j] % MOD;
			}
	}
	c.len = len;
	if( c.num[c.len] == 0 ) c.len--;
	return c;
}

int main()
{
	int i, j, lenth;
	int tmp = 0;
	/*
	gets(str+1);
	lenth = strlen(str+1);
	for(i = 1; i <= lenth; i++ )
	{
		a = a * 10;
		a = a + str[i];
	}
	*/
	a.num[1] = a.num[2] = a.num[3] = 1;
	a.len = 3;
	b.num[1] = b.num[2] = b.num[3] = 1;
	b.len = 3;
	c = a * b;
	printf("c.len = %d\n",c.len);
	for(i = c.len; i; i-- )
		if( i == c.len ) printf("%d",c.num[i]);
		else printf("%04d",c.num[i]);
	return 0;
}
