#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	while(cin>>n>>m, n || m){
		vector<pair<string, int> > v;
		for(int i = 0; i < n; i++){
			string _N, N; int M;
			cin>>_N>>M;
			int pos = 0;
			if((pos = _N.rfind('*')) != string::npos){
				N = _N.substr(pos + 1);
			}else{
				N = _N;
			}
			v.push_back(make_pair(N, M));
		}
		long long dst = 0;
		for(int i = 0; i < m; i++){
			string s;
			cin>>s;
			for(int j = 0; j < v.size(); j++){
				if(s.find(v[j].first, s.size() - v[j].first.size())
						!= string::npos){
					dst += v[j].second;
					break;
				}
			}
			
		}
		cout<<dst<<endl;
	}
	return 0;
}
