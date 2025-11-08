#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Segment {
	int val;
	bool lt, rt;
};

void split(string &input, vector<int> &v){
	istringstream s(input);

	string t;
	while(getline(s, t, ',')){
		v.push_back(stoi(t));
	}
}

int main() {
	vector<int> v;
	vector<Segment> s;
	string input;
	cin >> input;

	int id=stoi(input.substr(0, input.find(':')));
	input=input.substr(input.find(':')+1);
	split(input, v);

	for(int i=0;i<v.size();i++){
		bool found=false;
		for(Segment &seg : s){
			if(v[i]<seg.val && !seg.lt){
				seg.lt=true;
				found=true;
				break;
			}
			else if(v[i]>seg.val && !seg.rt){
				seg.rt=true;
				found=true;
				break;
			}
		}
		if(!found){
			Segment t;
			t.val=v[i];
			s.push_back(t);
		}
	}

	for(Segment seg : s){
		cout << seg.val;
	}
	cout << '\n';

	return 0;
}
