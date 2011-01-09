#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	char s[9];
	scanf("%d\n", &n);
	for(int i = 0; i < n; i++){
		int max, min;
		vector<int> v;
		scanf("%8s", s);
		for(int j = 0; j < 8; j++) v.push_back(s[j] - '0');
		sort(v.begin(), v.end());
		for(int j = 0; j < 8; j++) s[j] = v[j] + '0';
		min = atoi(s);
		for(int j = 0; j < 8; j++) s[j] = v[7 - j] + '0';
		max = atoi(s);
		printf("%d\n", max - min);
	}
	return 0;
}


