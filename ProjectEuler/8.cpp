#include <cstdio>
#include <algorithm>

using namespace std;

const long long MAXN=1000;

long long n=1, maxi;
char inp[MAXN+5];

int main()
{
    scanf("%s", inp);
    for(long long i=0; inp[i+12]; i++)
    {
        n=1;
        for(long long j=0; j<13; j++)
            n*=inp[i+j]-'0';
        maxi=max(maxi, n);
    }
    printf("%lld\n", maxi);
}
