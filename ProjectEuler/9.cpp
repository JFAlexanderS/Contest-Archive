#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int a, b, c, d, s, n, m, k;

int main()
{
    scanf("%d", &s);
    for(int i=2; i<=sqrt(s/2); i++)
    {
        if((s/2)%i)
            continue;
        for(int j=i+(i%2 ? 2 : 1); j<2*i; j+=2)
        {
            if((s/(2*i))%j || __gcd(i, j)>1)
                continue;
            m=i;
            n=j-m;
            d=s/(2*m*j);
            a=(m*m-n*n)*d;
            b=2*m*n*d;
            c=(m*m+n*n)*d;
            printf("%d %d %d\n", a, b, c);
        }
    }
}
