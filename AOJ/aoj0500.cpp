#include <cstdio>

int main()
{
	int n;
	while(scanf("%d\n", &n), n){
		int scr_a = 0, scr_b = 0;
		for(int i = 0; i < n; i++){
			int cur_scr_a, cur_scr_b;
			scanf("%d %d\n", &cur_scr_a, &cur_scr_b); 
			if(cur_scr_a == cur_scr_b){
				scr_a += cur_scr_a;
				scr_b += cur_scr_b;
			}else if(cur_scr_a > cur_scr_b){
				scr_a += cur_scr_a + cur_scr_b;
			}else{
				scr_b += cur_scr_a + cur_scr_b;
			}
		}
		printf("%d %d\n", scr_a, scr_b);
	}
	return 0;

}
