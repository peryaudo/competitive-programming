#include <cstdio>
#include <vector>
using namespace std;

int a, b;
vector<vector<char> > v;

int dfs(int x, int y){
	int _x = x + 1, _y = y + 1, m = 0;
	if(_x < a && y < b){
		if(v[_x][y] == 0) m += dfs(_x, y);
	}
	if(x < a && _y < b){
		if(v[x][_y] == 0) m += dfs(x, _y);
	}
	if(x == a - 1 && y == b - 1){
		m += 1;
	}
	return m;
}

int main()
{
	while(scanf("%d %d\n", &a, &b), a && b){
		int n;
		scanf("%d\n", &n);
		v  = vector<vector<char> >(a, vector<char>(b, 0));
		for(int i = 0; i < n; i++){
			int x, y;
			scanf("%d %d\n", &x, &y);
			v[x - 1][y - 1] = 1;
		}

		printf("%d\n", dfs(0, 0));
	}
	return 0;
}
