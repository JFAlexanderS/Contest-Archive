#include <cstdio>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<long long, long long> viser;

long long n, d, k, totes, n1, ind, gc;

int main()
{
	scanf("%lld%lld%lld", &n, &d, &k);
	d=__gcd(d, n);
	for(int i=1; i<=k; i++)
	{
		scanf("%lld", &n1);
		if(viser.find(n1%d)==viser.end())
			viser[n1%d]=1;
		else
			viser[n1%d]++;
		if(totes<viser[n1%d] || (totes==viser[n1%d] && n1%d<ind))
			ind=n1%d, totes=max(totes, viser[n1%d]);
	}
	printf("%lld %lld\n", totes, ind);
}
