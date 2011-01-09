#include <cstdio>

int main(){
	int m, q;
	while(scanf("%d %d\n", &m, &q)){
		if(!m)break;
		printf("%d\n", (q + ((m<3?12+m:m) + 1) * 13 / 5 + (m<3?3:5) - 35) % 7);
	}
}


