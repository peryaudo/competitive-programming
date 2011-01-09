#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef struct {int x, y;} p;
char m[8][9];
inline bool valid(int n){return 0 <= n && n < 8;}
inline void addqueue(queue<p>& q, int x, int y){
	if(valid(x) && valid(y))
		if(m[y][x] == '1'){
			m[y][x] = '0';
			p u = {x, y};
			q.push(u);
		}
}

int main()
{
	int n;
	scanf("%d\n\n", &n);
	for(int g = 0; g < n; g++){
		int x, y;
		for(int i = 0; i < 8; i++) scanf("%8s\n", m[i]);
		scanf("%d\n%d\n\n", &x, &y);
		queue<p> q;
		p t = {x - 1, y - 1};
		q.push(t);
		while(!q.empty()){
			t = q.front(); q.pop();
			for(int i = -3; i <= 3; i++) addqueue(q, t.x, t.y + i);
			for(int i = -3; i <= 3; i++) addqueue(q, t.x + i, t.y);
		}
		printf("Data %d:\n", g + 1);
		for(int i = 0; i < 8; i++) printf("%s\n", m[i]);
	}
	return 0;
}
