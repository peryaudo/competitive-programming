#include <cstdio>

int main(){
	char m[12][12];
	char fgr[7][4][4] = {
		{{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
		{{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
		{{1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
		{{0, 1, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}},
		{{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
		{{1, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}},
		{{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}};
	for(int i = 0; i < 144; i++) m[i/12][i%12] = 0;


	while(~scanf("%8s\n%8s\n%8s\n%8s\n%8s\n%8s\n%8s\n%8s\n\n",
		m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7])){
		int x = -1, y = -1;
		for(int i = 0; i < 64; i++) m[i/8][i%8] -= 48;
		for(int i = 0; i < 8; i++)
			for(int j = 0; j < 8; j++)
				if(m[i][j]){
					if(x == -1) x = j;
					if(y == -1) y = i;
					if(x != -1 && j < x) x = j;
				}
		for(int h = 0, f, i, j; h < 7; h++){
			for(i = 0, f = 1; i < 4; i++)
			for(j = 0; j < 4; j++)
				if(fgr[h][i][j] != m[i + y][j + x]) f = 0;
			
			if(f){
				printf("%c\n", 'A' + h);
				break;
			}
		}

	}
	return 0;
}
