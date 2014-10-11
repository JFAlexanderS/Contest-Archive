//https://omegaup.com/arena/problem/Highway-Trip#

#include <algorithm>
#include <cstdio>

using namespace std; 

long long mini, maxi, hotels;
long long dp[45], hlist[45];

int main()
{
	while(true)
	{
		scanf("%lld%lld%lld", &mini, &maxi, &hotels);
		if(mini==0 && maxi==0 && hotels==0)
			break; 
		for(int i=1; i<=hotels; i++)
			scanf("%lld", &hlist[i]), dp[i]=0;
		sort(hlist+1, hlist+1+hotels);
		dp[0]=1;
		for(int i=0; i<=hotels; i++)
		{
			for(int j=i+1; j<=hotels; j++)
			{
				if(hlist[j]-hlist[i]>=mini && hlist[j]-hlist[i]<=maxi)
					dp[j]+=dp[i];
			}
		}
		printf("%lld\n", dp[hotels]);
	}
	return 0;
}
