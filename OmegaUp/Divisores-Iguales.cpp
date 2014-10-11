//https://omegaup.com/arena/problem/Divisores-Iguales

#include <cstdio>
#include <iostream>

using namespace std;

int n, d;
long long totes;
short divs[2000005], recent[2000005];

int main()
{
    cin>>n;
    for(int i=1; i<=1000000; i++)
        divs[i]=1;
    for(int i=2; i<=1000000; i++)
    {
        if(divs[i]!=1)
            continue;
        for(int j=i; j<=1000000; j+=i)
        {
            d=(j/i);
            if(d%i==0)
            {
                recent[j]=recent[d]+1;
                divs[j]*=recent[j];
            }
            else
            {
                recent[j]=2;
                divs[j]*=recent[j];
            }
        }
    }
    for(int i=n-1, j=n+1; i>0 || (j<=4000000 || j<=2*n+n/2); i--, j++)
    {
        if(j<=4000000)
        {
            if(divs[j]==divs[n])
            {
                printf("%d\n", j);
                return 0;
            }
        }
        if(i>0)
        {
            if(divs[i]==divs[n])
            {
                printf("%d\n", i);
                return 0;
            }
        }
    }
    return 0;
}

