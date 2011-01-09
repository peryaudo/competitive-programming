#include <cstdio>

int main()
{
	char n;
	while(~(n = getchar()))
		putchar('a' <= n && n <= 'z' ? n - 'a' + 'A' : n);
	return 0;
}
