#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const long long MAXN=600851475143, SQRT=775147;

int notPrime[SQRT+5];
long long totes=1, N=MAXN;

vector<long long> primes;

int main()
{
    for(int i=2; i<=SQRT; i++)
    {
        if(!notPrime[i])
        {
            primes.push_back(i);
            for(int j=i+i; j<=SQRT; j+=i)
                notPrime[j]=1;
        }
    }

    for(int i=0; i<primes.size(); i++)
    {
        while(N%primes[i]==0)
        {
            totes=max(totes, primes[i]);
            N/=primes[i];
        }
    }
    totes=max(totes, N);
    printf("%lld\n", totes);
}
