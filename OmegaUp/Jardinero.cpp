//https://omegaup.com/arena/problem/Jardinero

#include <cstdio>
#include <queue>
#include <cmath>
#include <iostream> 

using namespace std; 

struct safe
{
	int r, c, t;
};

struct coord
{
	int r, c;
};

int rows, cols, totes, nm, bl, fl, fr, ba;
int adj[15][5], dist[15][15];

unsigned long long vis, O=1, sp;

safe slist[15];

coord viser[75];

bool testaround(int r, int c)
{
	if(r == 0 && c == 1 || (vis&(O<<(cols*(r)+c))) != 0 )
		return true; 
	int t = 0;
	if(!(r >= 0 && r < rows && c >= 0 && c < cols))
		return true;
	if(r-1 < 0 || (vis&(O<<(cols*(r-1)+c))) != 0)
		t++;
	if(r+1 == rows || (vis&(O<<(cols*(r+1)+c))) != 0)
		t++;
	if(c-1 < 0 || (vis&(O<<(cols*r+(c-1)))) != 0)
		t++;
	if(c+1 == cols || (vis&(O<<(cols*r+(c+1)))) != 0)
		t++;
	if(t >= 3)
		return false;
	return true;
}

bool time(int r, int c, int t)
{
	return true;
	for(int i=1; i<=4; i++)
	{
		if(slist[i].r==r && slist[i].c==c && slist[i].t!=t)
			return false;
	}
	return true;
}

bool reachable(int r, int c)
{
	int nr, nc;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
			dist[i][j]=100000000;
	}
	dist[r][c]=0;
	sp=vis;
	viser[1]={r, c};
	fr=1;
	ba=2;
	while(fr<ba)
	{
		r=viser[fr].r;
		c=viser[fr].c;
		fr++;
		for(int i = 0; i < 4; i++)
		{

			nr = r+adj[i][0];
			nc = c+adj[i][1];
			if(nr>=0 && nc>=0 && nr<rows && nc<cols && (sp&(O<<(cols*nr+nc))) == 0)
			{
				sp ^= (O<<(cols*nr+nc));
				dist[nr][nc]=dist[r][c]+1;
				viser[ba++]={nr, nc};
			} 

		}	
	}		
}

void dfs(int r, int c, int d, int b)
{
	if(d==nm)
	{
		totes++;
		return;
	}
	int nr, nc;
	bl=0;	
	for(int i = 0; i < 4; i++)
	{
		nr = r+adj[i][0];
		nc = c+adj[i][1];
		if(!testaround(nr, nc))
			bl++, fl=i;
	}
	if(bl > 1)
		return;	
	reachable(r, c);
	for(int i = b; i <= 4; i++)
	{
		if(dist[slist[i].r][slist[i].c] > slist[i].t-d)
			return;
	}

	if(bl == 1)
	{
		nr = r+adj[fl][0];
		nc = c+adj[fl][1];
		if(nr>=0 && nc>=0 && nr<rows && nc<cols && (vis&(O<<(cols*nr+nc))) == 0) 
		{
			vis ^= (O<<(cols*nr+nc));
			if(d == slist[b].t)
				dfs(nr, nc, d+1, b+1);
			else 
				dfs(nr, nc, d+1, b);
			vis ^= (O<<(cols*nr+nc));
		}
		return;
	}
	for(int i = 0; i < 4; i++)
	{
		nr = r+adj[i][0];
		nc = c+adj[i][1];
		if(nr>=0 && nc>=0 && nr<rows && nc<cols && (vis&(O<<(cols*nr+nc))) == 0)
		{
			vis ^= (O<<(cols*nr+nc));
			if(d == slist[b].t)
				dfs(nr, nc, d+1, b+1);
			else 
				dfs(nr, nc, d+1, b);
			vis ^= (O<<(cols*nr+nc));
		} 
	}	
}

int main()
{
	adj[0][0] = 1;
	adj[1][0] = -1;
	adj[2][1] = 1;
	adj[3][1] = -1;
	scanf("%d%d", &rows, &cols);
	nm = rows*cols;
	for(int i = 1; i <= 3; i++)
		scanf("%d%d", &slist[i].r, &slist[i].c), slist[i].t = (i*nm)/4;
	slist[4] = {0, 1, nm};
	vis|=1;
	dfs(0, 0, 1, 1);
	printf("%d\n", totes);	
}
