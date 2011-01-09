#include <cstdio>
#include <string>
#include <map>
using namespace std;
int main()
{
	char s[3];
	map<string, int> m;
	while(~scanf("%*d,%2s", s))
		m[string(s)]++;
	printf("%d\n%d\n%d\n%d\n", m["A"], m["B"], m["AB"], m["O"]);
		
	return 0;
}
