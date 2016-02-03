#include <cstdio>

using namespace std;

const int MAXN=100;

int totes;
char inp[MAXN+5], o[5]={'S', 'O', 'S'};

int main()
{
    scanf("%s", inp);
    for(int i=0; inp[i]; i++)
        totes+=inp[i]!=o[i%3];
    printf("%d\n", totes);
}
