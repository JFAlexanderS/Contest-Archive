#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

struct inf
{
    int t, mi, ma, i;
} inp;

struct pri
{
    int n, d, t;
}n, np;

struct vinf
{
    int d, t;
};

struct hp2
{
    bool operator () (pri i, pri j)
    {
        if(i.d==j.d)
        {
            return i.t<j.t;
        }
        else
            return i.d>j.d;
    }
};

int nodes, edges, optim, f, sof, l, r, m;
vector<inf> nlist[1055];
int olist[555];
vinf vis[1055];
priority_queue<pri, vector<pri>, hp2> viser;

bool tester(int far)
{
    //cout<<far<<endl;
    //Try the tying situation. That may help.
    for(int i=1; i<=nodes; i++)
        vis[i].d=-1, vis[i].t=-1;
    np.n=1;
    np.d=0;
    np.t=1;
    vis[np.n].d=0;
    vis[np.n].t=1;
    viser.push(np);
    while (!viser.empty())
    {
        n=viser.top();
        viser.pop();
        if(vis[n.n].d<n.d || vis[n.n].t!=n.t)
            continue;
        if(n.t==-1)
        {
            for(int i=0; i<nlist[n.n].size(); i++)
            {
                if(vis[nlist[n.n][i].t].d==-1 || vis[nlist[n.n][i].t].d>n.d+nlist[n.n][i].ma)
                {
                    vis[nlist[n.n][i].t].d=n.d+nlist[n.n][i].ma;
                    vis[nlist[n.n][i].t].t=-1;
                    np.n=nlist[n.n][i].t;
                    np.d=n.d+nlist[n.n][i].ma;
                    np.t=-1;
                    viser.push(np);
                }
            }
        }
        else if(n.t==0)
        {
            for(int i=0; i<nlist[n.n].size(); i++)
            {
                if(vis[nlist[n.n][i].t].d==-1 || vis[nlist[n.n][i].t].d>=n.d+nlist[n.n][i].mi)
                {
                    vis[nlist[n.n][i].t].d=n.d+nlist[n.n][i].mi;
                    vis[nlist[n.n][i].t].t=0;
                    np.n=nlist[n.n][i].t;
                    np.d=n.d+nlist[n.n][i].mi;
                    np.t=0;
                    viser.push(np);
                }
            }
        }
        else
        {
            for(int i=0; i<nlist[n.n].size(); i++)
            {
                if(n.t>far)
                {
                    //cout<<n.n<<"1"<<nlist[n.n][i].t<<endl;
                    if(vis[nlist[n.n][i].t].d==-1 || vis[nlist[n.n][i].t].d>=n.d+nlist[n.n][i].mi)
                    {
                        vis[nlist[n.n][i].t].d=n.d+nlist[n.n][i].mi;
                        vis[nlist[n.n][i].t].t=0;
                        np.n=nlist[n.n][i].t;
                        np.d=n.d+nlist[n.n][i].mi;
                        np.t=0;
                        viser.push(np);
                    }
                }
                else if(nlist[n.n][i].i==olist[n.t])
                {
                    //cout<<n.n<<"2"<<nlist[n.n][i].t<<endl;
                    if(vis[nlist[n.n][i].t].d==-1 || vis[nlist[n.n][i].t].d>=n.d+nlist[n.n][i].mi)
                    {
                        vis[nlist[n.n][i].t].d=n.d+nlist[n.n][i].mi;
                        vis[nlist[n.n][i].t].t=n.t+1;
                        np.n=nlist[n.n][i].t;
                        np.d=n.d+nlist[n.n][i].mi;
                        np.t=n.t+1;
                        viser.push(np);
                    }
                }
                else
                {
                    //cout<<n.n<<"3"<<nlist[n.n][i].t<<endl;
                    if(vis[nlist[n.n][i].t].d==-1 || vis[nlist[n.n][i].t].d>n.d+nlist[n.n][i].ma)
                    {
                        vis[nlist[n.n][i].t].d=n.d+nlist[n.n][i].ma;
                        vis[nlist[n.n][i].t].t=-1;
                        np.n=nlist[n.n][i].t;
                        np.d=n.d+nlist[n.n][i].ma;
                        np.t=-1;
                        viser.push(np);
                    }
                }
            }
        }
    }
    //0 means short, -1 long, and anything positive means part of the olist
    /*for(int i=1; i<=nodes; i++)
    {
        cout<<i<<" "<<vis[i].d<<" "<<vis[i].t<<endl;
    }*/
    if(vis[2].t==0 || vis[2].t==far+1)
        return true;
    return  false;
}

int main()
{
    scanf("%d%d%d", &nodes, &edges, &optim);
    for(int i=1; i<=edges; i++)
    {
        scanf("%d%d%d%d", &f, &inp.t, &inp.mi, &inp.ma);
        inp.i=i;
        nlist[f].push_back(inp);
    }
    for(int i=1; i<=optim; i++)
        scanf("%d", &olist[i]);
    //Can probably remove this
    l=0;
    r=optim;
    while(l<=r)
    {
        m=(l+r)/2;
        if(tester(m))
        {
            l=m+1;
            sof=m;
        }
        else
            r=m-1;
    }
    if(sof==optim)
        printf("Karel Obscuro le gustan los grafos\n");
    else
        printf("%d\n", olist[sof+1]);
    return 0;
}
/*
 4 5 3
 1 2 100 1000
 1 2 500 1000
 2 2 1 1
 1 2 1000 5000
 1 2 1000 1000
 2 3 3
*/
