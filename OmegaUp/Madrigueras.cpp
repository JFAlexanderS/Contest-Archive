//https://omegaup.com/arena/problem/Madrigueras

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

long long nodes, paths, n1, n2;
long long parent[100005];

long long totes=1, mod=1000000007, cursz, cura;

vector<long long> nlist[100005];

long long uni(long long n)
{
    cursz++;
    bool other=false;
    for(int i=0; i<nlist[n].size(); i++)
    {
        cura++;
        if(!parent[nlist[n][i]])
            parent[nlist[n][i]]=n, uni(nlist[n][i]);
        else
        {
            if(parent[n]!=nlist[n][i])
                other=true;
        }
    }
    if(other)
        return 2;
    return 1;
}

int main()
{
    scanf("%lld%lld", &nodes, &paths);
    for(int i=1; i<=paths; i++)
    {
        scanf("%lld%lld", &n1, &n2);
        nlist[n1].push_back(n2);
        nlist[n2].push_back(n1);
    }
    for(int i=1; i<=nodes; i++)
    {
        if(!parent[i])
        {
            parent[i]=nodes+1;
            cursz=0;
            cura=0;
            if(uni(i)==1)
                totes*=cursz;
            else
                totes*=2;
            if(cura/2>cursz)
            {
                printf("0\n");
                return 0;
            }
            totes%=mod;
        }
    }
    printf("%lld\n", totes);
    return 0;
}

