#include <cstdio>
#include <algorithm>

using namespace std;

struct inf
{
	int l, r, t, f;
};

const int MAXN=50000;

int nums, queries, typ, n1, n2;
int lazy[MAXN*8+5];

inf seg[MAXN*8+5];

//1=Empty, 2=Full

void init(int n, int l, int r)
{
	if(l>r)
		return;
	if(l==r)
	{
		seg[n].l=seg[n].r=seg[n].t=seg[n].f=1;
		return;
	}

	int m=(l+r)/2;
	init(n*2, l, m);
	init(n*2+1, m+1, r);
	seg[n].l=seg[n].r=seg[n].t=seg[n*2].t+seg[n*2+1].t;
	seg[n].f=1;
}

void updPos(int n)
{
	seg[n].l=seg[n*2].l;
	if(seg[n*2].f)
		seg[n].l+=seg[n*2+1].l;

	seg[n].r=seg[n*2+1].r;
	if(seg[n*2+1].f)
		seg[n].r+=seg[n*2].r;

	seg[n].t=max(seg[n*2].t, seg[n*2+1].t);
	seg[n].t=max(seg[n].t, seg[n*2].r+seg[n*2+1].l);

	seg[n].f=seg[n*2].f&seg[n*2+1].f;
}

void lazyUpd(int n, int l, int r)
{
	if(l>r)
		return; 

	if(lazy[n]==1)
	{
		lazy[n*2]=lazy[n];
		lazy[n*2+1]=lazy[n];
		lazy[n]=0;
		
		seg[n].l=seg[n].r=seg[n].t=r-l+1;
		seg[n].f=1;
	}
	else if(lazy[n]==2)
	{
		lazy[n*2]=lazy[n];
		lazy[n*2+1]=lazy[n];
		lazy[n]=0;
		
		seg[n].l=seg[n].r=seg[n].t=0;
		seg[n].f=0;
	}
}

void upd(int n, int l, int r, int lq, int rq, int t)
{
	if(l>r || lq>rq)
		return;

	lazyUpd(n, l, r);

	if(l>rq || r<lq)
		return;

	if(l>=lq && r<=rq)
	{
		lazy[n]=t;
		lazyUpd(n, l, r);
		return;
	}

	int m=(l+r)/2;
	upd(n*2, l, m, lq, rq, t);
	upd(n*2+1, m+1, r, lq, rq, t);
	updPos(n);
}

int query(int n, int l, int r, int p)
{
	if(l>r)
		return -1;
	
	lazyUpd(n, l, r);

	if(seg[n].t<p)
		return -1;
	if(l==r)
		return l;

	//Check Left
	int m=(l+r)/2;
	int q1=query(n*2, l, m, p);
	if(q1!=-1)
		return q1;
	
	//Check Middle
	lazyUpd(n*2, l, m);
	lazyUpd(n*2+1, m+1, r);
	if(seg[n*2].r+seg[n*2+1].l>=p)
		return m-seg[n*2].r+1;

	//Check Right
	return query(n*2+1, m+1, r, p);
}

int main()
{
	scanf("%d%d", &nums, &queries);
	init(1, 1, nums);
	for(int q=1; q<=queries; q++)
	{
		scanf("%d", &typ);
		if(typ==1)
		{
			scanf("%d", &n1);
			int p=query(1, 1, nums, n1);
			if(p==-1)
				printf("0\n");
			else
			{
				printf("%d\n", p);
				upd(1, 1, nums, p, p+n1-1, 2);
			}
		}
		else
		{
			scanf("%d%d", &n1, &n2);
			upd(1, 1, nums, n1, n1+n2-1, 1);
		}
	}
}
