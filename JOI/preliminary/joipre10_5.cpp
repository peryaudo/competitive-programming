#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
inline bool validate(int x, int y, int H, int W){
	return 0 <= x && x < H && 0 <= y && y < W;
}
int main()
{
	int H, W, N;
	cin>>H>>W>>N;
	vector<string> v(H);
	for(int i = 0; i < H; i++)
		cin>>v[i];
	int sx = 0, sy = 0;
	for(int i = 0, f = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			if(v[i][j] == 'S'){
				f = 1;
				sx = i; sy = j;
				break;
			}
		}
		if(f) break;
	}

	int cheese = N;
	int dst = 0;
	int life = 1;
	while(cheese > 0){
		vector<vector<int> > w(H, vector<int>(W, INT_MAX));
		queue<pair<int, int> > q;
		q.push(make_pair(sx, sy));
		w[sx][sy] = 0;
		while(!q.empty()){
			const int tbl[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
			pair<int, int> p = q.front(); q.pop();
			const int x = p.first, y = p.second;
			if('1' <= v[x][y] && v[x][y] <= '9'){
				if(life >= (v[x][y] - '0')){
					life++;
					cheese--;
					v[x][y] = '.';
					if(life < 10 || cheese <= 0){
						sx = x, sy = y;
						dst += w[x][y];
						break;
					}
				}
			}
			for(int i = 0; i < 4; i++){
				int nx = x + tbl[i][0], ny = y + tbl[i][1];
				if(validate(nx, ny, H, W)){
					if(v[nx][ny] != 'X' && w[nx][ny] == INT_MAX){
						q.push(make_pair(nx, ny));
						w[nx][ny] = w[x][y] + 1;
					}
				}
			}
		}
	}
	cout<<dst<<endl;

	return 0;
}
