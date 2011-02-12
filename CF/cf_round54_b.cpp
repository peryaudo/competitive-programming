#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int n;
	scanf("%d\n", &n);
	vector<int> v;
	while(1){
		v.push_back(n);
		if(n <= 1) break;
		for(int i = n - 1; 0 < i; i--){
			if(!(n % i)){
				n = i;
				break;
			}
		}
	}
	for(int i = 0; i < v.size(); i++){
		printf("%d%c", v[i], i == v.size() - 1 ? '\n' : ' ');
	}
	return 0;
}
