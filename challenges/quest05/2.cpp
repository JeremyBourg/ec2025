#include <iostream>
#include <sstream>
#include <vector>

#define ll long long

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

ll solve(string &input){
	vector<int> v;
	vector<Segment> s;
	stringstream r;

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
		r << seg.val;
	}

	return stoll(r.str());
}

int main() {
	string input;
	ll worst=0, best=0;

	while(cin >> input){
		ll v=solve(input);
		if(worst>v || !worst)
			worst=v;
		if(best<v || !best)
			best=v;
	}

	cout << best-worst << '\n';

	return 0;
}
