// Wrong Answer
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
inline int iabs(int x){
	return x < 0 ? -x : x;
}
int main()
{
	int n;
	scanf("%d\n", &n);
	char cs[n];
	scanf("%s\n", cs);

	vector<int> v;
	v.push_back(1);
	int offset = 0;
	for(int i = 0; i < n - 1; i++){
		if(cs[i] == 'L'){
			const int t = v.back() - 1;
			if(t <= 0) offset = max(offset, -t + 1);
			v.push_back(t);
		}else if(cs[i] == 'R'){
			v.push_back(v.back() + 1);
		}else if(cs[i] == '='){
			v.push_back(v.back());
		}
	}
	for(int i = 0; i < v.size(); i++)
		v[i] += offset;
	for(int i = 0; i < v.size(); i++){
		printf("%d%c", v[i], i == v.size() - 1 ? '\n' : ' ');
	}

	return 0;
}
