#include <cstdio>
#include <algorithm>

using namespace std;

const long long MAXN=90000, PRIME=3507241, MOD=1000000007;

struct hashTable
{
  char c[MAXN+5];
  long long h[MAXN+5];
} s[2];

int chars;
long long pows[MAXN+5];
char inp[MAXN+5], res[MAXN+5];

void mod(long long &i)
{
    i%=MOD;
    i+=MOD;
    i%=MOD;
}

long long hasher(int l, int r, int t)
{
	long long v;
  v=s[t].h[r];
  v-=s[t].h[l-1];
	mod(v);
	return v;
}

int comp(int p1, int p2)
{
	int k=-1;
	for(int l=0, r=min(chars-p1-1, chars-p2-1), m; l<=r; )
	{
		m=(l+r)/2;

		long long r1=hasher(p1, p1+m, 0);
		long long r2=hasher(p2, p2+m, 1);
		if(p1>p2)
		{
			r1*=pows[p1-p2];
			mod(r1);
		}
		else
		{
			r2*=pows[p2-p1];
			mod(r2);
		}

		if(r1!=r2)
			k=m, r=m-1;
		else
			l=m+1;
	}

	if(k==-1)
		return p1>p2;

	return s[0].c[p1+k]>=s[1].c[p2+k];
}

int main()
{
	scanf("%d", &chars);

	pows[0]=1;
	for(int i=1; i<chars; i++)
	{
		pows[i]=pows[i-1]*PRIME;
		mod(pows[i]);
	}

	for(int i=0; i<chars; i++)
	{
		scanf("%s", inp);
		s[0].c[i]=inp[0];
		s[1].c[chars-i-1]=inp[0];
	}

	for(int i=0, j=chars-1; i<chars; i++, j--)
	{
    for(int k=0; k<2; k++)
    {
      if(i)
        s[k].h[i]=s[k].h[i-1];
      s[k].h[i]+=pows[j]*s[k].c[i];
      mod(s[k].h[i]);
    }
	}

	for(int p1=0, p2=0, i=0; p1+p2<chars; )
	{
		if(comp(p1, p2)<=0)
			res[i++]=s[0].c[p1++];
		else if(comp(p1, p2)>0)
			res[i++]=s[1].c[p2++];
	}

	for(int i=0, j=1; i<chars; i++, j++)
	{
		printf("%c", res[i]);
		if(!(j%80))
			printf("\n");
	}
	printf("\n");
}
