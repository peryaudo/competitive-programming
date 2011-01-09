#include <cstdio>

int main(){
	int a, b;
	char hoge[256];
	while(scanf("%d %d\n", &a, &b) != EOF)
		printf("%d\n", sprintf(hoge, "%d", a+b));
	return 0;
}
