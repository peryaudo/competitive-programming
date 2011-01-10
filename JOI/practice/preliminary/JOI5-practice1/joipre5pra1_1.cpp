#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int x = 0, y = 0, z = 0;
	vector<int> t(3);
	while(~scanf("%d %d %d\n", &t[0], &t[1], &t[2])){
		sort(t.begin(), t.end());
		if((t[1] + t[0]) > t[2]){
			if(t[2] * t[2] < t[0] * t[0] + t[1] * t[1]){
				x++;
			}else if((t[2] * t[2]) == (t[0] * t[0] + t[1] * t[1])){
				y++;
			}else if(t[2] * t[2] > t[0] * t[0] + t[1] * t[1]){
				z++;
			}
		}else{
			break;
		}
	}
	printf("%d %d %d %d\n", x + y + z, y, x, z);
	return 0;
}
