#include <cstdio>
#include <cstring>

int main(){
	while(1){
		int n, m;
		int cnt = 0;

		scanf("%d\n%d\n", &n, &m);
		if(n == 0) break;

		char *s = new char[m + 1];
		scanf("%s\n", s);

		int plen = n * 2 + 1;
		for(int i = 0; i < m - plen; i++){
			cnt++;
			for(int j = 0; j < plen; j++){
				if(s[i + j] != (j % 2 ? 'I': 'O')){
					cnt--;
					break;
				}
			}
		}

		printf("%d\n", cnt);

		delete s;
	}

	return 0;
}
