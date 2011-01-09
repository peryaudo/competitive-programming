#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool inline validate(int x, int y, vector<string>& v){
	return (0 <= x) && (x < v.size()) && (0 <= y) && (y < v[0].size());
}
int dfs(int x, int y, vector<string>& v){
	if(v[x][y] == '.') return 0;
	v[x][y] = '.';
	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++){
			if(validate(i + x, j + y, v) && (!(i == 0 && j == 0))){
				dfs(i + x, j + y, v);
			}
		}
	}
	return 1;
}
int main()
{
	int N, M;
	cin>>N>>M;
	vector<string> v;
	for(int i = 0; i < N; i++){
		string s;
		cin>>s;
		v.push_back(s);
	}

	int cnt = 0;
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v[0].size(); j++){
			cnt += dfs(i, j, v);
		}
	}
	cout<<cnt<<endl;

	return 0;
}
