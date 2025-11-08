#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

struct Segment {
	int val, l=0, r=0;
};

struct Sword {
	vector<Segment> sword;
	int id;
	ll rating;
};

void split(string &input, vector<int> &v){
	istringstream s(input);

	string t;
	while(getline(s, t, ',')){
		v.push_back(stoi(t));
	}
}

vector<Segment> get_sword(string &input){
	vector<int> v;
	vector<Segment> sword;

	input=input.substr(input.find(':')+1);
	split(input, v);

	for(int i=0;i<v.size();i++){
		bool found=false;
		for(Segment &seg : sword){
			if(v[i]<seg.val && !seg.l){
				seg.l=v[i];
				found=true;
				break;
			}
			else if(v[i]>seg.val && !seg.r){
				seg.r=v[i];
				found=true;
				break;
			}
		}
		if(!found){
			Segment t;
			t.val=v[i];
			sword.push_back(t);
		}
	}

	return sword;
}

bool cmp(Sword a, Sword b){
	if(a.rating==b.rating){
		for(int i=0; i<a.sword.size();i++){
			stringstream ss_a, ss_b;
			ss_a << a.sword[i].l << a.sword[i].val << (a.sword[i].r ? to_string(a.sword[i].r) : "");
			ss_b << b.sword[i].l << b.sword[i].val << (b.sword[i].r ? to_string(b.sword[i].r) : "");

			int lvl_a=stoi(ss_a.str());
			int lvl_b=stoi(ss_b.str());
			if(!(lvl_a==lvl_b))
				return lvl_a>lvl_b;
		}
		return a.id>b.id;
	}
	return a.rating>b.rating;
}

int main() {
	string input;
	vector<Sword> swords;

	while(cin >> input){
		Sword s;
		s.id=stoi(input.substr(0, input.find(':')));
		s.sword=get_sword(input);

		stringstream ss;
		for(Segment seg : s.sword){
			ss << seg.val;
		}
		s.rating=stoll(ss.str());

		swords.push_back(s);
	}

	ll ans;
	sort(swords.begin(), swords.end(), cmp);

	ll t=0;
	for(int i=0;i<swords.size();i++){
		t+=swords[i].id*(i+1);
	}

	cout << t << '\n';

	return 0;
}
