#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=5000;
const long long MOD=1000000007;

int digits;
long long dp[MAXN+5][MAXN+5], decide[MAXN+5][MAXN+5];
char inp[MAXN+5];

bool comp(int i2, int j2, int i1, int j1)
{
    if(i1<0)
        return true;
    if(decide[i1][i2]>j1-i1)
        return false;
    return inp[i1+decide[i1][i2]]<inp[i2+decide[i1][i2]];
}

long long dec(int i, int j)
{
    if(decide[i][j])
        return decide[i][j];
    else if(i>digits || j>digits)
        decide[i][j]=MOD;
    else if(inp[i]!=inp[j])
        decide[i][j]=0;
    else
        decide[i][j]=min(dec(i+1, j+1)+1, MOD);
    return decide[i][j];
}

int main()
{
    scanf("%d", &digits);
    scanf("%s", inp+1);
    for(int i=1; i<=digits; i++)
        dp[0][i]=1;
    for(int i=1; i<=digits; i++)
        for(int j=i+1; j<=digits; j++)
            dec(i, j);

    for(int i=1; i<=digits; i++)
        for(int j=1; j<=digits; j++)
        {
            if(j<=i && inp[i-j+1]!='0')
            {
                if(comp(i-j+1, i, i-2*j+1, i-j))
                    dp[i][j]=(dp[i][j-1]+dp[i-j][j])%MOD;
                else
                    dp[i][j]=(dp[i][j-1]+dp[i-j][j-1])%MOD;
            }
            else
                dp[i][j]=dp[i][j-1];
        }

    cout<<dp[digits][digits]<<endl;
}
