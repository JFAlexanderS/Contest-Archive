#include <cstdio>

const long long MAXN=2000000;

long long totes=0;
int notPrime[MAXN+5];

int main()
{
    for(long long i=2; i<=MAXN; i++)
    {
        if(!notPrime[i])
        {
            totes+=i;
            for(long long j=i+i; j<=MAXN; j+=i)
                notPrime[j]=1;
        }
    }
    printf("%lld\n", totes);
}
