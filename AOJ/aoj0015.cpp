#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
	int N;
	scanf("%d\n", &N);
	for(int i = 0, f = 0; i < N; i++){
		vector<char> v(80, 0), w(80, 0);
		char c[81], d[81];
		scanf("%80s\n%80s\n", c, d);
		for(int j = 0, l = strlen(c); j < l; j++) v[j] = c[l - j - 1] - '0';
		for(int j = 0, l = strlen(d); j < l; j++) w[j] = d[l - j - 1] - '0';
		for(int j = 0; j < 80; j++){
			int t = v[j] + w[j] + f;
			f = t / 10;
			v[j] = t % 10;
		}
		if(f){
			puts("overflow");
		}else{
			int j = 79;
			for(; 0 <= j; j--)
				if(v[j]) break;
			for(; -1 <= j; j--)
				putchar(~j?v[j]+'0':'\n');
		}
	}
	return 0;
}
