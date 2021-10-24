#include <stdio.h>

typedef unsigned long long int ull;

int main()
{
	ull n;
	printf("Enter n value: ");
	scanf("%llu", &n);
	ull prime[n+1];
	for(ull i = (ull)1; i <= n; i++)
	{
		prime[i] = i;
	}
	for(ull i = (ull)2; i*i <= n; i++)
	{
		if(prime[i] != -1)
		{
			for(ull j = (ull)2*i; j <=n ; j += i)
				prime[j] = -1;
		}
	}
	printf("Prime numbers are: \n");
	for(ull i=(ull)2; i <= n; i++)
	{
		if(prime[i] != -1)
		{
			printf("%d ", i);
		}
	}
}