//http://codeforces.com/contest/60/problem/B

#include <iostream>
#include <cstdio>
using namespace std;
char bowl[12][12][12], inp[15];
int depth, rows, columns, bx, by, totes=0;
void dfs(int x, int y, int z)
{
    bowl[x][y][z]='#';
    totes++;
    if(bowl[x-1][y][z]=='.')
    {
        dfs(x-1, y, z);
    }
    if(bowl[x+1][y][z]=='.')
    {
        dfs(x+1, y, z);
    }
    if(bowl[x][y-1][z]=='.')
    {
        dfs(x, y-1, z);
    }
    if(bowl[x][y+1][z]=='.')
    {
        dfs(x, y+1, z);
    }
    if(bowl[x][y][z-1]=='.')
    {
        dfs(x, y, z-1);
    }
    if(bowl[x][y][z+1]=='.')
    {
        dfs(x, y, z+1);
    }
}
int main()
{
    //depth, rows, columns
    //[x][y][z]
    scanf("%d%d%d", &depth, &rows, &columns);
    for(int d=1; d<=depth; d++)
    {
        for(int r=1; r<=rows; r++)
        {
            scanf("%s", inp);
            for(int c=1; c<=columns; c++)
            {
                bowl[c][r][d]=inp[c-1];
            }
        }
    }
    /*for(int d=1; d<=depth; d++)
    {
        for(int r=1; r<=rows; r++)
        {
            for(int c=1; c<=columns; c++)
            {
                printf("%c", bowl[c][r][d]);
            }
            cout<<endl;
        }
        cout<<endl;
    }*/
    scanf("%d%d", &by, &bx);
    if(bowl[bx][by][1]=='.')
    {
        dfs(bx, by, 1);
    }
    printf("%d\n", totes);
    return 0;
}
