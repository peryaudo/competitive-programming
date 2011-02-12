#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
inline void collect(int sx, int sy, int dx, int dy, vector<vector<bool> >& v){
	if(sx > dx) swap(sx, dx);
	if(sy > dy) swap(sy, dy);

	if(sx == dx){
		for(int y = sy; y <= dy; y++)
			v[sx][y] = false;
	}else if(sy == dy){
		for(int x = sx; x <= dx; x++)
			v[x][sy] = false;
	}
	return;
}
int main()
{
	int N;
	while(scanf("%d\n", &N), N){
		vector<vector<bool> > v(21, vector<bool>(21, false));
		for(int i = 0, x, y; i < N; i++){
			scanf("%d %d\n", &x, &y);
			v[x][y] = true;
		}
		int M;
		scanf("%d\n", &M);
		int px = 10, py = 10;
		for(int i = 0, l; i < M; i++){
			char d;
			int x = px, y = py;
			scanf("%c %d\n", &d, &l);
			if(d == 'N'){
				y += l;
			}else if(d == 'E'){
				x += l;
			}else if(d == 'S'){
				y -= l;
			}else if(d == 'W'){
				x -= l;
			}
			collect(px, py, x, y, v);
			px = x, py = y;
		}

		int cnt = 0;
		for(int i = 0; i <= 20; i++)
			for(int j = 0; j <= 20; j++)
				if(v[i][j]) cnt++;
		
		puts(cnt ? "No" : "Yes");
	}
	return 0;
}
