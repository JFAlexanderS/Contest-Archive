#include <cstdio>

const int MAXN=100;

int n1, n2;

int main()
{
    for(int i=1; i<=MAXN; i++)
        n1+=i*i, n2+=i;
    printf("%d\n", n2*n2-n1);
}
