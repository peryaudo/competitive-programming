#include <cstdio>

int main()
{
	int n;
	while(scanf("%d\n", &n), n){
		int f = 1;
		for(int i = 0; i < n; i++){
			int p, q, r;
			scanf("%d %d %d\n", &p, &q, &r);
			if(1000000 <= q * r){
				printf("%d\n", p);
				f = 0;
			}
		}
		if(f) puts("NA");
	}
	return 0;
}
