//https://omegaup.com/arena/problem/Final-Cubico

#include <cstdio>
#include <iostream> 

using namespace std;

unsigned long long fin, digis, done, totes, ten=10, minn;
unsigned long long pows[25];

unsigned long long thr(unsigned long long n, unsigned long long m)
{
	unsigned long long nc, rval=1, mint=0;
	for(int q=1; q<=3; q++)
	{
		minn=0;
		mint=0;
		nc=n;
		for(int i=0; nc; i++)
		{
			minn=rval*(nc%10);
			nc/=10;
			for(int j=0; j<i; j++)
			{
				minn*=10;
				minn%=pows[m];
			}
			mint+=minn;
			mint%=pows[m];	
		}
		rval=mint;
	}
	return rval/pows[m-1];
}

void dfs(unsigned long long n, unsigned long long s)
{
	unsigned long long nd;
	if(done)
		return;
	if(n==digis+1)
	{
		done=1;
		totes=s;
	}
	for(unsigned long long i=0; i<=9; i++)
	{
		nd=thr(i*pows[n-1]+s, n);
		if((fin%pows[n])/pows[n-1]==nd)
			dfs(n+1, i*pows[n-1]+s);
	}
}

int main()
{
	pows[0]=1;
	for(unsigned long long i=1; i<=20; i++)
		pows[i]=pows[i-1]*ten;
	cin>>fin;
	for(digis=1; pows[digis]<fin; digis++){}
	dfs(1, 0);
	cout<<totes;
}
