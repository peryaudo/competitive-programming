#include <cstdio>

int main()
{
	int ha, ab, bc, ch;
	scanf("%d\n%d\n%d\n%d\n", &ha, &ab, &bc, &ch);
	int total = ha + ab + bc + ch;
	int tsec = total % 60;
	int tmin = (total - tsec) / 60;
	printf("%d\n%d\n", tmin, tsec);
	return 0;
}
