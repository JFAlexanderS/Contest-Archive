//https://omegaup.com/arena/problem/Lamparas-o-laseres#

#include <cstdio>

using namespace std;

int dims, totes, sof, cur;
int st[15][15];
char inp[15];
bool hp, vp;

void dfs(int r, int c)
{
	if(r==dims+1)
	{
		if(cur>totes)
			totes=cur, sof=1;
		else if(cur==totes)
			sof++;
		return;
	}
	if(c==dims)
		dfs(r+1, 1);
	else
		dfs(r, c+1);
	if(st[r][c]>=3)
		return;
	hp=true;
	for(int i=c; i && st[r][i]!=4; i--)
	{
		if(st[r][i]==1 || st[r][i]==2)
			hp=false;
	}
	for(int i=c; i<=dims && st[r][i]!=4; i++)
	{
		if(st[r][i]==1 || st[r][i]==2)
			hp=false;
	}
	if(hp)
	{
		st[r][c]=1;
		for(int i=c-1; i && st[r][i]!=4; i--)
			st[r][i]+=3;
		for(int i=c+1; i<=dims && st[r][i]!=4; i++)
			st[r][i]+=3;
		cur++;
		if(c==dims)
			dfs(r+1, 1);
		else
			dfs(r, c+1);
		cur--;
		for(int i=c-1; i && st[r][i]!=4; i--)
			st[r][i]-=3;
		for(int i=c+1; i<=dims && st[r][i]!=4; i++)
			st[r][i]-=3;
		st[r][c]=0;
	}
	//Not done with vertical
	vp=true;
	for(int i=r; i && st[i][c]!=4; i--)
	{
		if(st[i][c]==1 || st[i][c]==2)
			vp=false;
	}
	for(int i=r; i<=dims && st[i][c]!=4; i++)
	{
		if(st[i][c]==1 || st[i][c]==2)
			vp=false;
	}
	if(vp)
	{
		st[r][c]=2;
		for(int i=r-1; i && st[i][c]!=4; i--)
			st[i][c]+=3;
		for(int i=r+1; i<=dims && st[i][c]!=4; i++)
			st[i][c]+=3;
		cur++;
		if(c==dims)
			dfs(r+1, 1);
		else
			dfs(r, c+1);
		cur--;
		for(int i=r-1; i && st[i][c]!=4; i--)
			st[i][c]-=3;
		for(int i=r+1; i<=dims && st[i][c]!=4; i++)
			st[i][c]-=3;
		st[r][c]=0;
	}
}

int main()
{
	scanf("%d", &dims);
	for(int i=1; i<=dims; i++)
	{
		scanf("%s", inp+1);
		for(int j=1; j<=dims; j++)
		{
			if(inp[j]=='*')
				st[i][j]=4;
		}
	}
	dfs(1, 1);
	if(totes==0)
	{
		printf("%d %d\n", 0, 1);
		return 0;
	}
	printf("%d %d\n", totes, sof);
}
