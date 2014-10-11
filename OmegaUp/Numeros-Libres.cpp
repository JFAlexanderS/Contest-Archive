//https://omegaup.com/arena/problem/Numeros-Libres

#include <cstdio>
#include <algorithm>

using namespace std; 

long long a, b;
int cases; 

int main()
{
	scanf("%d", &cases);
	for(int i=1; i<=cases; i++)
	{
		scanf("%lld%lld", &a, &b);
		if(__gcd(a, b)==1)
			printf("SI\n"); 
		else
			printf("NO\n");
	}
}
