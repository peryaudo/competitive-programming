#include <cstdio>
int main()
{
	/* Consider len as length of numbers, x as first number of the sequence, 
	1/2 * len * (x + (x + len - 1)) = N
	len * (2x + len - 1) = 2N
	2x + len - 1 = 2N / len
	2x = 2N / len - len + 1
	x = (N / len) + (1 - len) / 2
	*/
	
	int N;
	while(scanf("%d\n", &N), N){
		int cnt = 0;
		for(int len = 1; len < N; len++){
			if(!(N % len) && !((1 - len) % 2)){
				int x = (N / len) + (1 - len) / 2;
				if(x > 0) cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
