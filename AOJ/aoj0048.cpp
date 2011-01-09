#include <cstdio>

int main()
{
	float n;
	int m;
	const char *rank[] = {"light fly", "fly", "bantam", "feather", "light", "light welter",
		"welter", "light middle", "middle", "light heavy", "heavy"};
	while(~scanf("%f\n", &n)){
		if(n <= 48.0) m = 0;
		else if(n <= 51.0) m = 1;
		else if(n <= 54.0) m = 2;
		else if(n <= 57.0) m = 3;
		else if(n <= 60.0) m = 4;
		else if(n <= 64.0) m = 5;
		else if(n <= 69.0) m = 6;
		else if(n <= 75.0) m = 7;
		else if(n <= 81.0) m = 8;
		else if(n <= 91.0) m = 9;
		else m = 10;
		puts(rank[m]);
	}
	return 0;
}

