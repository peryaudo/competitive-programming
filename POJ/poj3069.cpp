#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int R, n;
	while(scanf("%d %d\n", &R, &n), ~R && ~n){
		vector<int> v;
		for(int i = 0, x; i < n; i++){
			scanf("%d", &x);
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		int j = 0, c = 0;
		while(j < v.size()){
			int l = v[j++];
			while(j < v.size() && v[j] <= l + R) j++;
			l = v[j - 1];
			while(j < v.size() && v[j] <= l + R) j++;
			c++;
		}
		printf("%d\n", c);
	}
	return 0;

}
