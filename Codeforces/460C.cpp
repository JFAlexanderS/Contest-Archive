//http://codeforces.com/contest/460/problem/C

#include <cstdio>

using namespace std;

long long plants, days, water, l, r, m, lft, totes;
long long plist[100005], bit[200005];

long long csum(long long p)
{
    long long rval=0;
    while(p)
    {
        rval+=bit[p];
        p-=p&-p;
    }
    return rval;
}

void upd(long long p, long long v)
{
    while(p<=plants*2)
    {
        bit[p]+=v;
        p+=p&-p;
    }
}

bool test(long long m)
{
    long long mint=0;
    for(long long i=1; i<=plants*2; i++)
        bit[i]=0;
    for(long long i=1; i<=plants; i++)
    {
        lft=m-(plist[i]+(csum(i)));
        if(lft>0)
        {
            upd(i, lft);
            upd(i+water, -lft);
            mint+=lft;
        }
    }
    return (mint<=days); 
}

int main()
{
    scanf("%lld%lld%lld", &plants, &days, &water);
    for(long long i=1; i<=plants; i++)
        scanf("%lld", &plist[i]);
    l=1;
    r=1500000000;
    while(l<=r)
    {
        m=(l+r)/2;
        if(test(m))
        {
            l=m+1;
            totes=m;
        }
        else 
            r=m-1;
    }
    printf("%lld\n", totes);
}
