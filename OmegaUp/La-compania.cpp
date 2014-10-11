//https://omegaup.com/arena/problem/La-compania#

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int employees, minemp, head, l, m, r, totes=1000000000, sup;
int eval[100005];

vector<int> nlist[100005];

bool hp(int i, int j)
{
    return eval[i]>eval[j];
}

void fire(int m, int n)
{
    eval[n]=1;
    for(int i=0; i<nlist[n].size(); i++)
        fire(m, nlist[n][i]);
    sort(nlist[n].begin(), nlist[n].end(), hp);
    for(int i=0, f=1; i<nlist[n].size(); i++, f++)
    {
        if(f<=m)
        {
            eval[n]+=eval[nlist[n][i]];
        }
    }
}

int main()
{
    scanf("%d%d", &employees, &minemp);
    head=1;
    for(int i=2; i<=employees; i++)
    {
        scanf("%d", &sup);
        if(i!=sup)
            nlist[sup].push_back(i);
    }
    l=0;
    r=employees;
    while(l<=r)
    {
        m=(l+r)/2;
        fire(m, head);
        if(eval[head]>=minemp)
        {
            r=m-1;
            if(m<totes)
                totes=m;
        }
        else
            l=m+1;
    }
    printf("%d\n", totes);
    return 0;
}
