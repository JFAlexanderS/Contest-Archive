#include <cstdio>

using namespace std;

const int MAXN=1000;

char inp[MAXN+5], vised[MAXN+5][25];
int totes[MAXN+5];

int toInt(char a, char b)
{
    return (a-'0')*10+(b-'0');
}

int main()
{
    scanf("%s", inp);
    for(int i=0; inp[i]; i+=3)
    {
        if(vised[inp[i]][toInt(inp[i+1], inp[i+2])])
        {
            printf("GRESKA\n");
            return 0;
        }
        else
            totes[inp[i]]++;
        vised[inp[i]][toInt(inp[i+1], inp[i+2])]=1;
    }
    printf("%d %d %d %d\n", 13-totes['P'], 13-totes['K'], 13-totes['H'], 13-totes['T']);
}
