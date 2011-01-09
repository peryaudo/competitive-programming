#include <cstdio>

int main(){
	char b[10], a[3][3];
	while(~scanf("%9s\n", b)){
		char r = 0;
		for(int i = 0; i < 9; i++)
			a[i%3][i/3] = b[i];
		for(int i = 0, j, f; i < 3; i++){
			if(a[i][0] == 's') continue;
			for(j = 0, f = 1; j < 3; j++)
				if(a[i][0] != a[i][j]) f = 0;
			if(f) r = a[i][0];
		}
		for(int i = 0, j, f; i < 3; i++){
			if(a[0][i] == 's') continue;
			for(j = 0, f = 1; j < 3; j++)
				if(a[0][i] != a[j][i]) f = 0;
			if(f) r = a[0][i];
		}
		if(a[0][0] != 's' && a[0][0] == a[1][1] && a[0][0] == a[2][2]) r = a[0][0];
		if(a[2][0] != 's' && a[2][0] == a[1][1] && a[2][0] == a[0][2]) r = a[2][0];
		printf("%c\n", r?r:'d');
	}
	return 0;
}
