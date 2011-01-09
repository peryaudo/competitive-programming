#include <iostream>
#include <string>
using namespace std;
class Dice {
public:
	int top, bottom, west, east, south, north;
	Dice(){
		top = 1;bottom = 6;
		west = 4;east = 3; 
		south = 2;north = 5;
	}
	void North(){
		int tmp = top;
		top = south;
		south = bottom;
		bottom = north;
		north = tmp;
		return;
	}
	void East(){
		int tmp = top;
		top = west;
		west = bottom;
		bottom = east;
		east = tmp;
		return;
	}
	void West(){
		int tmp = top;
		top = east;
		east = bottom;
		bottom = west;
		west = tmp;
		return;
	}
	void South(){
		int tmp = top;
		top = north;
		north = bottom;
		bottom = south;
		south = tmp;
		return;
	}
	void Right(){
		int tmp = south;
		south = east;
		east = north;
		north = west;
		west = tmp;
		return;
	}
	void Left(){
		int tmp = south;
		south = west;
		west = north;
		north = east;
		east = tmp;
		return;
	}
};

int main(){
	int n;
	while(cin>>n, n){
		long long total = 1;
		Dice d;
		for(int i = 0; i < n; i++){
			string s;
			cin>>s;
			if(!s.compare("North"))
				d.North();
			else if(!s.compare("East"))
				d.East();
			else if(!s.compare("West"))
				d.West();
			else if(!s.compare("South"))
				d.South();
			else if(!s.compare("Right"))
				d.Right();
			else if(!s.compare("Left"))
				d.Left();
			total += d.top;
		}
		cout<<total<<endl;
	}
	return 0;
}
