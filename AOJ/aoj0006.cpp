#include <cstdio>
#include <cstring>

int main(){
	char hoge[21];
	fgets(hoge, 21, stdin);
	for(int i = 0, l = strlen(hoge) - 1; i < l + 1; i++)
		putc(hoge[l - i], stdout);
	puts("");
	
	return 0;
}
