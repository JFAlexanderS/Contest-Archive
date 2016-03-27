#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN=100000;

int nums;
int nList[MAXN+5], cList[MAXN+5];

map<int, int> cost;

void tryAdd(int n, int c)
{
	if(cost.find(n)==cost.end())
		cost[n]=c;
	else if(cost[n]>c)
		cost[n]=c;
}

int main()
{
	scanf("%d", &nums);
	for(int i=1; i<=nums; i++)
		scanf("%d", &nList[i]);
	for(int i=1; i<=nums; i++)
		scanf("%d", &cList[i]);
		
	for(int i=1; i<=nums; i++)
	{
		tryAdd(nList[i], cList[i]);
		for(auto j=cost.begin(); j!=cost.end(); j++)
			tryAdd(__gcd(nList[i], j->first), cList[i]+j->second); 
	}
	
	if(cost.find(1)==cost.end())
		printf("-1\n");
	else
		printf("%d\n", cost[1]);
}
