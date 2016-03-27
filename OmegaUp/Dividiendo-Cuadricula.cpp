#include <iostream>
#include <cstdio>

using namespace std;

int cases, n, x, y;

int main()
{
    scanf("%d", &cases);
    for(int q=1; q<=cases; q++)
    {
        scanf("%d%d%d", &n, &x, &y);
        if((x==n/2 || x==n/2+1) && (y==n/2 || y==n/2+1))
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
