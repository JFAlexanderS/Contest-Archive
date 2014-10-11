//https://omegaup.com/arena/problem/Permutacion-Hermosa

#include <cstdio>
#include <iostream>

using namespace std;

int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    if(n==k)
        printf("-1");
    else
    {
        for(int i=1; i<=n-k; i++)
        {
            if(i!=n-k)
                printf("%d ", i+1);
            else
                printf("1 ");
        }
        for(int i=(n-k)+1; i<=n; i++)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}

