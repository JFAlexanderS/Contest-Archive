//http://hsin.hr/coci/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct path
{
	long long t, super;
	double perc;
}inp;

long long p1, p2, super, nodes, l, r, m, sinp;
long long satis[1005];
double perc;
double totes=-1;
bool plaus;

vector<path> nlist[1005];

void dfs(long long n, double food, long long p)
{
	if(satis[n]!=-1)
	{
		if(food<satis[n])
			plaus=false;
		return;
	}
	for(int i=0; i<nlist[n].size(); i++)
	{
		double sender=food;
		sender*=nlist[n][i].perc;
		if(nlist[n][i].super==1)
		{
			sender*=sender;
		}
		if(nlist[n][i].t!=p)
			dfs(nlist[n][i].t, sender, n);
	}
}

int main()
{
	scanf("%lld", &nodes);
	for(int i=1; i<nodes; i++)
	{
		scanf("%lld%lld%lf%lld", &p1, &p2, &perc, &sinp);
		inp.t=p2;
		inp.super=sinp;
		inp.perc=perc;
		inp.perc/=100;
		nlist[p1].push_back(inp);
		inp.t=p1;
		nlist[p2].push_back(inp);
	}
	for(int i=1; i<=nodes; i++)
		scanf("%lld", &satis[i]);
	l=0;
	r=2000000000;
	r*=10000;
	while(l<=r)
	{
		m=(l+r);
		m/=2;
		plaus=true;
		perc=m;
		perc/=10000;
		dfs(1, perc, 0);
		if(plaus)
		{
			r=m-1;
			totes=perc;
		}
		else
			l=m+1;
	}
	printf("%.3lf", totes);
}
