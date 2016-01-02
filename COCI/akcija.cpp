#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXB=100000;

long long books, totes;
long long bList[MAXB+5];

int main()
{
    scanf("%lld", &books);
    for(int i=1; i<=books; i++)
        scanf("%lld", &bList[i]);
    sort(bList+1, bList+1+books, greater<int>());
    for(int i=1; i<=books; i+=3)
        totes+=bList[i]+bList[i+1];
    printf("%lld\n", totes);
}
