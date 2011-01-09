#include <cstdio>
int main(){
	int t,n;
	scanf("%d\n",&n);
	for(t=100000;n;n--){
		t+=t/20;
		if(t%1000)t+=1000-t%1000;
	}
	printf("%d\n",t);
}
