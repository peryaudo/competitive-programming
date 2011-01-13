/* Not solved */
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
class px {
public:
	px(void){this->x = 0; this->y = 0;return;}
	px(int x, int y){this->x = x;this->y = y;return;}
	int x, y;
	const bool operator<(px to) const{
		make_pair(x, y) < make_pair(to.x, to.y);
	}
	static inline int ipow(int x){
		return x * x;
	}
	inline int square(const px& to) const {
		return ipow(this->x - to.x) + ipow(this->y - to.y);
	}
};
int inline iabs(int x){
	return x < 0 ? -x: x;
}
int main()
{
	int n;
	while(scanf("%d\n", &n), n){
		set<px> se;
		for(int i = 0; i < n; i++){
			px t;
			scanf("%d %d\n", &(t.x), &(t.y));
			se.insert(t);
		}
		vector<px> v;
		for(set<px>::iterator it = se.begin(); it != se.end(); it++)
			v.push_back(*it);
		
		int biggest = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j) continue;
				const px A = v[i], B = v[j];
				const int b = iabs(A.x - B.x), a = iabs(A.y - B.y);
				const px C(B.x + a, B.y - b), D(A.x + a, A.x - b),
				      E(B.x - a, B.y + b), F(A.x - a, A.x + b);
				
				printf("+");
				if((se.find(C) != se.end() & se.find(D) != se.end()) ||
						(se.find(E) != se.end() & se.find(F) != se.end())){
					biggest = max(biggest, A.square(B));
				}
			}
		}
		printf("%d\n", biggest);
		return 0;
	}
	return 0;
}
