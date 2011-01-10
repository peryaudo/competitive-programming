#include <cstdio>
#include <map>
#include <algorithm>
#define X 1
#define Y 2
using namespace std;
int w, h;
class quad_memo {
private:
	map<pair<int, int>, map<pair<int, int>, long long> > m;
public:
	inline bool empty(int a, int b, int c, int d){
		return m[make_pair(a, b)].find(make_pair(c, d)) == m[make_pair(a, b)].end();
	}
	inline long long get(int a, int b, int c, int d){
		return m[make_pair(a, b)][make_pair(c, d)];
	}
	inline long long set(int a, int b, int c, int d, long long e){
		return m[make_pair(a, b)][make_pair(c, d)] = e % 100000;
	}
	inline void clear(){
		m.clear();
		return;
	}
};
quad_memo qm;
long long dfs(int x, int y, int vector, int prev){
	if(!qm.empty(x, y, vector, prev)){
		return qm.get(x, y, vector, prev);
	}

	if(x == w && y == h) return qm.set(x, y, vector, prev, 1);

	long long total = 0;
	
	if(vector == 0){
		if((x + 1) <= w) total += dfs(x + 1, y, X, 0);
		if((y + 1) <= h) total += dfs(x, y + 1, Y, 0);
	}else if(vector == X){
		if((x + 1) <= w) total += dfs(x + 1, y, X, 0);
		if(!prev && ((y + 1) <= h)) total += dfs(x, y + 1, Y, 1);
	}else if(vector == Y){
		if(!prev &&((x + 1) <= w)) total += dfs(x + 1, y, X, 1);
		if((y + 1) <= h) total += dfs(x, y + 1, Y, 0);
	}

	return qm.set(x, y, vector, prev, total);
}
int main()
{
	while(scanf("%d %d\n", &w, &h), w || h){
		w--, h--;
		qm.clear();
		printf("%lld\n", dfs(0, 0, 0, 0) % 100000);
	}
	return 0;
}
