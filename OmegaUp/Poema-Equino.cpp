//https://omegaup.com/arena/problem/Poema-Equino

#include <cstdio> 
#include <queue>

using namespace std;

char poem[105], state[7][12][7][12][105];
char key[15][15][5]=
{
	{{'q', 'Q'}, {'w', 'W'}, {'e', 'E'}, {'r', 'R'}, {'t', 'T'}, {'y', 'Y'}, {'u', 'U'}, {'i', 'I'}, {'o', 'O'}, {'p', 'P'}},
	{{'a', 'A'}, {'s', 'S'}, {'d', 'D'}, {'f', 'F'}, {'g', 'G'}, {'h', 'H'}, {'j', 'J'}, {'k', 'K'}, {'l', 'L'}, {';', ':'}},
	{{'z', 'Z'}, {'x', 'X'}, {'c', 'C'}, {'v', 'V'}, {'b', 'B'}, {'n', 'N'}, {'m', 'M'}, {',', '<'}, {'.', '>'}, {'/', '?'}},
	{{'^', '^'}, {'^', '^'}, {' ', ' '}, {' ', ' '}, {' ', ' '}, {' ', ' '}, {' ', ' '}, {' ', ' '}, {'^', '^'}, {'^', '^'}},
};

int len;
int hmovs[15][5]=
{
	{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
};

void dfs(int r1, int c1, int r2, int c2, int l)
{
	if(r1==r2 && c1==c2)
		return;
	//if(l==len-2 && (key[r1][c1][0]=='^' || key[r2][c2][0]=='^'))
	//	printf("%c %c\n", key[r1][c1][0], key[r2][c2][0]);
	if(state[r1][c1][r2][c2][l])
		return;
	state[r1][c1][r2][c2][l]=1;
	if(l==len)
		return;
	for(int i=0; i<8; i++)
	{
		if(r1+hmovs[i][0]<0 || r1+hmovs[i][0]>3 || c1+hmovs[i][1]<0 || c1+hmovs[i][1]>9)
			continue;
		//Still missing shifts!!!
		if(key[r2][c2][1]=='^')
		{
			if(key[r1+hmovs[i][0]][c1+hmovs[i][1]][1]!='^')//More shit here
			{
				if(!state[r1+hmovs[i][0]][c1+hmovs[i][1]][r2][c2][l+1] && key[r1+hmovs[i][0]][c1+hmovs[i][1]][1]==poem[l])
					dfs(r1+hmovs[i][0], c1+hmovs[i][1], r2, c2, l+1);
			}
			else if(!state[r1+hmovs[i][0]][c1+hmovs[i][1]][r2][c2][l])
					dfs(r1+hmovs[i][0], c1+hmovs[i][1], r2, c2, l);
		}
		else
		{
			if(key[r1+hmovs[i][0]][c1+hmovs[i][1]][1]!='^')//More shit here
			{
				if(!state[r1+hmovs[i][0]][c1+hmovs[i][1]][r2][c2][l+1] && key[r1+hmovs[i][0]][c1+hmovs[i][1]][0]==poem[l])
					dfs(r1+hmovs[i][0], c1+hmovs[i][1], r2, c2, l+1);
			}
			else if(!state[r1+hmovs[i][0]][c1+hmovs[i][1]][r2][c2][l])
					dfs(r1+hmovs[i][0], c1+hmovs[i][1], r2, c2, l);
		}	
	}
	for(int i=0; i<8; i++)
	{
		if(r2+hmovs[i][0]<0 || r2+hmovs[i][0]>3 || c2+hmovs[i][1]<0 || c2+hmovs[i][1]>9)
			continue;
		if(key[r1][c1][1]=='^')
		{
			if(key[r2+hmovs[i][0]][c2+hmovs[i][1]][1]!='^')//More shit here
			{
				if(!state[r1][c1][r2+hmovs[i][0]][c2+hmovs[i][1]][l+1] && key[r2+hmovs[i][0]][c2+hmovs[i][1]][1]==poem[l])
					dfs(r1, c1, r2+hmovs[i][0], c2+hmovs[i][1], l+1);
			}
			else if(!state[r1][c1][r2+hmovs[i][0]][c2+hmovs[i][1]][l])
					dfs(r1, c1, r2+hmovs[i][0], c2+hmovs[i][1], l);
		}
		else
		{
			if(key[r2+hmovs[i][0]][c2+hmovs[i][1]][1]!='^')//More shit here
			{
				if(!state[r1][c1][r2+hmovs[i][0]][c2+hmovs[i][1]][l+1] && key[r2+hmovs[i][0]][c2+hmovs[i][1]][0]==poem[l])
					dfs(r1, c1, r2+hmovs[i][0], c2+hmovs[i][1], l+1);
			}
			else if(!state[r1][c1][r2+hmovs[i][0]][c2+hmovs[i][1]][l])
					dfs(r1, c1, r2+hmovs[i][0], c2+hmovs[i][1], l);		
		}					
	}
} 

int main()
{	
	scanf("%[^\n]s", poem);
	for(len=0; poem[len]; len++){}		
	dfs(3, 0, 3, 9, 0);
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<10; j++)
		{
			for(int k=0; k<4; k++)
			{
				for(int l=0; l<10; l++)
				{
					if(state[i][j][k][l][len])
					{
						printf("1\n");
						return 0;
					}
				}
			}
		}
	}
	printf("0\n");	
	return 0;
}
