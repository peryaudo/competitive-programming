#include <cstdio>

int main()
{
	int k , _n;
	int r[14];
	for(int i = 0; i < 14; i++) r[i] = 0;

	while(scanf("%d", &k), k){
		if(!r[k]){
			_n = k * 2;
			for(int i = k; ; i++){
				int n = _n, p = 0;
				while(n != k){
					p = (p + i) % n--;
					if(p < k) goto l;
					p %= n;
				}
				r[k] = i + 1;
				break;
l:;
			}
		}
		printf("%d\n", r[k]);
	}
	return 0;
}