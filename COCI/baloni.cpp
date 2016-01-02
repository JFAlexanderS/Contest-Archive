#include <cstdio>

using namespace std;

const int MAXN=1000000;

int balloons, totes, num;
int last[MAXN+5];

int main()
{
    scanf("%d", &balloons);
    for(int i=1; i<=balloons; i++)
    {
        scanf("%d", &num);
        if(last[num+1])
            last[num+1]--;
        else
            totes++;
        last[num]++;
    }
    printf("%d\n", totes);
}
