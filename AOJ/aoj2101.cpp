#include <cstdio>
#include <cmath>

using namespace std;
inline void judge(int x){
	int N = x, S = 0;
	if(N != 1) S = 1;
	for(int i = 2, l = sqrt(N); i <= l; i++){
		if(N % i) continue;
		S += i;
		if(N / i != i) S += N / i;
	}
	if(N == S) puts("perfect number");
	if(N > S) puts("deficient number");
	if(N < S) puts("abundant number");
}
int main(){
	while(1){
		int N;
		scanf("%d\n", &N);
		if(!N) break;
		judge(N);
	}
}
