//https://omegaup.com/arena/problem/Solid-Nieves-y-las-aranas

#include <cstdio>

int ans[45][45];

int main()
{

ans[1][1]=1;
ans[1][2]=1;
ans[1][3]=1;
ans[1][4]=2;
ans[1][5]=2;
ans[1][6]=2;
ans[1][7]=3;
ans[1][8]=3;
ans[1][9]=3;
ans[1][10]=4;
ans[1][11]=4;
ans[1][12]=4;
ans[1][13]=5;
ans[1][14]=5;
ans[1][15]=5;
ans[1][16]=6;
ans[1][17]=6;
ans[1][18]=6;
ans[1][19]=7;
ans[1][20]=7;
ans[1][21]=7;
ans[1][22]=8;
ans[1][23]=8;
ans[1][24]=8;
ans[1][25]=9;
ans[1][26]=9;
ans[1][27]=9;
ans[1][28]=10;
ans[1][29]=10;
ans[1][30]=10;
ans[1][31]=11;
ans[1][32]=11;
ans[1][33]=11;
ans[1][34]=12;
ans[1][35]=12;
ans[1][36]=12;
ans[1][37]=13;
ans[1][38]=13;
ans[1][39]=13;
ans[1][40]=14;
ans[2][1]=1;
ans[2][2]=2;
ans[2][3]=2;
ans[2][4]=3;
ans[2][5]=3;
ans[2][6]=4;
ans[2][7]=4;
ans[2][8]=5;
ans[2][9]=5;
ans[2][10]=6;
ans[2][11]=6;
ans[2][12]=7;
ans[2][13]=7;
ans[2][14]=8;
ans[2][15]=8;
ans[2][16]=9;
ans[2][17]=9;
ans[2][18]=10;
ans[2][19]=10;
ans[2][20]=11;
ans[3][1]=1;
ans[3][2]=2;
ans[3][3]=3;
ans[3][4]=4;
ans[3][5]=4;
ans[3][6]=5;
ans[3][7]=6;
ans[3][8]=7;
ans[3][9]=7;
ans[3][10]=8;
ans[3][11]=9;
ans[3][12]=10;
ans[3][13]=10;
ans[4][1]=2;
ans[4][2]=3;
ans[4][3]=4;
ans[4][4]=4;
ans[4][5]=6;
ans[4][6]=7;
ans[4][7]=7;
ans[4][8]=8;
ans[4][9]=10;
ans[4][10]=10;
ans[5][1]=2;
ans[5][2]=3;
ans[5][3]=4;
ans[5][4]=6;
ans[5][5]=7;
ans[5][6]=8;
ans[5][7]=9;
ans[5][8]=11;
ans[6][1]=2;
ans[6][2]=4;
ans[6][3]=5;
ans[6][4]=7;
ans[6][5]=8;
ans[6][6]=10;
ans[7][1]=3;
ans[7][2]=4;
ans[7][3]=6;
ans[7][4]=7;
ans[7][5]=9;
ans[8][1]=3;
ans[8][2]=5;
ans[8][3]=7;
ans[8][4]=8;
ans[8][5]=11;
ans[9][1]=3;
ans[9][2]=5;
ans[9][3]=7;
ans[9][4]=10;
ans[10][1]=4;
ans[10][2]=6;
ans[10][3]=8;
ans[10][4]=10;
ans[11][1]=4;
ans[11][2]=6;
ans[11][3]=9;
ans[12][1]=4;
ans[12][2]=7;
ans[12][3]=10;
ans[13][1]=5;
ans[13][2]=7;
ans[13][3]=10;
ans[14][1]=5;
ans[14][2]=8;
ans[15][1]=5;
ans[15][2]=8;
ans[16][1]=6;
ans[16][2]=9;
ans[17][1]=6;
ans[17][2]=9;
ans[18][1]=6;
ans[18][2]=10;
ans[19][1]=7;
ans[19][2]=10;
ans[20][1]=7;
ans[20][2]=11;
ans[21][1]=7;
ans[22][1]=8;
ans[23][1]=8;
ans[24][1]=8;
ans[25][1]=9;
ans[26][1]=9;
ans[27][1]=9;
ans[28][1]=10;
ans[29][1]=10;
ans[30][1]=10;
ans[31][1]=11;
ans[32][1]=11;
ans[33][1]=11;
ans[34][1]=12;
ans[35][1]=12;
ans[36][1]=12;
ans[37][1]=13;
ans[38][1]=13;
ans[39][1]=13;
ans[40][1]=14;

int n, m;

scanf("%d%d", &n, &m);
printf("%d\n", (n*m)-ans[n][m]);

return 0;

}
