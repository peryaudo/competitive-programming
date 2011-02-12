// Wrong Answer
#include <cstdio>
#include <vector>
using namespace std;

inline bool valid(int x, int y, int w, int h){
	return 0 <= x && x < w && 0 <= y && y < h;
}
int dfs(int x, int y, int vec, int rem, vector<vector<char> > v)
{
	int dst = 0;
	const char tbl[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	if(v[x][y] == 2 && rem){
		for(int i = 0; i < 4; i++){
			const int nx = x + tbl[i][0], ny = y + tbl[i][1];
			if(valid(nx, ny, v.size(), v[0].size())){
				dst += dfs(nx, ny, i, rem, v);
			}
		}
	}else if(v[x][y] == 2 && !rem){
		for(int i = 0; i < v.size(); i++){
			for(int j = 0; j < v[i].size(); j++){ printf("%d ", v[i][j]); }
			puts("");
		} puts("");
		dst += 1;
	}else if(v[x][y] == 1){
		v[x][y] = 3;
		for(int i = 0; i < 4; i++){
			const int nx = x + tbl[i][0], ny = y + tbl[i][1];
			if(valid(nx, ny, v.size(), v[0].size())){
				if((rem - 1 == 0 || v[nx][ny] != 2) &&
					v[nx][ny] != 3){
					dst += dfs(nx, ny, i, rem - 1, v);
				}
			}
		}
	}else if(v[x][y] == 0){
		const int nx = x + tbl[vec][0], ny = y + tbl[vec][1];
		if(valid(nx, ny, v.size(), v[0].size())){
			if((rem == 0 || v[nx][ny] != 2) &&
				v[nx][ny] != 3){
				dst += dfs(nx, ny, vec, rem, v);
			}
		}
	}

	return dst;
}
int main()
{
	int m, n;
	while(scanf("%d %d\n", &m, &n), m || n){
		vector<vector<char> > v(n, vector<char>(m));
		int cx, cy, ho = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0, t; j < m; j++){
				scanf("%d", &t);
				if(t == 2){
					cx = i, cy = j;
				}else if(t == 1){
					ho++;
				}
				v[i][j] = (char)t;
			}
		}
		printf("%d\n", dfs(cx, cy, 0, ho, v));
	}
	return 0;
}
