#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int maxim;

class ThePhantomMenace
{
    public: int find(vector<int> doors, vector<int> droids)
    {
        droids.push_back(-10000);
        sort(doors.begin(), doors.end());
        sort(droids.begin(), droids.end());
        for(int i=0, j=0; i<doors.size(); i++)
        {
            while(j+1<droids.size() && droids[j+1]<=doors[i])
                j++;
            if(j+1<droids.size())
                maxim=max(maxim, min(doors[i]-droids[j], droids[j+1]-doors[i]));
            else
                maxim=max(maxim, doors[i]-droids[j]);
        }
        return maxim;
    }
};

