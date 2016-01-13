#include <cstdio>
#include <algorithm>

using namespace std;

const long long MAXB=100000;

long long cases, boxes, price, totes;
long long cSum[MAXB+5];

int main()
{
    scanf("%lld", &cases);
    for(int q=1; q<=cases; q++)
    {
        scanf("%lld%lld", &boxes, &price);
        for(int i=1; i<=boxes; i++)
        {
            scanf("%lld", &cSum[i]);
            cSum[i]+=cSum[i-1];
        }
        totes=0;
        cSum[boxes+1]=1000000000000000000;

        for(int i=1; i<=boxes; i++)
            totes+=upper_bound(cSum+i, cSum+1+boxes, price+cSum[i-1])-cSum-i;

        printf("Case #%d: %lld\n", q, totes);
    }
}
