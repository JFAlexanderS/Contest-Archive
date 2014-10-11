//https://omegaup.com/arena/problem/Cuartetas

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long nums, n, gc, stop;
long long dp[1000005][15], link[1000005][15], olist[5005], rlist[5005], prime[1000005];
long long plist[1000005][15];

int main()
{
    scanf("%lld", &nums);
	for(long long i=1; i<=nums; i++)
		scanf("%lld", &olist[i]);
	for(long long i=2; i<=1000000; i++)
	{
		if(!prime[i])
		{
            plist[i][plist[i][13]++]=i;
			for(long long j=i*2; j<=1000000; j+=i)
			{
				prime[j]=1;
                plist[j][plist[j][13]++]=i;
			}
		}
	}

	for(long long i=1; i<=nums; i++)
	{
        rlist[i]=1;
        for(long long j=0; j<plist[olist[i]][13]; j++)
        {
            rlist[i]*=plist[olist[i]][j];
        }
	}

	sort(rlist+1, rlist+1+nums);

    link[1000003][1]=1;
    link[1000003][2]=1;
    link[1000003][3]=1;
    for(long long i=1; i<=nums; i++)
    {
        n=rlist[i];
        for(long long j=3; j; j--)
        {
            for(long long k=1; k<link[1000003][j]; k++)
            {
                gc=1;
                for(long long f=0, r=0; f<plist[n][13] && r<plist[link[k][j]][13]; )
                {
                    if(plist[n][f]<plist[link[k][j]][r])
                        f++;
                    else if(plist[n][f]>plist[link[k][j]][r])
                        r++;
                    else
                    {
                        gc*=plist[n][f];
                        f++;
                        r++;
                    }
                }
                if(!dp[gc][j+1] && j+1<4)
                {
                        link[link[1000003][j+1]++][j+1]=gc;
                }
                dp[gc][j+1]+=dp[link[k][j]][j];
            }
        }
        if(!dp[n][1])
        {
            link[link[1000003][1]++][1]=n;
        }
        dp[n][1]++;
    }
    printf("%lld\n", dp[1][4]);
    return 0;
}
