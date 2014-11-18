http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3971

#include <cstdio>

using namespace std;

struct node
{
	int val, height;
	int children[5];
};

int toI(char i)
{
	return i-'0';
}

node nlist[20000005];

int words, sz, totes;
char inp[205];

void add()
{
	for(int i=0, j=0; inp[i]; i++)
	{
		if(nlist[j].children[toI(inp[i])])
		{
			j=nlist[j].children[toI(inp[i])];
			nlist[j].val++;
			if(nlist[j].height*nlist[j].val>totes)
				totes=nlist[j].height*nlist[j].val;
		}
		else
		{
			nlist[sz+1].height=nlist[j].height+1;
			nlist[j].children[toI(inp[i])]=++sz;
			j=sz;
			nlist[j].val=1;
			if(nlist[j].height*nlist[j].val>totes)
				totes=nlist[j].height*nlist[j].val;
		}
	}
}

int main()
{
	scanf("%d", &words);
	for(int i=1; i<=words; i++)
	{
		scanf("%s", inp);
		add();
	}
	printf("%d\n", totes);
}
