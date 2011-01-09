#include <iostream>

using namespace std;
int main(){
	while(1){
		double n;
		cin>>n;
		if(n == 0) break;
		for(int i = 1; ; i++){
			n -= (double)1 / (double)(i + 1);
			if(n <= 0){
				cout<<i<<" card(s)\n";
				break;
			}
		}
	}
	return 0;
}
