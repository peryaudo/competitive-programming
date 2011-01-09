#include <cstdio>

using namespace std;
inline void judge(int x){
	int N;
	N = x;
	for(int i = 1, l = (x / 2) + 1; i < l; i++){
		if(x % i) continue;
		N -= i;
	}
	if(N == 0) puts("perfect number");
	if(N > 0) puts("deficient number");
	if(N < 0) puts("abundant number");
}
int main(){
	while(1){
		int N;
		scanf("%d\n", &N);
		if(!N) break;
		judge(N);
	}
}
