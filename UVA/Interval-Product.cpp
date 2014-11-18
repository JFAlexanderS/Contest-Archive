//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3977

#include <cstdio>

using namespace std;

int n1, n2, n, k, r1, r2;
int bit[100005][15], val[100005];
char inp[15];

int gt(int i)
{
	if(i<0)
		return 1;
	else if(i==0)
		return 2;
	else
		return 3;
}

void upd(int i, int v, int t)
{
	while(i<=n)
	{
		bit[i][t]+=v;
		i+=i&-i;
	}
}

int csum(int i, int t)
{
	int rval=0;
	while(i)
	{
		rval+=bit[i][t];
		i-=i&-i;
	}
	return rval;
}

int main()
{
	while(scanf("%d", &n)!=EOF)
	{
		scanf("%d", &k);
		for(int i=1; i<=100000; i++)
			bit[i][1]=0, bit[i][2]=0, bit[i][3]=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &n1);
			upd(i, 1, gt(n1));
			val[i]=n1;
		}
		for(int i=1; i<=k; i++)
		{
			scanf("%s", inp);
			if(inp[0]=='C')
			{
				scanf("%d%d", &n1, &n2);
				upd(n1, -1, gt(val[n1]));
				upd(n1, 1, gt(n2));
				val[n1]=n2;
			}
			else
			{
				scanf("%d%d", &n1, &n2);
				if(csum(n2, 2)-csum(n1-1, 2))
					printf("0");
				else if((csum(n2, 1)-csum(n1-1, 1))%2==0)
					printf("+");
				else	
					printf("-");	
			}
		}
		printf("\n");
	}
}
