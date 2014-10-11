//https://omegaup.com/arena/problem/El-Arreglo-de-Nieves

#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

struct inf
{
    int p, v;
};

int nums, totes, mint, stval;
int nlist[1000005], tol[1000005], tor[1000005], seen[1000005];

inf lastnp[1000005];

int main()
{
    scanf("%d", &nums);
    for(int i=1; i<=nums; i++)
        scanf("%d", &nlist[i]);
    for(int i=1; i<=nums; i++)
    {
        while(stval && lastnp[stval].v%nlist[i]==0)
            stval--;
        if(stval)
            tol[i]=lastnp[stval].p+1;
        else
            tol[i]=1;
        stval++;
        lastnp[stval]={i, nlist[i]};
    }
    stval=0;
    for(int i=nums; i; i--)
    {
        while(stval && lastnp[stval].v%nlist[i]==0)
            stval--;
        if(stval)
            tor[i]=lastnp[stval].p-1;
        else
            tor[i]=nums;
        stval++;
        lastnp[stval]={i, nlist[i]};
    }
    for(int i=1; i<=nums; i++)
    {
        if(tor[i]-tol[i]+1>tor[totes]-tol[totes]+1)
            totes=i;
    }
    for(int i=1; i<=nums; i++)
    {
        if(tor[i]-tol[i]+1==tor[totes]-tol[totes]+1 && !seen[tol[i]])
            seen[tol[i]]=1, mint++;
    }
    printf("%d %d\n", mint, tor[totes]-tol[totes]);
    for(int i=1; i<=nums; i++)
    {
        if(seen[i])
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}

