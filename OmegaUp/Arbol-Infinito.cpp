//https://omegaup.com/arena/problem/Arbol-Infinito

#include <cstdio> 

using namespace std; 

struct bign
{
	int d;
	int n[10005];
	void add();
	void copy();
} t, c, b, f;

void bign::add()
{
	for(int i=1; i<=c.d || i<=d; i++)
	{
		if(i<=c.d)
		{
			n[i]+=c.n[i];
		}
		while(n[i]>=100)
		{
			n[i+1]++, n[i]-=100;
			if(i+1>d)
				d++;
		}
	}
}

void bign::copy()
{
	for(int i=1; i<=d; i++)
		c.n[i]=n[i];
	c.d=d;
}

char inp[10005];

int main()
{
	t.d=1;
	b.d=1;
	b.n[1]=1;
	t.n[1]=1;
	scanf("%s", inp+1);
	for(int i=1; inp[i]; i++)
	{
		if(inp[i]=='I')
		{
			t.copy();
			t.add();	
		}
		if(inp[i]=='D')
		{
			t.copy();
			t.add();
			b.copy();
			t.add();
		}
		if(inp[i]=='*')
		{
			t.copy();
			t.add();
			t.add();
			t.add();
			t.add();
			b.copy();
			t.add();
			b.add();
			b.add();
		}		
	}
	for(int i=t.d; i; i--)
	{
		if(i==t.d)
			printf("%d", t.n[i]);
		else
			printf("%d%d", t.n[i]/10, t.n[i]%10);
	}
	printf("\n");
	return 0;
}
