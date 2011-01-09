#include <cstdio>
#include <map>
using namespace std;
int main()
{
	int n;
	while(scanf("%d\n", &n), n){
		map<char, char> m;
		char a, b;
		for(int i = 0; i < n; i++){
			scanf("%c %c\n", &a, &b);
			m[a] = b;
		}
		scanf("%d\n", &n);
		for(int i = 0; i < n; i++){
			scanf("%c\n", &a);
			putchar(m[a] ? m[a] : a);
		}
		putchar('\n');
	}
	return 0;
}
