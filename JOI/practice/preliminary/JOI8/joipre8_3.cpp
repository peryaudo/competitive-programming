#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
int changecolour(char *c, int N, int pos, int colour){
	char d[N];
	for(int i = 0; i < N; i++)
		d[i] = c [i];
	d[pos] = colour;

	bool changed = true;
	while(changed){
		int last = 0, cnt = 1;
		changed = false;
		for(int i = 0; i <= N; i++){
			if(last == (i != N ? d[i] : 0)){
				cnt++;
			}else{
				if(cnt > 3){
					for(int j = i - cnt; j < N - cnt; j++){
						d[j] = d[j + cnt];
					}
					N -= cnt;
					changed = true;
					break;
				}
				last = d[i];
				cnt = 1;
			}
		}
	}
	return N;
}
inline char shouldchange(int x, char *c, int N){
	// There are following patterns which should  be changed:
	/* x??? */ if((N - x - 1) >= 3) if(c[x + 1] == c[x + 2] && c[x + 1] == c[x + 3]) return c[x + 1];
	/* ?x?? */ if((N - x - 1) >= 2 && (x >= 1)) if(c[x - 1] == c[x + 1] && c[x - 1] == c[x + 2]) return c[x - 1];
	/* ??x? */ if((N - x - 1) >= 1 && (x >= 2)) if(c[x - 2] == c[x - 1] && c[x - 2] == c[x + 1]) return c[x - 2];
	/* ???x */ if(x >= 3) if(c[x - 3] == c[x - 2] && c[x - 3] == c[x - 1]) return c[x - 3];
	return 0;
	
}
int main()
{
	int N;
	while(scanf("%d\n", &N), N){
		int M = N;
		char c[10000];
		for(int i = 0; i < N; i++)
			scanf("%hhd\n", &c[i]);
		if(N > 3){
			for(int i = 0, colour = 0; i < N; i++)
				if((colour = shouldchange(i, c, N)) != 0)
					M = min(M, changecolour(c, N, i, colour));
				
			/*M = min(M, changecolour(c, N, 0, c[1]));
			for(int i = 1; i < (N - 1); i++){
				if(c[i - 1] == c[i + 1]){
					M = min(M, changecolour(c, N, i, c[i - 1]));
				}else{
					M = min(M, changecolour(c, N, i, c[i - 1]));
					M = min(M, changecolour(c, N, i, c[i + 1]));
				}
			}
			M = min(M, changecolour(c, N, N - 1, c[N - 2]));*/
		}
		printf("%d\n", M);
	}
	return 0;
}
