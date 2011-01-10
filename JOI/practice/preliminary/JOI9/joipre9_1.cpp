#include <cstdio>
int main()
{
	int total;
	while(scanf("%d\n", &total), total){
		int others = 0;
		for(int i = 0; i < 9; i++){
			int t;
			scanf("%d\n", &t);
			others += t;
		}
		printf("%d\n", total - others);
	}
	return 0;
}
