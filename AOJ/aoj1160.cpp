#include <cstdio>
#include <vector>
using namespace std;
void fill(int i, int j, vector<vector<bool> >& v){
	for(int x = -1; x <= 1; x++){
		for(int y = -1; y <= 1; y++){
			if(!x && !y) continue;
			int nx = i + x, ny = j + y;
			if(0 <= nx && nx < v.size() &&
					0 <= ny && ny < v[0].size()){
				if(v[nx][ny]){
					v[nx][ny] = false;
					fill(nx, ny, v);
				}
			}
		}
	}
	return;
}
int main()
{
	int w, h;
	while(scanf("%d %d\n", &w, &h), w || h){
		vector<vector<bool> > v(w, vector<bool>(h, false));
		for(int i = 0; i < h; i++){
			for(int j = 0, c; j < w; j++){
				scanf("%d\n", &c);
				v[j][i] = (bool)c;
			}
		}
		int cnt = 0;
		for(int i = 0; i < w; i++){
			for(int j = 0; j < h; j++){
				if(v[i][j]){
					cnt++;
					v[i][j] = false;
					fill(i, j, v);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
