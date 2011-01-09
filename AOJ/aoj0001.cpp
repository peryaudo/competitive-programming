#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
	vector<int> m(10);
	for(int i = 0; i < 10; i++)
		scanf("%d\n", &m[i]);
	sort(m.begin(), m.end());
	for(int i = 0; i < 3; i++)
		printf("%d\n", m[9-i]);
	return 0;
}
