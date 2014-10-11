//https://omegaup.com/arena/problem/Freddy-el-Humano#

#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

struct point
{
	int x, y;
};

int points, pa, dp[105][105][105], maxim, xs[3000005], tp;

point pbyx[105], pbyy[105], cler[105];

bool hp1(point i, point j)
{
	return i.x<j.x;
}

bool hp2(point i, point j)
{
    if(i.y!=j.y)
        return i.y<j.y;
    return i.x<j.x;
}

int dper(int x1, int x2, int y)
{
	if(pbyx[x2].x==pbyx[x1].x)
		return 1;
    //Not so sure about this one
	if(dp[x1][x2][y]!=-1)
		return dp[x1][x2][y];
	int m1=1000000, mint=1000000, newy=y, curh=pa/(pbyx[x2].x-pbyx[x1].x), nx1, nx2;
	for(int i=x1; i<x2; i++)
	{
		mint=dper(x1, i, y)+dper(i+1, x2, y);
		if(mint<m1)
			m1=mint;
	}
	for(newy=y; (pbyy[newy].y<=curh || pbyy[newy].x<pbyx[x1].x || pbyy[newy].x>pbyx[x2].x) && newy<=points; newy++){}
	for(nx1=x1; pbyx[nx1].y<=curh && nx1<=points; nx1++){}
	for(nx2=x2; pbyx[nx2].y<=curh && nx2; nx2--){}
    if(pbyx[nx2].x<pbyx[nx1].x && newy!=points+1)
    {
        //cout<<x1<<" "<<x2<<endl;
        //cout<<pbyx[x1].x<<" "<<pbyx[x2].x<<" "<<curh<<" "<<pbyy[newy].x<<" "<<pbyy[newy].y;
        //cout<<endl;
        //cout<<nx1<<" "<<nx2<<endl;
    }
	if(newy==y)
		dp[x1][x2][y]=100000;
	else if(newy==points+1)
		dp[x1][x2][y]=1;
	else
		dp[x1][x2][y]=dper(nx1, nx2, newy)+1;
    //printf("%d ", dp[x1][x2][y]);
	if(dp[x1][x2][y]>m1)
		dp[x1][x2][y]=m1;
    //printf("%d\n", m1);
	//printf("%d %d %d %d %d %d %d\n", nx1, nx2, newy, curh, x1, x2, y);
	return dp[x1][x2][y];
}

int main()
{
	scanf("%d%d", &points, &pa);
    if(points==0)
    {
        printf("0\n");
        return 0;
    }
	for(int i=0; i<=points; i++)
	{
		for(int j=0; j<=points; j++)
		{
			for(int k=0; k<=points; k++)
			{
				dp[i][j][k]=-1;
			}
		}
	}
	for(int i=1; i<=points; i++)
	{
		scanf("%d%d", &pbyx[i].x, &pbyx[i].y);
        if(pbyx[i].y>xs[pbyx[i].x])
            xs[pbyx[i].x]=pbyx[i].y;
	}
	sort(pbyx+1, pbyx+1+points, hp1);
    if(pbyx[points].x-1==pbyx[points-1].x)
        points--;
    for(int i=1; i<=points; i++)
    {
        if(pbyx[i].x==pbyx[i+1].x)
        {
            pbyx[i].y=xs[pbyx[i].x];
        }
        cler[i]=pbyx[i];
    }
    for(int i=1; i<=points; i++)
    {
        if(cler[i].x!=cler[i+1].x || cler[i].y!=cler[i+1].y)
        {
            tp++;
            pbyx[tp]=cler[i];
            pbyy[tp]=pbyx[i];
        }
    }
    points=tp;
    sort(pbyx+1, pbyx+1+points, hp1);
	sort(pbyy+1, pbyy+1+points, hp2);
	printf("%d\n", dper(1, points, 1));
	return 0;
}
