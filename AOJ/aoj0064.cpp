#include <cstdio>

int main(){
	int n = 0, sum = 0;
	char c;
	while(c = getchar(), ~c){
		if('0' <= c && c <= '9'){
			n *= 10;n += c - '0';
		}else{
			sum += n;n = 0;
		}
	}
	printf("%d\n", sum);
	return 0;
}
