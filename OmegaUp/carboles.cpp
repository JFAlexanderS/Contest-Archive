//https://omegaup.com/arena/problem/carboles#

#include <cstdio>
#include <iostream>

using namespace std;

const long long MOD=1000000;
long long dp[1005], dn[1005];
long long n;

long long f(long long n)
{
	if(n==1 || n==0)
		return 1;
	if(dn[n])
		return dp[n];
	for(int i=0; i<=n-1; i++) 
	{
		dp[n]+=f(i)*f((n-1)-i);
		dp[n]%=MOD;
	}
	dn[n]=1;
	return dp[n];
}

int main()
{
	cin>>n;
	cout<<f(n)<<"\n";
}
