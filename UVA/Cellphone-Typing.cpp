http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3971

#include <string>
#include <cstdio>

using namespace std;

struct node
{
    int val, ccount;
    int children[30];
}base;

int toI(char i)
{
    return i-'a';
}

node nlist[500005];

int words, sz;
char inp[205];
double totes;

string slist[100005];

void add()
{
    for(int i=0, j=0; inp[i]; i++)
    {
        if(nlist[j].children[toI(inp[i])])
        {
            j=nlist[j].children[toI(inp[i])];
        }
        else
        {
            nlist[j].children[toI(inp[i])]=++sz;
	    nlist[j].ccount++;
            j=sz;
        }
    }
}

void trav(int n)
{
    //printf("%lf ", totes);
    for(int i=0, j=0; i<slist[n].size()-1; i++)
    {
	 if(nlist[j].ccount>1 || j==0)
		totes+=1;
         j=nlist[j].children[toI(slist[n][i])];
    }
    //printf("%lf\n", totes);
}

int main()
{
    while(scanf("%d", &words)!=EOF)
    {
    for(int i=0; i<=500000; i++)
	nlist[i]=base;
    sz=0;
    totes=0;
    for(int i=1; i<=words; i++)
    {
        scanf("%s", inp);
	for(int k=0; inp[k]; k++)
	{
		if(inp[k+1]==0)
		{
			inp[k+1]='z'+1;
			inp[k+2]=0;
			break;
		}
	}
	slist[i]=inp;
        add();
    }
    for(int i=1; i<=words; i++)
    {
	trav(i);
    }
    totes/=(double) words;
    printf("%.2lf\n", totes);
    }
}
