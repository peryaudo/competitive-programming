#include <cstdio>
int count(int x){
	int coins = 0;
	while(x >= 500) coins++, x -= 500;
	while(x >= 100) coins++, x -= 100;
	while(x >= 50) coins++, x -= 50;
	while(x >= 10) coins++, x -= 10;
	while(x >= 5) coins++, x -= 5;
	while(x >= 1) coins++, x -= 1;
	return coins;
}
int main()
{
	int n;
	while(scanf("%d\n", &n), n){
		printf("%d\n", count(1000 - n));
	}
	return 0;
}
