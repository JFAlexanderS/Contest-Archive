//https://omegaup.com/arena/problem/Boggle

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; 

int dims=4, words, totes, mint;
int taken[15][15][105], points[20], done[105];
char board[15][15], inp[15];

vector<string> wlist(105);

void dfs(int);

void fitw(int r, int c, int w, int l)
{
	if(done[w] || c<1 || c>dims || r<1 || r>dims || taken[r][c][w] || board[r][c]!=wlist[w][l])
		return;
	taken[r][c][w]=1;
	if(l==wlist[w].size()-1)
	{
		totes+=points[wlist[w].size()];		
		dfs(w+1);
		done[w]=1;
	}
	for(int i=-1; i<=1; i++)
	{
		for(int j=-1; j<=1; j++)
		{
			if(i!=0 || j!=0)
			{
				fitw(r+i, c+j, w, l+1);
			}
		}
	}
	taken[r][c][w]=0;
}

void dfs(int w)
{
	if(w==words+1)
	{
		if(mint>totes)
			totes=mint;
		return;
	}
	for(int i=1; i<=4; i++)
	{
		for(int j=1; j<=4; j++)
		{
			fitw(i, j, w, 0);		
			if(done[w])
				return;	
		}
	}
	dfs(w+1);
}

int main()
{
	points[3]=1;
	points[4]=1;
	points[5]=2;
	points[6]=3;
	points[7]=5;
	for(int i=8; i<=16; i++)
		points[i]=11;
	for(int i=1; i<=dims; i++)
	{
		scanf("%s", inp+1);
		for(int j=1; j<=dims; j++)
			board[i][j]=inp[j];
	}
	scanf("%d", &words);
	for(int i=1; i<=words; i++)
	{
		scanf("%s", inp);
		wlist[i]=inp;
	}
	dfs(1);
	printf("%d\n", totes);
}
