#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	vector<int> v(5);
	for(int i = 0; i < 5; i++)
		scanf("%d", &v[i]);
	sort(v.rbegin(), v.rend());
	for(int i = 0; i < 5; i++)
		printf("%d%c", v[i], i-4?' ':'\n');
	return 0;
}

