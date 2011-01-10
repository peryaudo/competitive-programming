#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d\n", &n);
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	for(int i = 1; i <= v[0]; i++){
		bool f = 1;
		for(int j = 0; j < v.size(); j++){
			if(v[j] % i) f = 0;
		}
		if(f) printf("%d\n", i);
	}
	return 0;
}
