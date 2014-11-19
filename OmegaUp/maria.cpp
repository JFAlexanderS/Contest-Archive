//https://omegaup.com/arena/problem/maria#problems

#include <cstdio>

using namespace std;

struct inf
{
	long long i, v;
};

long long n, l[100005], r[100005], sz, nlist[100005], totes;
inf viser[100005];

int main()
{
	scanf("%lld", &n);
	for(long long i=1; i<=n; i++)
		scanf("%lld", &nlist[i]);
	viser[0]={0, 0};
	for(long long i=1; i<=n; i++)
	{
		while(viser[sz].v>nlist[i])
			sz--;
		l[i]=viser[sz].i;	
		viser[++sz]={i, nlist[i]};
	}
	sz=0;
	viser[0]={n+1, 0};
	for(long long i=n; i; i--)
	{
		while(viser[sz].v>nlist[i])
			sz--;
		r[i]=viser[sz].i;	
		viser[++sz]={i, nlist[i]};
	}
	for(long long i=1; i<=n; i++)
	{
		totes+=(i-l[i])*(r[i]-i)*nlist[i];
		//printf("%lld\n", (i-l[i])*(r[i]-i)*nlist[i]);
	}
	printf("%lld\n", totes);
}
