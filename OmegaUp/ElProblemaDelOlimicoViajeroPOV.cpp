//https://omegaup.com/arena/problem/ElProblemaDelOlimicoViajeroPOV

#include <cstdio>
#include <algorithm>
#include <string>
#include <stack> 
#include <iostream>
#include <vector>

using namespace std;

int cities, roads, n1, n2;
int perm[15], adj[15][15];
char inp[15];

string clist[15];
string totes, plau, emp;
vector<int> nlist[15];
stack<int> viser;

bool test()
{
	viser.push(perm[1]);
	for(int i=2; i<=cities; i++)
	{
		while(!viser.empty())
		{
			if(adj[viser.top()][perm[i]])
			{
				viser.push(perm[i]);
				break;
			}
			else
				viser.pop();
		}
		if(viser.empty())
			return false;
	}
	while(!viser.empty())
		viser.pop();
	return true; 
}

int main()
{
	scanf("%d%d", &cities, &roads);
	for(int i=1; i<=cities; i++)
	{
		perm[i]=i;
		scanf("%s", inp);
		clist[i]=inp;	
	}	
	for(int i=1; i<=roads; i++)
	{
		scanf("%d%d", &n1, &n2);
		adj[n1][n2]=1;
		adj[n2][n1]=1;
		nlist[n1].push_back(n2);
		nlist[n2].push_back(n1);
	}
	do
	{
		plau=emp;
		for(int i=1; i<=cities; i++)
			plau+=clist[perm[i]];
		if(plau<totes || totes.empty())
		{
			if(test())
				totes=plau;
		}
	}while(next_permutation(perm+1, perm+1+cities));
	cout<<totes<<"\n";
}
