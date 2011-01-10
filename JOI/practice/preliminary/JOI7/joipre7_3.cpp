#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while(scanf("%d\n", &n), n){
		vector<int> tcards(n), hcards;
		for(int i = 0; i < n; i++)
			scanf("%d\n", &tcards[i]);
		sort(tcards.begin(), tcards.end());
		for(int i = 1, p = 0; i <= 2*n; i++){
			if(p < tcards.size()){
				if(tcards[p] == i){
					p++;
				}else{
					hcards.push_back(i);
				}
			}else{
				hcards.push_back(i);
			}
		}

		int ba = 0;
		int turn = 0;
		while(!tcards.empty() && !hcards.empty()){
			if(turn == 0){/* taro */
				int put = 0;
				for(int i = 0; i < tcards.size(); i++){
					if(tcards[i] > ba){
						ba = tcards[i];
						tcards.erase(remove(tcards.begin(), tcards.end(), ba), tcards.end());
						put = 1;
						break;
					}
				}
				if(!put) ba = 0;
				turn = 1;
			}else{
				int put = 0;
				for(int i = 0; i < hcards.size(); i++){
					if(hcards[i] > ba){
						ba = hcards[i];
						hcards.erase(remove(hcards.begin(), hcards.end(), ba), hcards.end());
						put = 1;
						break;
					}
				}
				if(!put) ba = 0;
				turn = 0;
			}
		}
		int tscore = hcards.size(), hscore = tcards.size();
		printf("%d\n%d\n", tscore, hscore);
	}
	return 0;
}
