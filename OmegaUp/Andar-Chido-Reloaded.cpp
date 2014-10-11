//https://omegaup.com/arena/problem/Andar-Chido-Reloaded

#include <iostream>
#include <cstdio>
#include <algorithm>

struct chido
{
    long long t, b;
};

using namespace std;

bool hp(chido i, chido j)
{
    chido is, js;
    is.t=i.t*j.b;
    js.t=j.t*i.b;
    return is.t<js.t;
}

long long clients, mint, totes;
chido clist[100005];

int main()
{
    scanf("%lld", &clients);
    for(int i=1; i<=clients; i++)
        scanf("%lld%lld", &clist[i].t, &clist[i].b), clist[i].t*=2, mint+=clist[i].b;
    sort(clist+1, clist+clients+1, hp);
    for(int i=1; i<=clients; i++)
        mint-=clist[i].b, totes+=mint*clist[i].t;
    printf("%lld\n", totes);
    return 0;
}
