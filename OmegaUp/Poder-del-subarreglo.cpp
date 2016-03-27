#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const long long MAXN=200000, MAXV=1000000;

struct inf
{
  long long l, r, o, t;
};

long long nums, queries, sq, lC, rC, totes;
long long nList[MAXN+5], vCount[MAXV+5];

inf qList[MAXN+5];

bool hp(inf i, inf j)
{
  if(i.l/sq==j.l/sq)
    return i.r<j.r;
  return i.l/sq<j.l/sq;
}

bool hp2(inf i, inf j)
{
  return i.o<j.o;
}

void add(long long n)
{
  totes+=(vCount[n]*2+1)*n;
  vCount[n]++;
}

void remove(long long n)
{
  vCount[n]--;
  totes-=(vCount[n]*2+1)*n;
}

int main()
{
  scanf("%lld%lld", &nums, &queries);
  sq=sqrt(nums);
  for(int i=1; i<=nums; i++)
    scanf("%lld", &nList[i]);
  for(int i=1; i<=queries; i++)
  {
    scanf("%lld%lld", &qList[i].l, &qList[i].r);
    qList[i].o=i;
  }
  sort(qList+1, qList+1+queries, hp);
  lC=rC=1;
  totes=nList[1];
  vCount[nList[1]]=1;

  for(int i=1; i<=queries; i++)
  {
    while(rC<qList[i].r)
      add(nList[++rC]);
    while(lC>qList[i].l)
      add(nList[--lC]);

    while(rC>qList[i].r)
      remove(nList[rC--]);
    while(lC<qList[i].l)
      remove(nList[lC++]);

    qList[i].t=totes;
  }

  sort(qList+1, qList+1+queries, hp2);
  for(int i=1; i<=queries; i++)
    printf("%lld\n", qList[i].t);
}
