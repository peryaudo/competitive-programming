#include <cstdio>

int main()
{
	int a, b, e = 1;
	while(scanf("%d %d\n", &a, &b), a || b){
		int f = 1;
		if(!e) puts("");
		for(int i = a; i <= b; i++)
			if((!(i % 4) && (i % 100)) || !(i % 400)){
				printf("%d\n", i);
				f = 0;
			}
		if(f) puts("NA");
		e = 0;
	}
	return 0;
}
