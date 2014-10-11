//https://omegaup.com/arena/problem/jarras

#include <stdio.h>
#include "jarras.h"

struct inf
{
	int j1, j2;
};

int c1, c2;
int seen[1005][1005];

inf sauce[1005][1005];

int minim(int i, int j)
{
	if(i<j)
		return i;
	return j;
}


int maxim(int i, int j)
{
	if(i>j)
		return i;
	return j;
}

void dfs(int a1, int a2)
{
	if(!seen[c1][a2])
	{
		seen[c1][a2]=1;
		sauce[c1][a2]={a1, a2};
		dfs(c1, a2);
	}
	if(!seen[a1][c2])
	{
		seen[a1][c2]=2;
		sauce[a1][c2]={a1, a2};
		dfs(a1, c2);
	}	
	if(!seen[0][a2])
	{
		seen[0][a2]=3;
		sauce[0][a2]={a1, a2};
		dfs(0, a2);
	}
	if(!seen[a1][0])
	{
		seen[a1][0]=4;
		sauce[a1][0]={a1, a2};
		dfs(a1, 0);
	}
	if(!seen[minim(a1+a2, c1)][maxim((a1+a2)-c1, 0)]) 
	{
		seen[minim(a1+a2, c1)][maxim((a1+a2)-c1, 0)]=5; 
		sauce[minim(a1+a2, c1)][maxim((a1+a2)-c1, 0)]={a1, a2}; 
		dfs(minim(a1+a2, c1), maxim((a1+a2)-c1, 0));
	}
	if(!seen[maxim((a1+a2)-c2, 0)][minim(a1+a2, c2)])
	{	
		seen[maxim((a1+a2)-c2, 0)][minim(a1+a2, c2)]=6; 
		sauce[maxim((a1+a2)-c2, 0)][minim(a1+a2, c2)]={a1, a2}; 
		dfs(maxim((a1+a2)-c2, 0), minim(a1+a2, c2));
	}
}

void dfs2(int a1, int a2)
{
	if(!a1 && !a2)
		return;
	dfs2(sauce[a1][a2].j1, sauce[a1][a2].j2);
	if(seen[a1][a2]==1)
		verterAgua(0, 1);		
	else if(seen[a1][a2]==2)
		verterAgua(0, 2);
	else if(seen[a1][a2]==3)
		verterAgua(1, 3);
	else if(seen[a1][a2]==4)
		verterAgua(2, 3);
	else if(seen[a1][a2]==5)
		verterAgua(2, 1);
	else if(seen[a1][a2]==6)
		verterAgua(1, 2);
}

void programa(int objetivo, int capacidadJarra1, int capacidadJarra2)
{
	c1=capacidadJarra1;
	c2=capacidadJarra2;
	dfs(0, 0);
	for(int i=0; i<=capacidadJarra2; i++)
	{
		if(seen[objetivo][i])
		{
			dfs2(objetivo, i);
			return;
		}
	}
	//(Fuente, Destino), 0=Llave, 3=Desague
}
