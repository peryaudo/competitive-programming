// WA
#include <cstdio>
#include <cstring>
int main()
{
	int n, m;
	scanf("%d %d\n", &n, &m);
	int start = 1, end = n;
	for(int i = 0, t; i < m; i++){
		char lr[10];
		scanf("To the %s of %d\n", lr, &t);
		if(!strcmp(lr, "left")){
			if(start <= (t - 1) && (t - 1) <= end){
				end = t - 1;
			}
		}else if(!strcmp(lr, "right")){
			if(start <= (t + 1) && (t + 1) <= end){
				end = t + 1;
			}
		}else{
			printf("that's odd. tell me how it happend.\n");
		}
	}
	printf("%d\n", end - start + 1);
	return 0;
}
