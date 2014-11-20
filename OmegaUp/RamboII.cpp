#include <algorithm>
#include <cstdio>

using namespace std;

struct inf
{
	int v, l, c;
};

int n1, totes, ind, n, k, d, m, ll;
int vlist[1000005], done[1000005];

inf ilist[1000005];

int main()
{
	scanf("%d%d%d%d", &n, &d, &k, &m);
	for(int i=1; i<=k; i++)
	{
		scanf("%d", &n1);
		vlist[n1]=1;
	}
	for(int q=0; q<n; q++)
	{
		for(int i=q, f=0; i!=q || !f; f++)
		{
			if(ilist[i].c)
				break;
			ll=i-d;
			if(ll<0)
				ll+=n;
			if(!ilist[ll].c)
			{
				for(int j=i, k=1; k<=m; j+=d, k++)
				{
					j=j%n;
					ilist[i].l=j;
					if(done[j]!=i+1)
					{
						ilist[i].v+=vlist[j];
						done[j]=i+1;
					}		
					else
					{
						ilist[i].l=j-d;
						if(ilist[i].l<0)
							ilist[i].l+=n;
						break;
					}
				}
			}
			else
			{
				ilist[i].v=ilist[ll].v-vlist[ll]+vlist[(ilist[ll].l+d)%n];
				ilist[i].l=(ilist[ll].l+d)%n;
			}
			ilist[i].c=1;
			i+=d;
			i%=n;
		}
	}
	for(int i=0; i<n; i++)
	{
		if(totes<ilist[i].v || (totes==ilist[i].v && ind>i))
			ind=i, totes=ilist[i].v;
	}
	printf("%d %d\n", totes, ind);
}
