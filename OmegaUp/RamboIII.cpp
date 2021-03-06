//https://omegaup.com/arena/IOI_2015_TN#problems/Rambo-III

#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

long long n, d, k, m, n1, gcv, ngroup, totes, cd, sres, cg1, cx1, cy1;

map<long long, long long> gdiv;

vector<long long> glist[10005], helper;

long long gcd(long long a, long long b, long long &x, long long &y)
{
	//ax+by=gcd(a, b)
	if(b==0)
	{
		x=1; 
		y=0;
		return a;
	}
	long long m=a/b, r=a%b, u, v, g;
    	g=gcd(b, r, u, v);
   	x=v;
   	y=u-(m*v);
    	return g;
	//Works for sure
}

void calc(long long i, long long j, long long &r1, long long &r2)
{	
	long long x1=cx1, y1=cy1;
	long long g1=cg1;	
	cd=n/g1;
	
	x1%=cd;
	while(x1<0)
		x1+=cd;

	x1*=(i-(i%g1))/g1;
	
	x1%=cd;

	if((x1*d+(i%g1))%n!=i)
		i/=0;


	long long x2=cx1, y2=cy1;
	long long g2=cg1;	
	
	x2%=cd;
	while(x2<0)
		x2+=n/g2;

	x2*=(j-(j%g1))/g2;
	
	x2%=cd;

	if((x2*d+(j%g1))%n!=j)
		i/=0;
	r1=x1;
	r2=x2;
}

long long sub(long long i, long long j)
{
	long long x1, x2;
	calc(i, j, x1, x2);
	return x1-x2;
}

bool hp(long long i, long long j)
{
	long long x1, x2;
	calc(i, j, x1, x2);
	return x1<x2;
}

int main()
{
	scanf("%lld%lld%lld%lld", &n, &d, &k, &m);
	cg1=gcd(d, n, cx1, cy1);
	gcv=__gcd(n, d);
	for(long long i=1; i<=k; i++)
	{
		scanf("%lld", &n1);
		if(gdiv.find(n1%gcv)==gdiv.end())
			gdiv[n1%gcv]=ngroup++;
		glist[gdiv[n1%gcv]].push_back(n1);
	}
	for(long long i=0; i<ngroup; i++)
		sort(glist[i].begin(), glist[i].end(), hp);
	/*for(long long i=0; i<ngroup; i++)
	{
		for(long long j=0; j<glist[i].size(); j++)
			printf("%lld ", glist[i][j]);
		printf("\n");
	}*/
	for(long long i=0; i<ngroup; i++)
	{
		helper=glist[i];
		helper.insert(helper.end(), glist[i].begin(), glist[i].end());
	/*	printf("Helper: ");
		for(int j=0; j<helper.size(); j++)
			printf("%lld ", helper[j]);
		cout<<endl;*/
		for(long long j=0; j<glist[i].size(); j++)
		{
			long long l, r, mi;
			l=j;
			r=j+glist[i].size()-1;
			while(l<=r)
			{
				mi=(l+r)/2;
				sres=sub(helper[mi], helper[j]);
				if(sres<0)
					sres+=n/gcv;
				if(sres<m)
					totes=max(totes, mi-j+1), l=mi+1;
				else
					r=mi-1;
			}
		}
	}
	if(m==0)
		totes=0;
	printf("%lld\n", totes);
}
