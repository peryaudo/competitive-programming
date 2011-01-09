#include <cstdio>

int main(){
	int x, y, sz, max = 0, cnt = 0;
	char si[3][3] = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}},
	     mi[3][3] = {{1,1,1},{1,1,1},{1,1,1}},
	     li[5][5] = {{0, 0, 1, 0, 0}, {0, 1, 1, 1, 0}, {1, 1, 1, 1, 1}, {0, 1, 1, 1, 0}, {0, 0, 1, 0, 0}};
	int m[20][20];
	for(int i = 0; i < 20; i++)
	for(int j = 0; j < 20; j++)
		m[i][j] = 0;
	while(~scanf("%d,%d,%d\n", &x, &y, &sz)){
		for(int i = 0, szi = (sz-- < 3 ? 3 : 5), ofs = (szi - 1) / 2; i < szi; i++)
		for(int j = 0; j < szi; j++)
			m[x+i+5-ofs][y+j+5-ofs] += (sz==1?si[i][j]:sz==2?mi[i][j]:li[i][j]);
	}
	for(int i = 5; i < 15; i++)
	for(int j = 5; j < 15; j++){
		if(!m[i][j]) cnt++;
		if(max < m[i][j]) max = m[i][j];
		
	}
	printf("%d\n%d\n", cnt, max);
	return 0;
}
