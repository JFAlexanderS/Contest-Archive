//https://omegaup.com/arena/problem/Freddy-Plano-Etereo

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct inf
{
    long long t, w;
};

struct djk
{
    long long n, v;
    bool operator > (const djk &i) const
    {
        return v<i.v;
    }
    bool operator < (const djk &i) const
    {
        return v>i.v;
    }
} n;

struct edge
{
    long long n1, n2, t;
    bool operator < (const edge &i) const
    {
        return t<i.t;
    }
};

long long nodes, edges, n1, n2, weight, nn, totes, p1, p2, ports;
long long isp[100005], cp[100005], pd[100005], rnk[100005], head[100005];

edge elist[100005];

vector<inf> nlist[100005];
priority_queue<djk> viser;

long long ufind(long long n)
{
    if(head[n]!=n)
        head[n]=ufind(head[n]);
    return head[n];
}

void uni(long long n1, long long n2)
{
    p1=ufind(n1);
    p2=ufind(n2);
    if(rnk[p1]>rnk[p2])
        head[p1]=p2;
    else if(rnk[p2]>rnk[p1])
        head[p2]=p1;
    else
        head[p1]=p2, rnk[p1]++;
}

int main()
{
    scanf("%lld%lld", &nodes, &edges);
    for(int i=1; i<=nodes; i++)
        pd[i]=-1, head[i]=i, rnk[i]=1;
    for(int i=1; i<=edges; i++)
    {
        scanf("%lld%lld%lld", &n1, &n2, &weight);
        nlist[n1].push_back({n2, weight});
        nlist[n2].push_back({n1, weight});
        elist[i]={n1, n2, weight};
    }
    scanf("%lld", &ports);
    for(int i=1; i<=ports; i++)
    {
        scanf("%lld", &n1);
        isp[n1]=1;
        viser.push({n1, 0});
        pd[n1]=0;
        cp[n1]=n1;
    }
    while(!viser.empty())
    {
        n=viser.top();
        viser.pop();
        if(pd[n.n]>n.v)
            continue;
        for(int i=0; i<nlist[n.n].size(); i++)
        {
            nn=nlist[n.n][i].t;
            if(pd[nn]==-1 || pd[nn]>nlist[n.n][i].w+pd[n.n])
            {
                pd[nn]=nlist[n.n][i].w+pd[n.n];
                cp[nn]=cp[n.n];
                viser.push({nn, pd[nn]});
            }
        }
    }
    for(int i=1; i<=edges; i++)
        elist[i].t+=pd[elist[i].n1]+pd[elist[i].n2];
    sort(elist+1, elist+1+edges);
    for(int i=1; i<=edges; i++)
    {
        //cout<<elist[i].n1<<" "<<elist[i].n2<<" "<<elist[i].t<<endl;
        if(ufind(cp[elist[i].n1])!=ufind(cp[elist[i].n2]))
        {
            uni(cp[elist[i].n1], cp[elist[i].n2]);
            totes+=elist[i].t;
        }
    }
    if(!isp[1] && pd[1]!=-1)
        totes+=pd[1];
    printf("%lld\n", totes);
    return 0;
}

