#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	long long n;
	while(cin>>n, n){
		long long m;
		string s;
		cin>>m>>s;
		n = 2 * n + 1;
		vector<long long> v;
		int len = 0;
		bool is_seq = 0;
		char expect = 0;
		for(long long i = 0; i < m; i++){
			if(is_seq){
				if(s[i] == expect){
					expect = (expect == 'I' ? 'O' : 'I');
					len++;
				}else{
					is_seq = 0;
					if(len >= n){
						if(!(len % 2)) len--;
						v.push_back(len);
					}
				}
			}
			if(!is_seq && s[i] == 'I'){
				is_seq = 1;
				expect = 'O';
				len = 1;
			}
		}
		if(len >= n) v.push_back(len);
		long long dst = 0;
		for(int i = 0; i < v.size(); i++){
			dst += 1 + ((v[i] - n) / 2);
		}
		cout<<dst<<endl;
	}
	return 0;
}
