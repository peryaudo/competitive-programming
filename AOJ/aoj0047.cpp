#include <cstdio>
#define swp(a,b) a ^= b,b ^= a,a ^= b;
int main()
{
	int cups[3] = {1, 0, 0};
	unsigned char a, b;
	while(~scanf("%c,%c\n", &a, &b))
		swp(cups[a - 'A'], cups[b - 'A']);
	printf("%c\n", cups[0] * 'A' + cups[1] * 'B' + cups[2] * 'C');
	return 0;
}

