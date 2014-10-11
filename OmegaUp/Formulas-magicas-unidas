//https://omegaup.com/arena/problem/Formulas-magicas-unidas#

#include <cstdio>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

struct inf
{
	int s, n;
};

int nodes, f, ansn, ton, totes=100000000;
int adj[15][15], dp[5005][15];
string sauce[5005][15];
char inp[55];

string slist[15], appender;
inf n;
queue<inf> viser;

int main()
{
	scanf("%d", &nodes);
	for(int i=1; i<=nodes; i++)
	{
		scanf("%s", inp);
		slist[i]=inp;	
		f|=(1<<(i-1));
	}
	sort(slist+1, slist+1+nodes);
	for(int i=1; i<=nodes; i++)
	{
		for(int j=1; j<=5000; j++)
			dp[j][i]=10000000;
		viser.push({1<<(i-1), i});
		sauce[1<<(i-1)][i]=slist[i];
		dp[1<<(i-1)][i]=slist[i].size();
		for(int j=1; j<=nodes; j++)
		{
			adj[i][j]=slist[j].size();
			for(int f=0, k, fc; f<slist[i].size(); f++)
			{
				for(k=0, fc=f; k<slist[j].size() && fc<slist[i].size(); k++, fc++)
				{
					if(slist[j][k]!=slist[i][fc])
						break;
				}
				if(fc==slist[i].size())
					adj[i][j]=min(adj[i][j], int(slist[j].size()-k));
				else if(k==slist[j].size())
					adj[i][j]=0;
			} 
		}
	}
	while(!viser.empty())
	{
		n=viser.front();
		if(n.s==f && totes>dp[n.s][n.n] || (totes==dp[n.s][n.n] && sauce[n.s][n.n]<sauce[f][ansn]))
		{
			ansn=n.n;
			totes=dp[n.s][n.n];
		}
		viser.pop();
		for(int i=1; i<=nodes; i++)
		{
			if(adj[n.n][i]==0)
				ton=n.n;
			else
				ton=i;
			appender=sauce[n.s][n.n];
			appender.append(slist[i].begin()+(slist[i].size()-adj[n.n][i]), slist[i].end());
			if(dp[n.s|(1<<(i-1))][ton]==10000000)
				viser.push({n.s|(1<<(i-1)), ton});
			if(dp[n.s][n.n]+adj[n.n][i]<dp[n.s|(1<<(i-1))][ton] || (dp[n.s][n.n]+adj[n.n][i]==dp[n.s|(1<<(i-1))][ton] && appender<sauce[n.s|(1<<(i-1))][ton]))
			{
				dp[n.s|(1<<(i-1))][ton]=dp[n.s][n.n]+adj[n.n][i];
				sauce[n.s|(1<<(i-1))][ton]=appender;
			}
		}
	}
	cout<<sauce[f][ansn];
	printf("\n");
}
