#include <cstdio>
inline int isprime(int n){
	for(int i = 2; i <=  n / 2; i++){
		if(!(n % i)) return 0;
	}
	return 1;
}
int main()
{
	int n;
	while(~scanf("%d\n", &n)){
		for(int i = n - 1; 0 <= i; i--){
			if(isprime(i)){
				printf("%d ", i);
				break;
			}
		}
		for(int i = n + 1; ; i++)
			if(isprime(i)){
				printf("%d\n", i);
				break;
			}
	}
	return 0;
}
