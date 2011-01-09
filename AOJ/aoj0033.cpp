#include <cstdio>
#include <list>
using namespace std;
int main(){
	int n;
	scanf("%d\n", &n);

	for(int i = 0, tmp; i < n; i++){
		list<int> a, b, c;
		for(int j = 0; j < 10; a.push_back(tmp), j++)
			scanf("%d", &tmp);
		while(!a.empty()){
			if(a.front() > b.back() || b.empty()){
				b.push_back(a.front());
				a.pop_front();
			}else if(a.front() > c.back() || c.empty()){
				c.push_back(a.front());
				a.pop_front();
			}else{
				break;
			}
		}
		puts(a.empty()?"YES":"NO");
	}
	return 0;
}
