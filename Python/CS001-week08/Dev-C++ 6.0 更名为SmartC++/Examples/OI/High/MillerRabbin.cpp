
# include <cstdio>
# include <cstdlib>
# include <cstring>

typedef long long lg;
lg power(lg a,int d,lg n)
{
	if( d == 0 ) return 1;
	if( d == 1 ) return a;
	else if( d&1 ) return ( (power( (a*a)%n, d/2, n)*a)%n );
	else return ( (power((a*a)%n, d/2, n)%n) );
}

bool test(int x,int flag)
{
    if((!(x&1))&&(x!=2))return false;
    if(x<2)return false;
    //if(x==flag || x== 2|| x == 3 || x == 5 || x == 7)return true;
    if( x == flag ) return true;
	int d=x-1;
    while( !(d&1) )
		d>>=1;
	lg t = power(flag%x,d,x);
    while( (d!=x-1) && (t!=1) && (t!=x-1) )
    {
        d <<= 1;
        t = (t*t)%x;
    }
    return (t==x-1)||(d&1);
}

int main()
{
	int a;
	bool ok;
	printf("Begin\n");
	for(int i = 1; i <= 100; i++ )
	{
		ok = true;
		for(int j = 1; j <= 3; j++ )
		{
			if( j == 1 ) a = 2;
			if( j == 2 ) a = 7;
			if( j == 3 ) a = 61;
			if( test(i, a) == false ) ok = false;
		}
		if( ok ) printf("%d\n", i);
	}
	printf("Done\n");
	scanf("%d", &a);
	return 0;
}
