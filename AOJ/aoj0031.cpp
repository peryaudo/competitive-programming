#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int n;
	while(~scanf("%d\n", &n)){
		vector<int> v;
		for(int i = 512; 1 <= i; i /= 2){
			if(n < i) continue;
			n -= i;
			v.push_back(i);
			if(n <= 0) break;
		}
		for(int i = v.size() - 1; 0 <= i; i--)
			printf("%d%c", v[i], i ? ' ' : '\n');
	}
	return 0;
}
