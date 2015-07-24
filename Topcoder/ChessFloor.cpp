#include <cstdio>
#include <vector>
#include <string>

using namespace std;

const int MAXN=20;

int totes=1000000;
char tiled[MAXN+5][MAXN+5];

int tile(char c1, char c2, const vector<string> &floor)
{
    tiled[0][0]=c1;
    int mint=tiled[0][0]!=floor[0][0];
    for(int i=0; i<floor.size(); i++)
    {
        for(int j=0+(i==0); j<floor[i].size(); j++)
        {
            if(j)
            {
                if(tiled[i][j-1]==c1)
                    tiled[i][j]=c2;
                else
                    tiled[i][j]=c1;
            }
            else
            {
                if(tiled[i-1][j]==c1)
                    tiled[i][j]=c2;
                else
                    tiled[i][j]=c1;
            }
            mint+=tiled[i][j]!=floor[i][j];
        }
    }
    return mint;
}

class ChessFloor
{
    public: int minimumChanges(vector <string> floor)
    {
        for(char i='a'; i<='z'; i++)
            for(char j='a'; j<='z'; j++)
                if(i!=j)
                    totes=min(totes, tile(i, j, floor));

        return totes;
    }
}
