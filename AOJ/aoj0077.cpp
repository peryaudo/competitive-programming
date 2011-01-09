#include <cstdio>
#include <cstring>

int main()
{
	char s[101];
	while(fgets(s, 101, stdin)){
		for(int i = 0, l = strlen(s); i < l; i++){
			if(s[i] == '@'){
				for(int j = 0; j < s[i + 1] - '0'; j++) putchar(s[i + 2]);
				i += 2;
			}else{
				putchar(s[i]);
			}
		}
	}
	return 0;
}
