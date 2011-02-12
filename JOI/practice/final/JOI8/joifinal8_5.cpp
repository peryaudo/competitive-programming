#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Rect {
public:
	int x1, y1, x2, y2;
};

class Compressor {
public:
	int w, h;
	vector<Rect> rects;
	Compressor(int& w, int& h, vector<Rect>& rects){
		this->w = w; this->h = h;
		this->rects = rects;
		return;
	}

	static inline bool valid(int x, int w){
		return 0 <= x && x < w;
	}

	map<int, int> make_compress_table(vector<int> v, int cur_width, int& dst_width){
		map<int, int> dst;
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		int cur = 0;
		for(int i = 0; i < v.size(); i++){
			if(valid(v[i] - 1, cur_width)) cur++;
			if(valid(v[i], cur_width))
				dst[v[i]] = ++cur;
			if(valid(v[i] + 1, cur_width)) cur++;
		}
		dst_width = cur + 1;
		return dst;
	}

	void compress(){
		vector<int> x, y;
		for(int i = 0; i < rects.size(); i++){
			x.push_back(rects[i].x1);
			x.push_back(rects[i].x2);
			y.push_back(rects[i].y1);
			y.push_back(rects[i].y2);
		}

		map<int, int> xt = make_compress_table(x, w, w),
			yt = make_compress_table(y, h, h);

		for(int i = 0; i < rects.size(); i++){
			rects[i].x1 = xt[rects[i].x1];
			rects[i].x2 = xt[rects[i].x2];
			rects[i].y1 = yt[rects[i].y1];
			rects[i].y2 = yt[rects[i].y2];
		}
		return;
	}
	vector<vector<bool> > convert(){
		vector<vector<bool> > v(w, vector<bool>(h, false));
		printf("w = %d, h = %d\n", w, h);
		for(int i = 0; i < rects.size(); i++)
			for(int j = rects[i].x1; j < rects[i].x2; j++)
			for(int k = rects[i].y1; k < rects[i].y2; k++){
				v[j][k] = true;
			}

		return v;
	}
};

void dfs(int x, int y, vector<vector<bool> >& v){
	const int tbl[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	v[x][y] = true;
	for(int i = 0; i < 4; i++){
		const int nx = x + tbl[i][0], ny = y + tbl[i][1];
		if(Compressor::valid(nx, v.size()) && Compressor::valid(ny, v[0].size())){
			if(v[nx][ny] == false){
				dfs(nx, ny, v);
			}
		}
	}
	return;
}
int main()
{
	int w, h;
	while(scanf("%d %d\n", &w, &h), w || h){
		int n;
		scanf("%d\n", &n);
		vector<Rect> rects;
		for(int i = 0; i < n; i++){
			Rect re;
			scanf("%d %d %d %d\n", &re.x1, &re.y1, &re.x2, &re.y2);
			//re.x2--, re.y2--;
			rects.push_back(re);
		}

		printf("compressor constructor?\n");
		Compressor comp(w, h, rects);
		printf("compressor?\n");
		comp.compress();
		printf("compressor ok.\n");

		printf("converter?\n");
		vector<vector<bool> > v = comp.convert();
		printf("converter ok\n");
		int res = 0;

		for(int j = 0; j < v[0].size(); j++){
		for(int i = 0; i < v.size(); i++){
				printf(v[i][j] ? "*" : "-");
			}
			puts("");
		}
		for(int i = 0; i < v.size(); i++)
		for(int j = 0; j < v[0].size(); j++){
			if(v[i][j] == false){
				res++;
				dfs(i, j, v);
			}
		}

		printf("%d\n", res);
	}
	return 0;
}
