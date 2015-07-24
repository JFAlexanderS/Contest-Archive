#include <cstdio>

using namespace std;

long long totes=1;

long long gcd(long long i, long long j)
{
    if(i==0)
        return j;
    return gcd(j%i, i);
}

int main()
{
    for(long long i=1; i<=20; i++)
        totes=(totes*i)/gcd(totes, i);
    printf("%lld\n", totes);
}
