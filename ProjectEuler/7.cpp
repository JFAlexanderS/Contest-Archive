#include <cstdio>

using namespace std;

const int MAXN=1000000;

int primeCount=0;
int notPrime[MAXN+5];

int main()
{
    for(int i=2; i<=MAXN; i++)
    {
        if(!notPrime[i])
        {
            primeCount++;
            if(primeCount==10001)
                printf("%d\n", i);
            for(int j=i+i; j<=MAXN; j+=i)
                notPrime[j]=1;
        }
    }
}
