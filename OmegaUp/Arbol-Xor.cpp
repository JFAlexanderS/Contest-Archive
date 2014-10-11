//https://omegaup.com/arena/problem/Arbol-Xor#

#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

struct inf
{
	long long t, p;
};

const long long LOG=20;

long long nodes, queries, n1, n2, cost, p1, p2;
long long height[100005];

inf lca[100005][LOG+5]; 
vector<inf> nlist[100005];

void dfs(long long n, long long p, long long pd)
{
	height[n]=height[p]+1;
	lca[n][0].t=p;
	lca[n][0].p=pd;
	for(long long i=1; i<=LOG; i++)
	{
		lca[n][i].t=lca[lca[n][i-1].t][i-1].t;
		lca[n][i].p=lca[lca[n][i-1].t][i-1].p^lca[n][i-1].p;
	}
	for(long long i=0; i<nlist[n].size(); i++)
	{
		if(nlist[n][i].t!=p)
			dfs(nlist[n][i].t, n, nlist[n][i].p);
	}
}

long long query(long long n1, long long n2)
{
	p1=0, p2=0;
	if(height[n1]<height[n2])
	{
		n1+=n2;
		n2=n1-n2;
		n1-=n2;		
	}
	for(long long i=LOG; i>=0 && height[n1]>height[n2]; i--)
	{
		while(lca[n1][i].t && height[lca[n1][i].t]>=height[n2])
		{
			p1^=lca[n1][i].p;
			n1=lca[n1][i].t;
		} 
	}
	if(n1==n2)
		return p1^p2;
	for(long long i=LOG; i>=0; i--)
	{
		while(lca[n1][i].t!=lca[n2][i].t && lca[n1][i].t)
		{
			p1^=lca[n1][i].p;
			n1=lca[n1][i].t;
			p2^=lca[n2][i].p;
			n2=lca[n2][i].t;
		}
	}
	p1^=lca[n1][0].p;
	n1=lca[n1][0].t;
	p2^=lca[n2][0].p;
	n2=lca[n2][0].t;
	return p1^p2;
}

int main()
{
	scanf("%lld%lld", &nodes, &queries);
	for(long long i=1; i<nodes; i++)
	{
		scanf("%lld%lld%lld", &n1, &n2, &cost);
		nlist[n2].push_back({n1, cost});
		nlist[n1].push_back({n2, cost});
	}
	dfs(1, 0, 0);	
	for(long long i=1; i<=queries; i++)
	{
		scanf("%lld%lld", &n1, &n2);
		printf("%lld\n", query(n1, n2));
	}
}
