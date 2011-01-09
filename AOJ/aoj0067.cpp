#include <cstdio>
char m[14][14];
int fillaround(int x, int y){
	if(!m[x][y]) return 0; else m[x][y] = 0;
	if(m[x - 1][y + 0]) fillaround(x - 1, y + 0);
	if(m[x + 1][y + 0]) fillaround(x + 1, y + 0);
	if(m[x - 0][y - 1]) fillaround(x - 0, y - 1);
	if(m[x + 0][y + 1]) fillaround(x + 0, y + 1);
	return 1;
}
int main()
{
	while(~scanf("%12s\n%12s\n%12s\n%12s\n%12s\n%12s\n%12s\n%12s\n%12s\n%12s\n%12s\n%12s\n\n",
		&m[1][1], &m[2][1], &m[3][1], &m[4][1], &m[5][1], &m[6][1],
		&m[7][1], &m[8][1], &m[9][1], &m[10][1], &m[11][1], &m[12][1])){
		int cnt = 0;
		for(int i = 0; i < 14; i++) m[0][i] = '0';
		for(int i = 0; i < 14; i++) m[13][i] = '0';
		for(int i = 1; i < 13; i++) m[i][0] = '0', m[i][13] = '0';
		for(int i = 0; i < 14; i++)
			for(int j = 0; j < 14; j++)
				m[i][j] -= '0';
		for(int i = 1; i < 13; i++)
			for(int j = 1; j < 13; j++)
				cnt += fillaround(i, j);
		printf("%d\n", cnt);
	}
	return 0;
}
