#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

#define ll long long

using namespace std;

void split(string &input, pair<double, double> &p) {
	istringstream s(input);

	string first, second;
	getline(s, first, '|');
	getline(s, second);

	p.first=stod(first);
	p.second=stod(second);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	pair<double, double> p;
	vector<pair<double, double>> g;

	double first, last;
	cin >> first;

	string input;
	while(cin >> input){
		if(input.find('|')!=string::npos){
			split(input, p);
			g.push_back(p);
		}
		else{
			last=stod(input);
			break;
		}
	}

	double r=first/g[0].first;
	for(int i=0;i+1<g.size();i++){
		double mul=g[i].second/g[i+1].first;
		r*=mul;
	}

	long double ans=r*g[g.size()-1].second/last;
	cout << fixed;
	cout << floor(ans*100) << '\n';
	return 0;
}
