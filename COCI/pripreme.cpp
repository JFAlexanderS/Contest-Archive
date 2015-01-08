//http://hsin.hr/coci/

#include <cstdio>
#include <algorithm>

using namespace std;

long long n, sum, big, inp, totes;

int main()
{
	scanf("%lld", &n);
	for(int i=1; i<=n; i++)
	{
		scanf("%lld", &inp);
		sum+=inp;
		big=max(big, inp);
	}
	totes=max(big*2, sum);
	printf("%lld\n", totes);
}
