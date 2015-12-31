#include <cstdio>

using namespace std;

int n;
char inp[15];

int main()
{
    scanf("%d%s%s", &n, inp, inp);
    if(inp[0]=='w')
    {
        if(n==1 || n==2 || n==3 || n==4 || n==7)
            printf("%d\n", 52);
        else
            printf("%d\n", 53);
    }
    else
    {
        if(n<=29)
            printf("%d\n", 12);
        else if(n<=30)
            printf("%d\n", 11);
        else
            printf("%d\n", 7);
    }
}
